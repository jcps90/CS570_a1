########################################################
#
# Authors: Juan Pina-Sanz, Mikhail Mineev
# Users: cssc2147, cssc2160
# Class: CS 570, Summer 2020
# Assignment 1
# Filename: Makefile
#
# ######################################################

EXEC = bots
FILES = main.cpp Chatbot.cpp
CC = g++
LFLAGS = -lm -o
CFLAGS = -lm -o

$(EXEC):$(FILES)
	$(CC) -std=c++11 $(FILE) $(LFLAGS) $(EXEC)
clean:
	rm -f *.o $(EXEC)

.PHONY: all bots clean
####################[ EOF: Makefile ]##################

