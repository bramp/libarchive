#!/bin/sh -e

CFLAGS=$1
LDFLAGS=$2

for p in test-*.c
do
	echo $p
	cc -Wall -g -o $p.out $CFLAGS $p $LDFLAGS -larchive -lz -lbz2
	./$p.out
done
