#ifdef P_9_2_NEW

/*
Problem
	X, Y �׸��尡 ���� �� 
	0, 0 ���� X, Y ��ǥ�� ���� Path�� ����

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

void GetPath2(int x, int y, int& nCount)
{
	if (0 == x && 0 == y)
	{
		++nCount;
		return;
	}

	if (0 > x)
		return;

	if (0 > y)
		return;

	GetPath2(x - 1, y, nCount);
	GetPath2(x, y - 1, nCount);
}

void main()
{
	int x = 4;
	int y = 4;
	int nCount = 0;

	cout << GetPath(x, y, nCount) << endl;

	int nCount2 = 0;
	GetPath(x, y, nCount2);
	cout << nCount2 << endl;
}

#endif
