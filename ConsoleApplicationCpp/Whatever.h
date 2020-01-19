#pragma once
 

double whatever_add(double a, double b);

double whatever_add2(double* a, double *b);

double* whatever_add3(double* a, double* b);

double* (*whatever_add4)(double* a, double* b);

typedef double* (*whatever_add5)(double* a, double* b);

whatever_add5 wh_add;


typedef struct {
    int a;
    int b;
} coordinate;
