#ifdef _11_4_NEW_

/*
Problem

Solution

*/

#include "Header.h"

int EmptyBS(vector< string > vArr, int l, int u, string strTarget)
{
	if (l > u)
		return -1;

	int m = (l + u) / 2;
	
	if (strTarget == vArr[m])
		return m;

	int nLeft = m;
	int nRight = m;
	if (vArr[m].empty())
	{
		while ( !vArr[nLeft].empty() )
			--nLeft;

		while ( !vArr[nRight].empty() )
			--nRight;

		if ( (vArr[nLeft] < strTarget) && (strTarget < vArr[nRight]) )
			return -1;
		else if (strTarget < vArr[nLeft])
			return EmptyBS(vArr, l, nLeft, strTarget);
		else if (strTarget > vArr[nRight])
			return EmptyBS(vArr, nRight, u, strTarget);
	}

	if (strTarget < vArr[m])
		return EmptyBS(vArr, l, m - 1, strTarget);
	else 
		return EmptyBS(vArr, m + 1, u, strTarget);

	return -1;
}

void main()
{
	vector< string > vArr;

	vArr.push_back("aaa");
	vArr.push_back("");
	vArr.push_back("");
	vArr.push_back("");
	vArr.push_back("");
	vArr.push_back("bbb");
	vArr.push_back("");
	vArr.push_back("c");
	vArr.push_back("");

	cout << EmptyBS(vArr, 0, vArr.size() - 1, "c") << endl;
}

#endif
