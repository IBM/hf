include ../Makefile.common

SOURCES = hflog.c\
		  hfenv.c\
		  hfstr.c\
		  hfsocket.c\
		  hfib.c\
		  hfmxm.c\
		  hfcomm.c \
		  hfdemangle.c

build:	build-hfutils\
		build-tests
	@echo

build-hfutils:
	@echo
	@echo -------
	@echo hfutils
	@echo -------
	@echo

	$(CC) $(SOURCES)\
		../extlibs/dl_malloc.o \
		-o libhfutils.so\
		-I$(CUDA_INC) \
		-I../extlibs \
		-shared -fpic\
		-lstdc++ \
		-I/opt/mellanox/mxm/include/ \
		-L/opt/mellanox/mxm/lib -lmxm \
		-lrdmacm -libverbs -L$(CUDA_LIB) -lcudart\
		-D_GNU_SOURCE\
		-std=gnu11 -Wall -Wextra -g

build-tests:
	make -C tests

clean:
	rm -f *.o *.so *.bin	
	make -C tests clean
