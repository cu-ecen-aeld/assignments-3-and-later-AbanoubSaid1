

ifeq ($(CROSS_COMPILE), )
	target =  writer
else
	target = writer-arm
endif

all:$(target)

writer: writer.o
	gcc -Wall -Werror -c writer.c -o writer

writer-arm: writer.o
	$(CROSS_COMPILE)gcc -Wall -Werror writer.o -o writer-arm -static

