#ifdef _11_1_NEW_

/*
Problem

Solution

*/

#include "Header.h"

void MergeTwoArray(vector< int >& vFirst, vector< int >& vSecond)
{
	int nInsertIdx = vFirst.size() + vSecond.size() - 1;
	int nFirstIdx = vFirst.size() - 1;
	int nSecondIdx = vSecond.size() - 1;

	while (0 <= nFirstIdx && 0 <= nSecondIdx)
	{
		if (vFirst[nFirstIdx] > vSecond[nSecondIdx])
			vFirst[nInsertIdx--] = vFirst[nFirstIdx--];
		else
			vFirst[nInsertIdx--] = vSecond[nSecondIdx--];
	}

	while (0 <= nSecondIdx)
		vFirst[nInsertIdx--] = vSecond[nSecondIdx--];
}

void main()
{
	vector< int > vFirst;
	vFirst.push_back( 1 );
	vFirst.push_back( 3 );
	vFirst.push_back( 5 );
	vFirst.push_back( 7 );
	vFirst.push_back( 9 );
	vFirst.push_back( 0 );
	vFirst.push_back( 0 );
	vFirst.push_back( 0 );
	vFirst.push_back( 0 );

	vector< int > vSecond;
	vSecond.push_back( 2 );
	vSecond.push_back( 4 );
	vSecond.push_back( 6 );
	vSecond.push_back( 8 );

	MergeTwoArray(vFirst, vSecond);

	copy(vFirst.begin(), vFirst.end(), ostream_iterator< int >(cout, " "));
}

#endif
