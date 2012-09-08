#ifdef P_9_3

/*	
Problem
	Given a sorted array of n integers that has been rotated an unknown number of times, give anO(log n) algorithm that finds an element in the array 
	You may assume that the array was originally sorted in increasing order.

	EXAMPLE:
	Input: find 5 in array (15 16 19 20 25 1 3 4 5 7 10 14)
	Output: 8 (the index of 5 in the array)

Solution 
	We can do this with a modification of binary search

	public static int search(int a[], int l, int u, int x) { 
		while (l <= u) { 
			int m = (l + u) / 2; 
			if (x == a[m]) {
				return m; 
			} else if (a[l] <= a[m]) {
				if (x > a[m]) {
					l = m+1; 
				} else if (x >=a [l]) {
					u = m-1; 
				} else {
					l = m+1;
				}
			} 
			else if (x < a[m]) u = m-1; 
			else if (x <= a[u]) l = m+1; 
			else u = m - 1; 
		}
		return -1; 
	}

	public static int search(int a[], int x) {
		return search(a, 0, a.length - 1, x);
	}
*/

#include <vector>
#include <algorithm>
#include <memory>
#include <iostream>

using namespace std;

int BinarySearch(vector<int>& vArr, int nStart, int nEnd, int nTarget)
{
	while(nStart <= nEnd)
	{
		int nMid = (nEnd + nStart) / 2;

		if (nTarget == vArr[nMid])
			return nMid;
		else if (vArr[nStart] <= vArr[nEnd])
		{
			if (nTarget > vArr[nMid])	nStart = nMid + 1;
			else if (nTarget > vArr[nStart])	nEnd = nMid - 1;
			else	nStart = nMid + 1;
		}
		else if (nTarget < vArr[nMid])	nEnd = nMid - 1;
		else if (nTarget >= vArr[nMid])	nStart = nMid + 1;
		else nEnd = nMid - 1;
	}

	return -1;
}

int main()
{

	int a[] = {15,16,19,20,25,1,3,4,5,7,10,14};
	vector< int > vArr(a, a + (sizeof(a) / sizeof(int)));

	int position = BinarySearch(vArr, 0, (sizeof(a) / sizeof(int)) - 1, 5);

	cout << position;

	return 0;
}

#endif