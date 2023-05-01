
CROSS_COMPILE=aarch64-none-linux-gnu-


all:writer-arm
writer: writer.o
	$(CROSS_COMPILE)gcc -Wall -Werror -c writer.c -o writer.o

writer-arm: writer.o
	$(CROSS_COMPILE)gcc -Wall -Werror writer.o -o writer-arm -static

