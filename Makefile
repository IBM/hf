build:
	make  -C extlibs
	make  -C hfio    build
	make  -C hfutils build
	make  -C hfcuda  build
	#make -C hfmem   build
	#make -C apps    build

test:	
	make  -C hfcuda  test

clean:
	make  -C hfutils clean
	make  -C hfcuda  clean
	#make -C hfmem   clean
	#make -C apps    clean

