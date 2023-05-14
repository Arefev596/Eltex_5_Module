obj-m += kernelsp.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
	gcc usersp.c -o usersp
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	rm -f usersp
