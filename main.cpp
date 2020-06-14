#include "Chatbot.h"
#include "main.h"

#define NUM_THREADS 7
//typedef int semaphore;
sem_t FLAG;

void *printThread(void *threadid){
	string a,b;
    long tid;
    tid = (long)threadid;
    ofstream quote;
    a = "Thread ";
    b = " is running. \n";
    quote.open("QUOTE.txt");
    if(tid % 2 == 0){
        sem_wait(&FLAG);                //if modulo is 0 then tid is even, hence print quote 1
        quote << tid << " Controlling complexity is the essence of computer programming.\r\n" << endl;
        cout << a << tid << b << endl;
        sem_post(&FLAG);
    }
    else{      
        sem_wait(&FLAG);                  //modulo not 0 then tid is odd hence print quote 2
        quote << tid << " Computer science is no more about computers than astronomy is about telescopes. \r\n" << endl;
        cout << a << tid << b << endl;
        sem_post(&FLAG);
    }
    quote.close();
    pthread_exit(NULL);
}

int main(int argc, char *argv[]){

    // 0 = chatbot #1, 1 = chatbot #2, 3 = 4,  4 = 5, 5 = 6, 6 = 7 
    pthread_t chatbots[NUM_THREADS]; //establishes an array of pthread_t type variables
    sem_init(&FLAG,0,1); //initialize semaphore
    ofstream outfile("QUOTE.txt");

    int processID = fork();
    if (processID == 0){
        cout << "Process ID: " << getpid() << "\r\n" << endl;
        outfile << "Process ID: " << getpid() << "\r\n" << endl;
        outfile.close();
    }

    int tr;
    cout << "Running bot loop" << endl;
    for(long i = 0; i <= sizeof(chatbots); i++){
        tr = pthread_create(&chatbots[i], NULL, printThread, (void *) i);
    }
    cout << "Finished bot loop" << endl;

    pthread_exit(NULL);
    return 0;
}
