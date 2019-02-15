#!/bin/bash -e
function usage() {
    echo "[USAGE] $0 BIN_DIR TEST_DATA_DIR"
    exit 1
}

NG_CNT=0
OK_CNT=0
function test() {
    local FILE1=$1
    local FILE2=$2
    local ADD_EXP=$3
    local DEL_EXP=$4

    ${LOGDIFF} ${TEST_DATA_DIR}/$1 ${TEST_DATA_DIR}/$2 |
        tail -n +4 > result
    local ADD_ACT=`grep "^+" result | wc -l`
    local DEL_ACT=`grep "^-" result | wc -l`

    if [ ${ADD_EXP} != ${ADD_ACT} ]; then
        printf "X"
        NG_CNT=`expr ${NG_CNT} + 1`
        return
    fi
    if [ ${DEL_EXP} != ${DEL_ACT} ]; then
        printf "X"
        NG_CNT=`expr ${NG_CNT} + 1`
        return
    fi

    printf "."
    OK_CNT=`expr ${OK_CNT} + 1`
}

if [ $# != 2 ]; then
    usage
fi

BIN_DIR=$1
TEST_DATA_DIR=$2

LOGDIFF=${BIN_DIR}/logdiff
if [ ! -x ${LOGDIFF} ]; then
    usage
fi

test ok.log ng.log 0 1


echo ""
echo "Passed: ${OK_CNT}, Failed: ${NG_CNT}"

if [ ${NG_CNT} -gt 0 ]; then
    exit 1
fi
