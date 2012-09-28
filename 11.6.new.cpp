#ifdef _11_5_NEW_

/*
Problem
	sorted 2D matrix. find element

Solution

*/

#include "Header.h"

int FindEllRow(vector< vector< int > > vvArr, int l, int u, int nTarget)
{
	if (l > u)
		return -1;

	int m = (l + u) / 2;

	if (nTarget == vvArr[m][0])
		return m;
	else if (nTarget < vvArr[m][0])
		return FindEllRow(vvArr, l, m - 1, nTarget);
	else
	{
		if (m == (vvArr.size() - 1))
			return m;
		else if ( (nTarget < vvArr[m + 1][0]) && (m + 1 <= vvArr.size() - 1) )
			return m;
		else
			return FindEllRow(vvArr, m + 1, u, nTarget);
	}

	return -1;
}

void main()
{
	int arr[][4] = {
		{15, 20, 40, 85},
		{20, 35, 80, 95},
		{30, 55, 95, 105},
		{40, 80, 100, 120}};

	vector< vector< int > > vArr;
	vArr.push_back(vector< int >(&arr[0][0], &arr[0][4]));
	vArr.push_back(vector< int >(&arr[1][0], &arr[1][4]));
	vArr.push_back(vector< int >(&arr[2][0], &arr[2][4]));
	vArr.push_back(vector< int >(&arr[3][0], &arr[3][4]));

	int nRow = FindEllRow(vArr, 0, vArr.size() -1, 30);
	cout << nRow << endl;
}

#endif
