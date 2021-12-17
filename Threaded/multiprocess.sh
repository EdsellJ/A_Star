#!/bin/sh
NUM_PROCS=`cat /proc/cpuinfo | awk '/^processor/{print $3}'| wc -l`
< $@ xargs -d '\n' -P $NUM_PROCS -I {} /bin/bash -c "{}"
