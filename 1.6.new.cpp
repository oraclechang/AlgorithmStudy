#ifdef _1_6_NEW_
// SOLVEAGAIN

/*
Problem
	find duplicate char in string without additional buffer.
Solution

*/

#include "Header.h"
#include "BSTree.h"

void RotateMatrix(vector< vector< int > >& vvArr)
{
	int nMatrixSize = vvArr.size();
	
	for (int layer = 0; layer < nMatrixSize / 2; ++layer)
	{
		int nFirst = layer;
		int nLast = nMatrixSize - 1 - layer;

		for (int i = nFirst; i < nLast; ++i)
		{
			int nOffset = i - nFirst;
			
			// Tmp <- Top
			int nTmp = vvArr[nFirst][i];

			// Top <- Left
			vvArr[nFirst][i] = vvArr[nLast - nOffset][nFirst];
			
			// Left <- Bottom
			vvArr[nLast - nOffset][nFirst] = vvArr[nLast][nLast - nOffset];

			// Bottom <- Right
			vvArr[nLast][nLast - nOffset] = vvArr[i][nLast];

			// Right <- Tmp
			vvArr[i][nLast] = nTmp;
		}

	}
}

template< typename T >
void PrintVector(vector< T > vArr)
{
	for (auto x : vArr)
	{
		for (auto y : x)
		{
			cout << y << " ";
		}
		cout << endl;
	}
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

	PrintVector(vArr);

	RotateMatrix(vArr);

	PrintVector(vArr);
}

#endif
