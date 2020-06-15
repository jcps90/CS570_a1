
Authors: Juan Pina-Sanz, Mikhail Mineev

Users: cssc2147, cssc2160

Class: CS 570, Summer 2020

Assignment 1

Filename: Makefile




File Manifest:  Makefile
                main.cpp
                main.h
                README.md



Compile Instructions
                Call the make command



Operation Instructions
                Run the bots file that was created by the "make" command\



The design we went for is a nested for loop in order to allow the program to run the 7 threads 8 times
furthermore we separated the print/write funsction into two separate ones to account for odd or even hread numbers



While testing we encountered a bug with thread 7 not being printed out on the last run, however we descovered
that this was due to the oute loop reseting before the print function executed. This was fine for the previous loops because the program continued running, but it failed on the last printout because the loop and the program were terminated. This was fixed by adding a wait function on the outer loop. Anotehr bug thatw e discovered was that the "QUOTE.txt" file was not getting a proper printout, instead the printed line was being overwritten by the next one. This was due to the fact that once we opened the file it would reset its pointer to the first line and would overwrite the existing text. We fixed this by adding a function that would remember which line was alreay written. No other bugs have been discovered after that.



This program allowed us to learn semaphores and pthread which allowed us to do the timed print outs much easier than we could have before. Furthermore it enhanced our understanding of printing to a text file.
