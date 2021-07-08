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

export LD_LIBRARY_PATH=/opt/ibm/spectrum_mpi/lib:${LD_LIBRARY_PATH}
export LD_LIBRARY_PATH=/shared/opt/cuda/cuda-9.1/lib64:${LD_LIBRARY_PATH}

if [[ ${mpi} -eq 0 ]]; then
    export HFLOG_LEVEL=${log}
    export HFLOG_COLOR=false
    export HFCUDA_COMM=${com}
    export LD_PRELOAD=${hfp}/hfcuda/hfcuda_trapper.so:${LD_PRELOAD}
    export HFCUDA_DEVICES=${dev}
else
    flags="-x LD_LIBRARY_PATH=${hfp}/hfutils:${LD_LIBRARY_PATH}
           -x HFLOG_LEVEL=${log}
           -x HFCUDA_COMM=${com}
           -x LD_PRELOAD=${hfp}/hfcuda/hfcuda_trapper.so:${LD_PRELOAD}
           -x HFCUDA_DEVICES=${dev}
           --hostfile ${dir}/job${job}.hostfile"
    exe=${exe/mpirun/mpirun ${flags}}
fi

echo ${exe} | tr -s " "
${exe}

