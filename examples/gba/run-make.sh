#!/bin/bash  -xue

current_srcfile=${BASH_SOURCE:-$0}
script_dir=$(dirname "${current_srcfile}")

host_localdir=${script_dir}
work_dir=/home/$(basename "${host_localdir}")
container==shumon84/gba

command=make
docker run  \
    -v ${host_localdir}:${work_dir}  \
    -w ${work_dir}   \
    ${container}  ${command}
