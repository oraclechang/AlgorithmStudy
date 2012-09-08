#ifdef P_9_6
/*
Problem
	Given a matrix in which each row and each column is sorted, write a method to find an element in it

Solution

	Assumptions:
	- Rows are sorted left to right in ascending order Columns are sorted top to bottom in ascending order
	- Matrix is of size MxN

	This algorithm works by elimination 
	Every move to the left (--col) eliminates all the elements below the current cell in that column 
	Likewise, every move down eliminates all the elements to the left of the cell in that row

	boolean FindElem(int[][] mat, int elem, int M, int N) {
		int row = 0;
		int col = N-1; 
		while (row < M && col >= 0) {
			if (mat[row][col] == elem) {
				return true;
			} else if (mat[row][col] > elem) {
				col--;
			} else {
				row++; 
			}
		} 
		return false; 
	}
*/

#include <iostream>
#include <utility>

using namespace std;

pair< int, int > MatrixSearch(int (*nArr)[5], int nMaxRow, int nMaxCol, int nTargetVal)
{
	int nRowIdx = 0;
	int nColIdx = 0;

	// column을 정함
	while (nColIdx < nMaxCol && nArr[0][nColIdx] <= nTargetVal)
	{
		if (nTargetVal == nArr[0][nColIdx])
			return make_pair(0, nColIdx);
		else
			++nColIdx; 
	}
	--nColIdx;

	// row를 정함
	while (nRowIdx < nMaxRow && nArr[nRowIdx][nColIdx] <= nTargetVal)
	{
		if (nTargetVal == nArr[nRowIdx][nColIdx])
			return make_pair(nRowIdx, nColIdx);
		else
			++nRowIdx;
	}

	return make_pair(-1, -1);
}

pair< int, int > MatrixSearch2(int (*nArr)[5], int nMaxRow, int nMaxCol, int nTargetVal)
{
	int nRowIdx = 0;
	int nColIdx = nMaxCol - 1;

	while (nRowIdx < nMaxRow && nColIdx >= 0)
	{
		if (nArr[nRowIdx][nColIdx] == nTargetVal)
			return make_pair(nRowIdx, nColIdx);
		else if (nArr[nRowIdx][nColIdx] > nTargetVal)
			--nColIdx;
		else
			++nRowIdx;
	}

	return make_pair(-1, -1); 
}

int main()
{
	int nArr[4][5] =
	{
		{0, 4, 8, 12, 16},
		{1, 5, 9, 13, 17},
		{2, 6, 10, 14, 18},
		{3, 7, 11, 15, 19}
	};

	//auto result = MatrixSearch(nArr, 4, 5, 10);
	auto result = MatrixSearch2(nArr, 4, 5, 10);

	return 0;
}

#endif