
#include "whatever.h"

double anotherValue = 12.0;

double whatever_add(double a, double b)
{
	return a + b;
}

double whatever_add2(double *a, double *b)
{
	return *a + *b;
}

double result;

double* whatever_add3(double* a, double* b)
{
	result = *a + *b;
	return &result;
}

