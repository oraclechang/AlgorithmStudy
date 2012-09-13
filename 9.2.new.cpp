#ifdef P_9_2_NEW

/*
Problem
	X, Y 그리드가 있을 때 
	0, 0 에서 X, Y 좌표로 가는 Path의 개수

Solution

*/

#include "Header.h"
int GetPath(int x, int y, int& nCount)
{
	if (0 == x && 0 == y)
		return ++nCount;
	if (0 < x)
		GetPath(x - 1, y, nCount);
	if (0 < y)
		GetPath(x, y - 1, nCount);
}

void main()
{
	int x = 1;
	int y = 1;
	int nCount = 0;

	cout << GetPath(x, y, nCount) << endl;
}

#endif
