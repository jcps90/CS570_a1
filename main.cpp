
// Authors: Juan Pina-Sanz, Mikhail Mineev
// Users: cssc2147, cssc2160
// Class: CS 570, Summer 2020
// Assignment 1
// Filename: main.cpp

#include "main.h"

#define NUM_THREADS 6				// Threads go from 0 to 6, so 7 in total

sem_t FLAG;
using namespace std;

void *printThreadEven(void *threadid){		//even thread printer	
    string a,b;					// made strings for ease of printing
    long tid;
    tid = (long)threadid + 1;			//for more conventional naming scheme 1-7 instead of 0-6

    ofstream quote;
    a = "Thread ";				//ease of printing
    b = " is running. \n";
    
    sem_wait(&FLAG);				//waits until previous thread finishes
    quote.open("QUOTE.txt", std::ios_base::app);//opens file to print to
    quote << tid << " Controlling complexity is the essence of computer programming." << "\r\n";	//prints into the file
    cout << a << tid << b << endl;		//prints to console
    quote.close();				//closes file that was writen into
    sem_post(&FLAG);
    pthread_exit(NULL);
}

void *printThreadOdd(void *threadid){		//odd thread printer
    string a,b;					// made strings for ease of printing
    long tid;
    tid = (long)threadid + 1;			//for more conventional naming scheme 1-7 instead of 0-6

    ofstream quote;
    a = "Thread ";				//ease of printing
    b = " is running. \n";

    sem_wait(&FLAG);				//waits until previous thread finishes
    quote.open("QUOTE.txt", std::ios_base::app);//opens file to print to
    quote << tid << " Computer science is no more about computers than astronomy is about telescopes." << "\r\n";	//prints into the file	
    cout << a << tid << b << endl;		//prints to console
    quote.close();				//closes file that was writen into
    sem_post(&FLAG);
    pthread_exit(NULL);
}
int main(int argc, char *argv[]){		//main

    // [0] = chatbot #1, [1] = chatbot #2, [2] = chatbot #3,  [3] = chatbot #4,  [4] = chatbot #5, [5] = chatbot #6, [6] = chatbot #7 
    pthread_t chatbots[NUM_THREADS]; //establishes an array of pthread_t type variables
    
    ofstream outfile("QUOTE.txt");
    cout << "Process ID: " << getpid() << "\n" << endl;	//prints process ID to console 
    outfile << "Process ID: " << getpid() << "\r\n";	//prints precess ID to the QUOTE.txt file
    outfile.close();					//closes file
    
    int tr;
    //cout << "Running bots Now" << endl;	//for testing the run 
    
    sem_init(&FLAG,0,1); //initialize semaphore
    int r;						//outisde loop variable
    long i;						//inside bots variable
    for(r =0; r <= 8; r++){				//outside loop of 8, to allow the seven threads to repeat
        for(i = 0; i <= NUM_THREADS; i++){		//prints seven threads
            if(i % 2 == 0){				//if modulo is 0 then the thread number is odd due the array design
                sleep(3);				//wait 3 seconds because odd
                tr = pthread_create(&chatbots[i], NULL, printThreadOdd, (void*) i);	//creates pthread, that calls printThreadOdd
            }
            else{					//if anything else besides 0, then the thread is even
                sleep(2);				//wait 2 seconds because even
                tr = pthread_create(&chatbots[i], NULL, printThreadEven, (void *) i);	//creates pthread, that calls printThreadEven
            }
            //cout << "i = " << i << endl; //for testing for loop		
        }
        sleep(1);				//wait one secodn bedore continuing the loop
        //cout << "# of runs = " << r << endl; //for testing the outside for loop
        i = 0;					//set i to 0 to allow for more runs
    }

    sem_destroy(&FLAG);
    cout << "Thank You for Talking to us! :) " << endl;		//chatbots being friendly
    return 0;
}//main
