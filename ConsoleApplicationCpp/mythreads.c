#include <stdio.h> 
#include <stdlib.h> 
#include <windows.h>  //Header file for sleep(). man 3 sleep for details. 
#include <process.h> 
#include "threading.h"

// A normal C function that is executed as a thread  
// when its name is specified in _beginthread() 
void myThreadFun(void* vargp)
{
    Sleep(1000L);
    printf("Printing from Thread \n");
    return NULL;
}

int threadnr;

typedef unsigned int uint;

int threading()
{
    uint thread_id;
    printf("Before Thread\n");
    thread_id = _beginthread(myThreadFun, 0, NULL);
    
    printf("After Thread\n");
    Sleep(3000L);
    
}


