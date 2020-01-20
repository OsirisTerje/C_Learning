#pragma once

#include <stdbool.h>
#include <windows.h>
#include <stdio.h>

#define THREADS 1000

typedef struct {
    int number;
    bool isPrime;
} primecheck;


bool isPrime(primecheck *arg)
{
    int i,n,flag = 1;
    for (i = 2; i <= arg->number / 2; ++i) {
        // condition for non-prime
        if (arg->number % i == 0) {
            flag = 0;
            break;
        }
    }
    arg->isPrime = flag;
    return flag;
}




void allPrimes(int upTo)
{
    primecheck threadArgs[THREADS];
    unsigned int threadIds[THREADS];
    int i;
    for (i = 0; i < upTo; ++i)
    {
        threadArgs[i].number = i;
        threadIds[i] = _beginthread(isPrime, 0, &threadArgs[i]);
    }
    WaitForMultipleObjects(upTo, threadIds, 1,5000);
    printf("Prime numbers:\n");
    for (i = 0; i < upTo; ++i)
    {
        if (threadArgs[i].isPrime)
        {
            printf("%d ",threadArgs[i].number);
        }
    }
    printf("\n");
}