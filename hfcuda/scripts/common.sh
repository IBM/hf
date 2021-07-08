#!/bin/bash

# Define parameters
# ------------------------------------------------------------------------------

dir=""
nod=""
aso=""
exe=""

gpn="6"
hfp="${SDIR}/../.."
log="ERROR"
com="hfib"
mpi=0
env=""
nvp=0
loc=0
lop=0
ifn=1
wtf=0
cli=1
iso=1

por="" # HFCUDA_PORT
dev="" # HFCUDA_DEVICES
job="" # Job ID

# Print usage and exit
# ------------------------------------------------------------------------------

function usage
{
    echo "usage: ${0} required [optional]"
    echo "required:"
    echo "  -d, --dir DIR       output directory"
    echo "  -n, --nod NOD       number of GPU nodes"
    echo "  -s, --aso ASO       path to application shared object"
    echo "  -x, --    EXE       command to execute (including arguments)"
    echo "optional:"
    echo "  -g, --gpn GPN       GPUs per node (default: ${gpn})"
    echo "      --hfp HFP       path to HF folder (default: ${hfp})"
    echo "      --log LOG       logging level (default: ${log})"
    echo "      --com COM       communicator (default: ${com})"
    echo "      --mpi           setup for MPI application"
    echo "      --env           environment to set on daemon"
    echo "      --nvp           run nvprof"
    echo "      --loc           use local GPUs (from client perspective)"
    echo "      --lop           use loopback interface"
    echo "      --sif           smart interfaces"
    echo "      --ifn IFN       number of network interfaces to use"
    echo "      --wtf           wait to finish (job)"
    echo "      --cli CLI       number of client hosts (default: ${cli})"
    exit 1
}

# Parse parameters
# ------------------------------------------------------------------------------

function arg_parse
{
    while ((${#})); do
        if   [[ ${1} == "-h" || ${1} == "--help" ]]; then usage
        elif [[ ${1} == "-d" || ${1} == "--dir"  ]]; then dir=${2}; shift; shift
        elif [[ ${1} == "-n" || ${1} == "--nod"  ]]; then nod=${2}; shift; shift
        elif [[ ${1} == "-s" || ${1} == "--aso"  ]]; then aso=${2}; shift; shift
        elif [[ ${1} == "-g" || ${1} == "--gpn"  ]]; then gpn=${2}; shift; shift
        elif [[                 ${1} == "--hfp"  ]]; then hfp=${2}; shift; shift
        elif [[                 ${1} == "--log"  ]]; then log=${2}; shift; shift
        elif [[                 ${1} == "--com"  ]]; then com=${2}; shift; shift
        elif [[                 ${1} == "--mpi"  ]]; then mpi=1          ; shift
        elif [[                 ${1} == "--env"  ]]; then env=${2}; shift; shift
        elif [[                 ${1} == "--nvp"  ]]; then nvp=1          ; shift
        elif [[                 ${1} == "--loc"  ]]; then loc=1          ; shift
        elif [[                 ${1} == "--lop"  ]]; then lop=1          ; shift
        elif [[                 ${1} == "--ifn"  ]]; then ifn=${2}; shift; shift
        elif [[                 ${1} == "--wtf"  ]]; then wtf=1          ; shift
        elif [[                 ${1} == "--cli"  ]]; then cli=${2}; shift; shift
        elif [[ ${1} == "-x" || ${1} == "--"     ]]; then shift; exe=${*}; break
        elif [[                 ${1} == "--por"  ]]; then por=${2}; shift; shift
        elif [[                 ${1} == "--dev"  ]]; then dev=${2}; shift; shift
        elif [[                 ${1} == "--job"  ]]; then job=${2}; shift; shift
        else
            echo "error: invalid parameter: '${1}'"
            usage
        fi
    done
}

# Check parameters
# ------------------------------------------------------------------------------

function arg_check
{
    local par=${1}
    if [[ -z ${!par} ]]; then
        echo "error: missing parameter: '${par}'"
        usage
    fi
}

# Load module
# ------------------------------------------------------------------------------

function load_module 
{
    local mod=${1}
    source /usr/share/Modules/init/bash
    module load ${mod}
}

