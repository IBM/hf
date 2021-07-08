include ../Makefile.common

CFLAGS = -std=gnu11 -Wall -Wextra -g -Wno-unused-parameter -Wno-missing-braces

build:	build-trapper\
		build-daemon
	@echo

build-trapper:
	@echo
	@echo --------------
	@echo hfcuda/trapper
	@echo --------------
	@echo

	$(CC) hfcuda_trapper.c\
		-o hfcuda_trapper.so\
		-ldl -pthread \
		-I../extlibs \
		-I. \
		-I$(CUDA2_INC) -L$(CUDA2_LIB)\
		-I$(CUDA_INC)  -L$(CUDA_LIB)\
		-lcudart \
		-lstdc++ \
		-I../hfutils -L../hfutils -Wl,-rpath='$$ORIGIN/../hfutils' -lhfutils\
		-I../hfio 	 -L../hfio    -Wl,-rpath='$$ORIGIN/../hfio'    -lhfio\
		-shared -fpic\
		-D_GNU_SOURCE\
		$(CFLAGS)

build-daemon:
	@echo
	@echo -------------
	@echo hfcuda/daemon
	@echo -------------
	@echo

	$(CC) hfcuda_daemon.c\
		-o hfcuda_daemon.bin\
		-ldl -lpthread\
		-I$(CUDA2_INC) -L$(CUDA2_LIB)\
		-I$(CUDA_INC)  -L$(CUDA_LIB)\
		-I../extlibs \
		-lcuda -lcudart -lcublas -lcusparse -lcudnn\
		-I../hfutils -L../hfutils -Wl,-rpath='$$ORIGIN/../hfutils' -lhfutils\
		-I../hfio 	 -L../hfio    -Wl,-rpath='$$ORIGIN/../hfio'    -lhfio\
		-D_GNU_SOURCE\
		$(CFLAGS)

build-tests:
	@echo
	@echo ------------
	@echo hfcuda/tests
	@echo ------------
	@echo

	make -C tests/ build

test:
	make -C tests/ test

clean:
	rm -f *.o *.so *.bin
	
