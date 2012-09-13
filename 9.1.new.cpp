#ifdef P_9_1_NEW

/*
Problem
	N ���� ����� �ִ�. 1, 2, 3ĭ�� �ö� �� �ִ�.
	N ������ �ö� �� �ִ� ����� ���� ���϶�

Solution

*/

#include "Header.h"

int CountWay(int n)
{
	if (0 == n)
		return 1;
	else if (0 > n)
		return 0;
	else
		return CountWay(n - 1) + CountWay(n - 2) + CountWay(n - 3);
}

int DoCountWayDP(vector< int >& vArr, int n)
{
	if (0 == n)
		return 1;
	else if (0 > n)
		return 0;
	else if (-1 < vArr[n])
		return vArr[n];
	else
	{
		vArr[n] = (DoCountWayDP(vArr, n - 1) + DoCountWayDP(vArr, n - 2) + DoCountWayDP(vArr, n - 3));
		return vArr[n];
	}
}

int CountWayDP(int n)
{
	vector< int > vArr(100, -1);

	DoCountWayDP(vArr, n);

	return vArr[n];
}

void main()
{
	int n = 20;
	cout << CountWay(n) << endl;;

	cout << CountWayDP(n) << endl;
}

#endif
