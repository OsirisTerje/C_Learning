// ConsoleApplicationCpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <malloc.h>
#include "whatever.h"

double mainValue = 42.0;
extern double anotherValue;

int add(int a, int b)
{
    return a + b;
}




int main()
{
    printf ("Hello World!\n");

    int result = add(3, 4);
    printf("The result of 3 + 4 is %d\n", result);

    double x = mainValue + anotherValue;
    printf("Double result is %.2f\n", x);

    double y = whatever_add(mainValue, anotherValue);
    printf("Double result is %.2f\n", y);

    double z = whatever_add2(&mainValue, &anotherValue);
    printf("Double result is %.2f\n", z);

    double* w = whatever_add3(&mainValue, &anotherValue);
    printf("Double result is %.2f\n", *w);

    whatever_add4 = &whatever_add3;
    double* g = (*whatever_add4)(&mainValue, &anotherValue);
    printf("Double result is %.2f\n", *g);

    wh_add = &whatever_add3;
    double* h = wh_add(&mainValue, &anotherValue);
    printf("Double result is %.2f\n", *h);

    coordinate *coordPtr = malloc(sizeof(coordinate)); // Get memory from heap
    if (coordPtr)
    {
        coordPtr->a = 5;
        coordPtr->b = 6;

        coordinate coord2 = { 3,4 };
        
        printf("coordPtr:  %d   %d  ;  coord: %d   %d\n", coordPtr->a, coordPtr->b, coord2.a, coord2.b);

        coord2 = *coordPtr;

        printf("coordPtr:  %d   %d  ;  coord: %d   %d\n", coordPtr->a, coordPtr->b, coord2.a, coord2.b);
                
        // Free up memory from heap
        free(coordPtr);
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
