.PHONY: build run all

default: all

COMPILER=mpicc
N=4
FILE=version2.c

build:
	${COMPILER} ${FILE} -o output

run:
	mpirun --host localhost:${N} -n ${N} ./output

all: build run

