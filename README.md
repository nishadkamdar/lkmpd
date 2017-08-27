Modules from "The Linux Kernel Module Programming Guide" by Peter Jay Salzman

Ch-2
Ch-3
Ch-4

To compile the modules, create a makefile and write

obj-m := <module_name>.o

Now, in the terminal, type the following command to compile the module

make -C /usr/src/linux-2.6.32 M=$PWD modules

To clean the files created by the module, type

make -C /usr/src/linux-2.6.32 M=$PWD clean

The path /usr/src/linux-2.6.32 is the kernel source compiled manually.
