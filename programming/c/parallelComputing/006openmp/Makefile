.PHONY: build-critical build-reduction build-sequential critical reduction sequential

default: sequential critical reduction

build-critical:
	gcc critical.c -o critical.out -fopenmp

build-reduction:
	gcc reduction.c -o reduction.out -fopenmp

build-sequential:
	gcc sequential.c -o sequential.out

critical:
	time ./critical.out -p

reduction:
	time ./reduction.out -p

sequential:
	time ./sequential.out -p

