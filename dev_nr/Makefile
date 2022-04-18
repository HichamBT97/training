obj-m += dev_nr.o

KDIR = /lib/modules/$(shell uname -r)

all:
	make -C $(KDIR)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
