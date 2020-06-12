#include "Chatbot.h"
#include <pthread.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <semaphore.h>

using namespace std;
#define num_thread 7
typedef int semaphore;
semaphore FLAG = 1;
int runCount = 8;




void *getID(void *threadid){
	long tid;
	tid = (long) threadid;
	ofstream quote;
	quote.open("Quote.txt");
	quote << "Thread ", tid, "is running";	
}

int main(int argc, char *argv[]){
	pthread_t threads[num_thread];
	long t;
	int run;
	for (run = 0; run<= runCount; run++){
		for(t=0; t<NUM_THREADS; t++){
       			int i=0;
			if (int i<1){
				sem_wait(2);
			}else{
				sem_wait(1);
			}
				
       			rc = pthread_create(&threads[t], NULL, getID, (void *)t);
			i++;
       			if (rc){
          			printf("ERROR; return code from pthread_create() is %d\n", rc);
          			exit(-1);
       			}
    		}			
 	}
}
