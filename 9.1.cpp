#ifdef P_9_1

/*
Problem:
	You are given two sorted arrays, A and B, and A has a large enough buffer at the end to hold B.  
	Write a method to merge B into A in sorted order 

Solution:
	This code is a part of the standard merge-sort code. 
	We merge A and B from the back, by comparing each element

	public static void merge(int[] a, int[] b, int n, int m) {
		int k = m + n - 1; // Index of last location of array b
		int i = n - 1; // Index of last element in array b
		int j = m - 1; // Index of last element in array a

		// Start comparing from the last element and merge a and b
		while (i >= 0 && j >= 0) {
			if (a[i] > b[j]) {
				a[k--] = a[i--];
			} else {
				a[k--] = b[j--];
			}
		}
		while (j >= 0) {
			a[k--] = b[j--];
		}
	}
*/

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void mergeArray(int* pA, int* pB, int nASize, int nBSize)
{
	int nLastIdx	= nASize + nBSize - 1;
	int nIdxA		= nASize - 1;
	int nIdxB		= nBSize - 1;

	while (0 <= nIdxA && 0 <= nIdxB)
	{ 
		if (pA[nIdxA] < pB[nIdxB])
			pA[nLastIdx--] = pB[nIdxB--];
		else
			pA[nLastIdx--] = pA[nIdxA--];
	}

	while (0 <= nIdxB)
		pA[nLastIdx--] = pB[nIdxB--];
}

int main()
{
	int aA[10] = {0, 2, 4, 6, 8};
	int aB[4] = {1, 3, 5, 7};

	mergeArray(aA, aB, 5, 4);

	for (int i = 0; i < 9; ++i)
		printf("%d ", aA[i]);

	return 0;
}

#endif