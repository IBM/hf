#!/bin/bash

# Get script's path and load utilities
# ------------------------------------------------------------------------------

SOURCE="${BASH_SOURCE[0]}"
while [ -h "$SOURCE" ]; do
    DIR="$( cd -P "$( dirname "$SOURCE" )" && pwd )"
    SOURCE="$(readlink "$SOURCE")"
    [[ $SOURCE != /* ]] && SOURCE="$DIR/$SOURCE"
done
SDIR="$( cd -P "$( dirname "$SOURCE" )" && pwd )"

source ${SDIR}/common.sh

# Parse and check parameters
# ------------------------------------------------------------------------------

arg_parse ${*}

arg_check "dir"
arg_check "nod"
arg_check "aso"
arg_check "exe"

# Process directory
# ------------------------------------------------------------------------------

mkdir -p ${dir}
dir=$(readlink -f ${dir})

# Process nodes
# ------------------------------------------------------------------------------

if [[ ${loc} -eq 0 ]]; then
    tot=$((${nod} + ${cli}))
else
    tot=$((${nod} + ${cli} - 1))
fi

# Process bsub flags
# ------------------------------------------------------------------------------

flags=""
flags+="-core_isolation ${iso} "

if [[ ${wtf} -eq 1 ]]; then
  flags+="-K "
fi

# Submit job
# ------------------------------------------------------------------------------

bsub ${flags} << EOF

#BSUB -cwd ${PWD}
#BSUB -nnodes ${tot}
#BSUB -o ${dir}/job%J.out
#BSUB -J HFCUDA(${tot})
#BSUB -q excl

# Define job parameters
# ------------------------------------------------------------------------------

job=\${LSB_JOBID}
hosts=(\$(${SDIR}/get_hosts.py))
echo \${hosts[@]}
echo

devs=""

# Run servers
# ------------------------------------------------------------------------------

for h in \$(seq 0 $((${nod}-1))); do
    server_host=\${hosts[\${h}]}

    for g in \$(seq 0 $((${gpn}-1))); do
        if [[ ${lop} -eq 0 ]]; then
            iface=\$((\${g} % ${ifn}))
            server_ip=\$(ssh \${server_host} /sbin/ifconfig ib\${iface} 2>/dev/null |\
                grep 'inet ' | tr -s ' ' | cut -d ' ' -f 3)
        else
            server_ip="127.0.0.1"
        fi

        cmd="cd ${PWD};
            ${SDIR}/hfcuda_run_server.sh --por \${g} --job \${job} ${*}"
        echo ssh \${server_host} "\${cmd}"
        ssh \${server_host} "\${cmd}" &

        devs+="\${server_ip}:\${g},"
    done
done

devs=\${devs::-1}
sleep 60

# Run client
# ------------------------------------------------------------------------------

# Prep hostfile
hostfile=${dir}/job\${job}.hostfile
for h in \$(seq -1 -1 -${cli}); do
  echo "\${hosts[\${h}]} slots=$((44-2*${iso}))" >> \${hostfile}
done

# Run client
client_host=\${hosts[-1]}
cmd="cd ${PWD}; ${SDIR}/hfcuda_run_client.sh --dev \${devs} --job \${job} ${*}"
echo ssh \${client_host} "\${cmd}"
ssh \${client_host} "\${cmd}" &> ${dir}/job\${job}.app

# Stop servers
# ------------------------------------------------------------------------------

for h in \$(seq 0 $((${nod}-1))); do
    server_host=\${hosts[\${h}]}
    ssh \${server_host} "killall hfcuda_daemon.bin" &
done
wait

EOF

