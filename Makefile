# Path must point to your configured & compiled ARM9 Linux Kernel Tree
KDIR ?= /path/to/your/arm9/linux-kernel-source

obj-m += dummy_device.o

default:
	$(MAKE) -C $(KDIR) M=$$PWD ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- modules

clean:
	$(MAKE) -C $(KDIR) M=$$PWD ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- clean
