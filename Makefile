########################################################
#
# Authors: Juan Pina-Sanz, Mikhail Mineev
# Users: cssc2147, cssc2160
# Class: CS 570, Summer 2020
# Assignment 1
# Filename: Makefile
#
#######################################################
EXEC = bots
CC=g++
$(EXEC):
	$(CC) -o $(EXEC) main.cpp -lpthread
	rm -f *.o
clean:
	rm bots
	rm QUOTE.txt
	rm -f *.o core a.out $(EXEC)
####################[ EOF: Makefile ]##################

