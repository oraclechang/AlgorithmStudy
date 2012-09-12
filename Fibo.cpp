#ifdef _FIBO

/*
Problem

Solution

*/

#include "Header.h"

int Fibo(int n)
{
	if (0 == n)
		return 0;
	else if (1 == n)
		return 1;
	else
		return Fibo(n - 1) + Fibo(n - 2);
}

int DoFibo_Cache(vector< int >& vArr, int n)
{
	if (vArr.size() == n)
		vArr.push_back(vArr[n - 1] + vArr[n - 2]);

	return vArr[n];
}

int Fibo_Cache(int n)
{
	vector< int > vArr;
	vArr.push_back(0);
	vArr.push_back(1);

	for (int i = 2; i <= n; ++i)
		DoFibo_Cache(vArr, i);

	return vArr[n];
}


void main()
{
	cout << "Fibo : " << Fibo(10) << endl;

	cout << "Fibo_Cache : " << Fibo_Cache(10) << endl;
}

#endif
