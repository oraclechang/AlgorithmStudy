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

void main()
{
	int x = 1;
	int y = 1;
	int nCount = 0;

	cout << GetPath(x, y, nCount) << endl;
}

#endif
