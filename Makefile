CC=arm-none-linux-gnueabi-gcc
CFLAGS=--static
OUTNAME=-o bltool

#CC86=gcc
#OUTNAME86=-o bltool-86

all:
	$(CC) $(CFLAGS) $(OUTNAME) bltool.c
#	$(CC86) $(OUTNAME86) bltool.c
