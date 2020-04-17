.PHONY: build run all


default: all

arg=1

build:
	gcc -fopenmp sum${arg}.c -o output


run:
	./output

all: build run