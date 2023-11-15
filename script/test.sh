#!/bin/bash
set -eu
TMP_DIR=$(mktemp -d)
trap "rm -rf ${TMP_DIR}" EXIT

LIST=$(ls test)
for l in ${LIST}
do
  FULLPATH=$(pwd)/test/${l}
  MODULE=$(echo ${l} | sed -e 's/\..*//g')
  if [[ $(head -n 1 ${FULLPATH}) =~ "#define IGNORE" ]]; then
    clang++ ${FULLPATH} -std=c++20 -I . -I ./include
    # in/0001.txt
    INPUT_DIR="testcases/${MODULE}/in"
    OUTPUT_DIR="testcases/${MODULE}/out"
    TESTS=$(ls ${INPUT_DIR})
    for t in ${TESTS}
    do
      ./a.out < ${INPUT_DIR}/${t} > ${TMP_DIR}/${t}
      if [ -n "$(diff ${TMP_DIR}/${t} ${OUTPUT_DIR}/${t})" ]; then
        echo "ERROR: ${MODULE} test failed at testcase ${t}"
        break
      fi
    done
    echo "INFO: ${MODULE} test completed"
  fi
done
