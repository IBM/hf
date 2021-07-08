include ../../Makefile.common

TESTS += CUDART_cudaMalloc
TESTS += CUDART_cudaFree
TESTS += CUDART_cudaMemcpy

build:	$(addprefix build-, $(TESTS))	

build-%:
	@./test_build.sh $* $(NVCC)

test:	$(addprefix test-, $(TESTS))

test-%:
	@./test_run.sh $*

clean:
	$(RM) *.o
	$(RM) *.so
	$(RM) *.bin
		

