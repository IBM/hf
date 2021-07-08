include ../../Makefile.common

build:	build-test_hfcomm
	@echo

build-test_hfcomm:
	@echo
	@echo -------------------------
	@echo hfutils/tests/test_hfcomm	
	@echo -------------------------
	@echo

	$(CC) test_hfcomm_client.c\
		-o test_hfcomm_client.bin\
		-I.. -L.. -lhfutils\
		-D_GNU_SOURCE\
		-std=gnu11 -Wall -Wextra

	@echo

	$(CC) test_hfcomm_server.c\
		-o test_hfcomm_server.bin\
		-I.. -L.. -lhfutils\
		-D_GNU_SOURCE\
		-std=gnu11 -Wall -Wextra

clean:
	rm -f *.o *.so *.bin

