#ifdef _RANDOM_

/*
Problem

Solution

*/

#include "Header.h"

int BigRand()
{
	return RAND_MAX * rand() + rand();
}

int RandInt(int l, int u)
{
	return l + rand() % (u - l + 1);
}


void main()
{
}

#endif
