#!/usr/bin/env make

CC ?= cc
CFLAGS ?= -std=c89\
		  -pedantic\
		  -Wall\
		  -Wextra

tests: test.c
	$(CC) $(CFLAGS) -o $@ $^
