#
# Makefile: Makefile to build as4 binary and libqueue.a

CC=gcc
AR=ar
CFLAGS=-Wall

all: as4 libqueue.a

as4: as4.o libqueue.a
	$(CC) $(CFLAGS) -o as4 as4.o libqueue.a

as4.o: as4.c
	$(CC) $(CFLAGS) -c as4.c

libqueue.a: queue.o
	$(AR) -rc libqueue.a queue.o

queue.o: queue.c
	$(CC) $(CFLAGS) -c queue.c

clean:
	rm -f *.o as4 libqueue.a 

run: as4
	./as4 < /home/cshing/public_html/310/Assignment/as4_data.txt
