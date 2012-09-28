#ifdef _11_3_NEW_

/*
Problem

Solution

*/

#include "Header.h"

int RotatedBinarySearch(vector< int > vArr, int l, int u, int nTargetVal)
{
	if (l > u)
		return -1;

	int m = (l + u) / 2;

	if (nTargetVal == vArr[m])
		return m;

	if (vArr[l] < vArr[m])	//왼쪽 정렬상태
	{
		if (vArr[l] <= nTargetVal && nTargetVal <= vArr[m])
			return RotatedBinarySearch(vArr, l, m - 1, nTargetVal);
		else
			return RotatedBinarySearch(vArr, m + 1, u, nTargetVal);
	}
	else if (vArr[l] > vArr[m])	// 오른쪽 정렬상태
	{
		if (vArr[m] <= nTargetVal && nTargetVal <= vArr[u])
			return RotatedBinarySearch(vArr, m + 1, u, nTargetVal);
		else
			return RotatedBinarySearch(vArr, l, m - 1, nTargetVal);
	}
	else if (vArr[l] == vArr[m])
	{
		if (vArr[m] != vArr[u])
			return RotatedBinarySearch(vArr, m + 1, u, nTargetVal);
		else
		{
			int nResult = RotatedBinarySearch(vArr, l, m - 1, nTargetVal);
			if (-1 == nResult)
				return RotatedBinarySearch(vArr, m + 1, u, nTargetVal);
			else
				return nResult;
		}
	}

	return -1; 
}

void main()
{
	vector< int > vArr1;
	vector< int > vArr2;
	vector< int > vArr3;

	vArr1.push_back( 10 );
	vArr1.push_back( 15 );
	vArr1.push_back( 20 );
	vArr1.push_back( 0 );
	vArr1.push_back( 5 );

	vArr2.push_back( 50 );
	vArr2.push_back( 5 );
	vArr2.push_back( 20 );
	vArr2.push_back( 30 );
	vArr2.push_back( 40 );

	vArr3.push_back( 2 );
	vArr3.push_back( 2 );
	vArr3.push_back( 2 );
	vArr3.push_back( 3 );
	vArr3.push_back( 4 );
	vArr3.push_back( 2 );

	cout << RotatedBinarySearch(vArr1, 0, vArr1.size() - 1, 0) << endl;

	cout << RotatedBinarySearch(vArr2, 0, vArr2.size() - 1, 5) << endl;

	cout << RotatedBinarySearch(vArr3, 0, vArr3.size() - 1, 3) << endl;
}

#endif
