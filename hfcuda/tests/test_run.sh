#!/bin/bash

# SETUP
# ----------------------------------------

source test_common.sh

if [ $# -ne 1 ]; then
    echo "[test_run] error: missing arguments"
    echo "usage: $0 test"
    echo "  test: test name"
    exit 1
fi

test=$1

temp_local="$(mktemp)"
temp_client="$(mktemp)"
echo -e "------\nclient\n------" > ${temp_client}
temp_server="$(mktemp)"
echo -e "------\nserver\n------" > ${temp_server}

# RUN LOCAL
# ----------------------------------------

printf "%*s %*s" ${pad0} "RUN LOCAL" ${pad1} ${test}

./${test}.bin &> ${temp_local}

pretty_print $? ${temp_local}

# RUN HFCUDA
# ----------------------------------------

printf "%*s %*s" ${pad0} "RUN HFCUDA" ${pad1} ${test}

export LD_LIBRARY_PATH=../../hfutils/:${LD_LIBRARY_PATH}
export HFLOG_LEVEL=DEBUG
export HFLOG_COLOR=true
export HFCUDA_COMM=hfsocket

export HFCUDA_APPSO=./${test}.so
timeout=60

{ timeout ${timeout}\
  stdbuf -o0 -e0\
  ../hfcuda_daemon.bin; }\
  &>> ${temp_server} &
srv=$!
sleep 1

export HFCUDA_DEVICES=127.0.0.1:0,127.0.0.1:1,127.0.0.1:2
export LD_PRELOAD=../hfcuda_trapper.so

{ timeout ${timeout}\
  ./${test}.bin; }\
  &>> ${temp_client}
ret=$?
unset LD_PRELOAD

kill -SIGINT ${srv} &> /dev/null
while true; do
    kill -0 ${srv} &> /dev/null
    if [ $? -ne 0 ]; then
        break
    fi
done

pretty_print ${ret} ${temp_client} ${temp_server}

# CLEANUP
# ----------------------------------------

rm -f ${temp_local}
rm -f ${temp_client}
rm -f ${temp_server}

