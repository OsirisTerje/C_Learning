#pragma once
 

double whatever_add(double a, double b);

double whatever_add2(double* a, double *b);

double* whatever_add3(double* a, double* b);

double* (*whatever_add4)(double* a, double* b);

typedef double* (*whatever_add5)(double* a, double* b);   // Creating a new "type", a simplification

whatever_add5 wh_add;

// Creating a structure
typedef struct {
    int a;
    int b;
} coordinate;
