#!/bin/bash  -xue

current_srcfile=${BASH_SOURCE:-$0}
script_dir=$(dirname "${current_srcfile}")

host_localdir=$(readlink -f "${script_dir}")
work_dir=/home/$(basename "${host_localdir}")
container=shumon84/gba

/usr/bin/cp -pv ${script_dir}/../examples/gba/Makefile Makefile

command=make
docker run  \
    -v ${host_localdir}:${work_dir}  \
    -w ${work_dir}   \
    ${container}  ${command}  "$@"
