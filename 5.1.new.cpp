#ifdef P_5_1_NEW

/*
Problem
	You are given two 32-bit numbers, N and M, and two bit positions, i and j 
	Write a method to set all bits between i and j in N equal to M 
	(e g , M becomes a substring of N located at i and starting at j) 

	EXAMPLE:
	Input: N = 10000000000, M = 10101, i = 2, j = 6
	Output: N = 10001010100

Solution

*/

#include "Header.h"

int UpdateBit(int n, int m, int i, int j) 
{
	int max = ~0; // All 1¡¯s

	// 1¡¯s through position j, then 0¡¯s
	int left = (max << (j + 1));

	// 1¡¯s after position i
	int right = ((1 << i) - 1); 

	// 1¡¯s, with 0s between i and j
	int mask = left | right; 

	// Clear i through j, then put m in there 
	return (n & mask) | (m << i); 
}

void main()
{
	int n = 9;	// 1001
	int m = 3;	// 11
	int i = 1;
	int j = 2;

	cout << UpdateBit(n, m, i, j);
}

#endif
