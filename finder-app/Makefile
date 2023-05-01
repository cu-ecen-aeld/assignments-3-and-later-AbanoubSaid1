
ifeq ($(CROSS_COMPILE), )
	target =  writer
else
	target = writer-arm
endif

all:$(target)

writer: writer.o
	gcc -g -Wall -I/ writer.o -o writer
      
	
writer.o: writer.c
	gcc -g -Wall   -c -o writer.o writer.c
      

writer-arm: writer.o
	$(CROSS_COMPILE)gcc -Wall -Werror writer.o -o writer-arm -static

clean:
	rm -f *.o writer *.elf *.map
	