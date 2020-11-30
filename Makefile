
.PHONY: all
all: reftohdr

CFLAGS= -Wall -I../platform/include

reftohdr: main.o
	$(CC) -o $@ $? 

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm reftohdr
	rm *.o
	