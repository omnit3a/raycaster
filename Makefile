CC=gcc
CFLAGS=-I$(HDRDIR) -O2 -lm

HDRDIR=include/

INPUT=*.c
OUTPUT=test

all:
	clear
	$(CC) -o $(OUTPUT) $(INPUT) $(CFLAGS)
