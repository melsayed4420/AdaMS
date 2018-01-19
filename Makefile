CC = gcc
AdaMS: AdaMS.o AdaMS-cg.o AdaMS-vm.o AdaMS-std.o
	$(CC)  AdaMS.o AdaMS-cg.o AdaMS-vm.o AdaMS-std.o -o AdaMS

AdaMS.o: AdaMS.c
	$(CC) -c AdaMS.c

AdaMS-vm.o: AdaMS-vm.c
	$(CC) -c AdaMS-vm.c

AdaMS-cg.o: AdaMS-cg.c
	$(CC) -c AdaMS-cg.c

AdaMS-std.o: AdaMS-std.c
	$(CC) -c AdaMS-std.c
clear:
	rm *.o
