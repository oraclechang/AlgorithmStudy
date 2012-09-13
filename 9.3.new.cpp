#ifdef P_9_3_NEW

/*
Problem
	Find magic index. m[i] = i.
	단 m은 distinct int 값으로 정렬된 array

Solution

*/

#include "Header.h"

int FindMagic(vector< int > vArr, int nLow, int nUpper)
{
	if (nLow > nUpper)
		return -1;

	int nMid = (nUpper + nLow) / 2;
	if (nMid == vArr[nMid])
		return nMid;
	else if (nMid < vArr[nMid]) 
		return FindMagic(vArr, nLow, nMid - 1);
	else 
		return FindMagic(vArr, nMid + 1, nUpper);
}


void main()
{
	vector< int > vArr;
	vArr.push_back(-10);	// 0
	vArr.push_back(-5);	// 1
	vArr.push_back(-1);	// 2
	vArr.push_back(1);	// 3
	vArr.push_back(2);	// 4
	vArr.push_back(3);	// 5
	vArr.push_back(5);	// 6
	vArr.push_back(7);	// 7
	vArr.push_back(9);	// 8
	vArr.push_back(12);	// 9

	cout << FindMagic(vArr, 0, vArr.size() - 1) << endl;
}

#endif
