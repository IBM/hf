#!/bin/bash

# SETUP
# ----------------------------------------

source test_common.sh

if [ $# -ne 2 ]; then
    echo "[test_build] error: missing arguments"
    echo "usage: $0 test nvcc"
    echo "  test: test name"
    echo "  nvcc: path to NVIDIA compiler"
    exit 1
fi

test=$1
nvcc=$2

# BUILD BIN
# ----------------------------------------

#echo -n "BUILD BIN  ${test} "
printf "%*s %*s" ${pad0} "BUILD BIN" ${pad1} ${test}

temp_bin=$(mktemp)
${nvcc} ${test}.cu\
        -o ${test}.bin\
        -cudart shared\
        -Xcompiler -Wall,-Wextra,-rdynamic\
        &> "${temp_bin}"

pretty_print $? ${temp_bin}

# BUILD SO
# ----------------------------------------

printf "%*s %*s" ${pad0} "BUILD SO" ${pad1} ${test}

temp_so=$(mktemp)
${nvcc} ${test}.cu\
        -o ${test}.so\
        -cudart shared\
        -Xcompiler -shared,-fpic\
        -Xcompiler -Wall,-Wextra,-rdynamic\
        &> "${temp_so}"

pretty_print $? ${temp_so}

# CLEANUP
# ----------------------------------------

rm -f ${temp_bin}
rm -f ${temp_so}

