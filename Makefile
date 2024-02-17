CFLAGS = -g
CC = gcc

all: test_image

picture.o : picture.c picture.h pixel.h
	$(CC) $(CFLAGS) -c -o $@ $<

pixel.o : pixel.c pixel.h
	$(CC) $(CFLAGS) -c -o $@ $<

test_image.o : test_image.c picture.h
	$(CC) $(CFLAGS) -c -o $@ $<

test_image : test_image.o picture.o pixel.o
	$(CC) $(CFLAGS) -o $@ $^

clean :
	rm -f *.o test_image
