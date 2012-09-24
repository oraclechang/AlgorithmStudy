#ifdef P_9_1_NEW

/*
Problem
	N 개의 계단이 있다. 1, 2, 3칸씩 올라갈 수 있다.
	N 개단을 올라갈 수 있는 방법의 수를 구하라

Solution

*/

#include "Header.h"

void MyCountWay(int nLeftStep, int& nCount)
{

	if (0 == nLeftStep)
	{
		++nCount;
		return;
	}

	if (0 > nLeftStep)
		return;

	MyCountWay(nLeftStep - 1, nCount);
	MyCountWay(nLeftStep - 2, nCount);
	MyCountWay(nLeftStep - 3, nCount);
}

int MyCountWayDP(vector< int >& vResult, int nStep)
{
	vResult[0] = 0;
	vResult[1] = 1;
	vResult[2] = 2;
	vResult[3] = 4;

	if (0 >= nStep)
		return 0;

	if (3 >= nStep)
		return vResult[nStep];

	for (int i = 4; i <= nStep; ++i)
	{
		vResult[i] = vResult[i - 1] + vResult[i - 2] + vResult[i - 3];
	}

	return vResult[nStep];
}


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
	int n = 5;
	cout << "CountWay : " << CountWay(n) << endl;;

	cout << "CoundWayDP : " << CountWayDP(n) << endl;

	int nCount = 0;
	MyCountWay(n, nCount);
	cout << "MyCountWay : " << nCount << endl;

	vector< int > vResult(100, 0);
	int Result = MyCountWayDP(vResult, n);
	cout << "MyCountWayDB : " << Result << endl;
}

#endif
