########################################################
#
# Authors: Juan Pina-Sanz, Mikhail Mineev
# Users: cssc2147, cssc2160
# Class: CS 570, Summer 2020
# Assignment 1
# Filename: Makefile
#
# ######################################################
CC=gcc
CFLAGS=-I
DEPS=bots.h
OBJ=main.o bots.o chatbot.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
bots: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
####################[ EOF: Makefile ]##################

