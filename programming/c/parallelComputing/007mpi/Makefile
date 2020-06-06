.PHONY: build run all

default: all

COMPILER=mpicc
N=4

build:
	${COMPILER} main.c -o output

run:
	mpirun --host localhost:${N} -n ${N} ./output

all: build run

