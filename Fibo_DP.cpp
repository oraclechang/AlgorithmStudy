#ifdef _FIBO_DP

/*
Problem

Solution

*/

#include "Header.h"

int Fibo_DP(int n)
{
	vector< int > vArr;
	vArr.push_back(0);
	vArr.push_back(1);

	for (int i = 2; i <= n; ++i)
		vArr.push_back(vArr[i - 1] + vArr[i - 2]);

	return vArr[n];
}

void main()
{
	cout << "Fibo_DP : " << Fibo_DP(10) << endl;
}

#endif
