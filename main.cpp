//#include "Chatbot.h"
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

//using namespace std;

int main(int argc, char **argv){
    pid_t pid = getpid();
    printf("pid: %lun", pid);
    return 0;
}

//Create file QUOTE.txt
// Open file, write PID into file, close file.
//Create Semaphore 
