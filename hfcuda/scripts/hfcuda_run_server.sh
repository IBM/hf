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

# Parse parameters
# ------------------------------------------------------------------------------

arg_parse ${*}

# Setup and execute
# ------------------------------------------------------------------------------

for e in $(echo ${env} | tr ":" " "); do
    envar=$(echo ${e} | cut -d "=" -f 1)
    enval=$(echo ${e} | cut -d "=" -f 2)
    export ${envar}=${enval}:${!envar}
done

export LD_LIBRARY_PATH=/opt/ibm/spectrum_mpi/lib:${LD_LIBRARY_PATH}
export LD_LIBRARY_PATH=/shared/opt/cuda/cuda-9.1/lib64:${LD_LIBRARY_PATH}

export HFLOG_LEVEL=${log}
export HFLOG_COLOR=false
export HFCUDA_COMM=${com}
export HFCUDA_APPSO=${aso}
export HFCUDA_PORT=$((10000+${por}))

if   [[ ${nvp} -eq 0 ]]; then
    cmd="taskset -c $((4*${por})) 
        ${hfp}/hfcuda/hfcuda_daemon.bin"
elif [[ ${nvp} -eq 1 ]]; then
    cmd="taskset -c $((4*${por})) 
        /shared/opt/cuda/cuda-9.1/bin/nvprof
        -o ${dir}/job${job}-nvprof-${HOSTNAME}-%p.nvp
        ${hfp}/hfcuda/hfcuda_daemon.bin"
fi

#echo ${cmd}
eval ${cmd}

