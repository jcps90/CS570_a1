//#include "Chatbot.h"
#include "main.h"

#define NUM_THREADS 6

sem_t FLAG;
using namespace std;

void *printThreadEven(void *threadid){
	string a,b;
    long tid;
    tid = (long)threadid + 1;

    ofstream quote;
    a = "Thread ";
    b = " is running. \n";
    
    sem_wait(&FLAG);
    quote.open("QUOTE.txt", std::ios_base::app);
    //if modulo is 0 then tid is even, hence print quote 1
    quote << tid << " Controlling complexity is the essence of computer programming." << "\r\n";
    cout << a << tid << b << endl;
    quote.close();
    sem_post(&FLAG);
    pthread_exit(NULL);
}

void *printThreadOdd(void *threadid){
    string a,b;
    long tid;
    tid = (long)threadid + 1;

    ofstream quote;
    a = "Thread ";
    b = " is running. \n";

    sem_wait(&FLAG);
    quote.open("QUOTE.txt", std::ios_base::app);
    //modulo not 0 then tid is odd hence print quote 2
    quote << tid << " Computer science is no more about computers than astronomy is about telescopes." << "\r\n";
    cout << a << tid << b << endl;
    quote.close();
    sem_post(&FLAG);
    pthread_exit(NULL);
}

/*
void *easyPrint(void *threadID){
    string msg = "printing is so easy: ";
    long tID = (long) threadID;
    ofstream openFile;
    sem_wait(&FLAG);
    openFile.open("QUOTE.txt");
    cout << msg << tID << "\n" << endl;
    openFile << msg << tID << "\n" << endl;
    sem_post(&FLAG);
    pthread_exit(0);

}*/

int main(int argc, char *argv[]){

    // [0] = chatbot #1, [1] = chatbot #2, [2] = chatbot #3,  3 = 4,  4 = 5, 5 = 6, 6 = 7 
    pthread_t chatbots[NUM_THREADS]; //establishes an array of pthread_t type variables
    
    ofstream outfile("QUOTE.txt");
    cout << "Process ID: " << getpid() << "\n" << endl;
    outfile << "Process ID: " << getpid() << "\r\n";
    outfile.close();
    //outfile << "Process ID: " << getpid() << "\r\n";
    //outfile.close();
    
    int tr;
    cout << "Running bots Now" << endl;
    /*int i = 3;
    sem_init(&FLAG,0,1);
    tr = pthread_create(&chatbots[i], NULL, printThread, (void *) i);
    pthread_join(chatbots[i],NULL);
    sem_destroy(&FLAG);
    */
    
    sem_init(&FLAG,0,1); //initialize semaphore
    int r;
    long i;
    for(r =0; r <= 8; r++){
        
        for(i = 0; i <= NUM_THREADS; i++){
            if(i % 2 == 0){
                sleep(3);
                tr = pthread_create(&chatbots[i], NULL, printThreadOdd, (void*) i);
            }
            else{
                sleep(2);
                tr = pthread_create(&chatbots[i], NULL, printThreadEven, (void *) i);
            }
            cout << "i = " << i << endl;
        }
        sleep(1);
        cout << "# of runs = " << r << endl;
        i = 0;
    }

    sem_destroy(&FLAG);
    cout << "Thank You for Talking to us! :) " << endl;
    return 0;
}
