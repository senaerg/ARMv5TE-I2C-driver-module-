# ARMv5TE-I2C-driver-module-
arm9 archecture i2c driver module genration
#execution and  testing
1. Transfer your newly compiled .dtb file to your board's boot partition/server.
2. Build the module in this project workspace:
   make KDIR=/path/to/your/arm9/linux/source
3. Copy the output binary object (dummy_device.ko) onto your embedded root file 
   system (via SSH, NFS rootfs, or SD Card).
4. Boot the ARM9 system and insert the module dynamically:
   insmod dummy_device.ko
5. Verify the driver instantiation:
   dmesg | tail -n 20
