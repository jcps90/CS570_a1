#include "Chatbot.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;


void *print(void *threadid){
	string a,b;
    long tid;
    tid = (long) threadid;
    ofstream quote;
    a = "Thread ";
    b = " is running. \n";
    quote.open("QUOTE.txt");
    if(tid % 2 == 0){                //if modulo is 0 then tid is even, hence print quote 1
        quote << tid << " Controlling complexity is the essence of computer programming.\r\n";
        cout << a << tid << b;
    }
    else{                            //modulo not 0 then tid is odd hence print quote 2
        quote << tid << " Computer science is no more about computers than astronomy is about telescopes. \r\n";
        cout << a << tid << b;
    }
    quote.close();
}