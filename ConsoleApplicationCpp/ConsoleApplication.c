// ConsoleApplicationCpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "whatever.h"
#include "bounce.h"


double mainValue = 42.0;
extern double anotherValue;

int add(int a, int b)
{
    return a + b;
}

void printeol()
{
    printf("\n");
}


int main()
{
    printf ("Hello World!\n");

    int result = add(3, 4);
    printf("The result of 3 + 4 is %d\n", result);

    double x = mainValue + anotherValue;
    printf("Double result is %.2f\n", x);

    double y = whatever_add(mainValue, anotherValue);   // Using values
    printf("Double result is %.2f\n", y);

    double z = whatever_add2(&mainValue, &anotherValue);  // Using pointers
    printf("Double result is %.2f\n", z);

    double* w = whatever_add3(&mainValue, &anotherValue);  // also returning pointer
    printf("Double result is %.2f\n", *w);

    whatever_add4 = &whatever_add3;
    double* g = (*whatever_add4)(&mainValue, &anotherValue); // Using pointer to a function too
    printf("Double result is %.2f\n", *g);

    wh_add = &whatever_add3;
    double* h = wh_add(&mainValue, &anotherValue);  // Using a typedef simplified pointer to the function
    printf("Double result is %.2f\n", *h);

    coordinate *coordPtr = malloc(sizeof(coordinate)); // Get memory from heap, as a pointer
    if (coordPtr)  // Will be null if it fails allocating memory
    {
        coordPtr->a = 5;  // access to content from a pointer
        coordPtr->b = 6;

        coordinate coord2 = { 3,4 };
        
        printf("coordPtr:  %d   %d  ;  coord: %d   %d\n", coordPtr->a, coordPtr->b, coord2.a, coord2.b);

        coord2 = *coordPtr;  // Copies content of whatever coordPtr points to into coord2

        printf("coordPtr:  %d   %d  ;  coord: %d   %d\n", coordPtr->a, coordPtr->b, coord2.a, coord2.b);
                
        // Free up memory from heap
        free(coordPtr);
    }

    threading();

    // bounceMain();

    allPrimes(100);


    // file handling
    FILE* fw = fopen("output.txt", "w");
    fputs("some nice text", fw);
    fclose(fw);



    FILE* f = fopen("..\\whatever.txt", "r");
    if (f != NULL)
    {
        char buffer[1000];
        while (fgets(buffer, 1000, f))
        {
            printf("%s\n", buffer);
        }
        fclose(f);
    }
   
    // string handling
    char* whatever = "some long string with numbers  34 56 7";
    char* newstring = " 45 67 89";
    int totalLength = strlen(whatever) + strlen(newstring) + 1;
    char* destination = malloc(totalLength);
    if (destination)
    {
        memset(destination, '\0', totalLength);
        strcat(destination, whatever);
        strcat(destination, newstring);
        printf("%s\n", destination);
        printf(destination);
    }
    int len = strlen(whatever);  // length of string
   
    char digits[] = "0123456789";
    char *digitsPtr = &digits[0]; // Use debugger to look at these pointer addresses, they should be equal
    char* firstDigit = strpbrk(whatever, digits);
    
    
    int length = strlen(destination);  // length of string
    char* dest = malloc(length + 1);
    if (dest)
    {
        strcpy(dest, destination);
    }
    
    printeol();
    int numbers[100];
    int n = 0;
    char delim[] = " ";
    char* token = strtok(dest, delim);
    if (strpbrk(token, digits) != NULL)
    {
        int no = atoi(token);
        numbers[n] = no;
        n++;
    }
    while(token)
    { 
        token = strtok(NULL, delim);
        if (token!=NULL && strpbrk(token, digits) != NULL)
        {
            int no = atoi(token);
            numbers[n] = no;
            n++;
        }
    }

    int j;
    for (j = 0; j < n; ++j)
    {
        printf("%d ", numbers[j]);
    }
    printeol();


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
