build:
	g++ hfio.c\
		-o libhfio.so\
		-I$(CUDA_DIR)/include -L$(CUDA_DIR)/lib64\
		-lcuda -lcudart\
		-shared -fPIC -rdynamic
