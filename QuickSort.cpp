#ifdef _QUICKSORT_

#include "Header.h"

int Partition(int* pArr, int nLow, int nHigh)
{
	int nPivotIdx = nHigh;
	int nSortedPosition = nLow;

	for (int i = nLow; i < nHigh; ++i)
	{
		if (pArr[i] < pArr[nPivotIdx])
			swap(pArr[nSortedPosition++], pArr[i]);
	}

	swap(pArr[nSortedPosition], pArr[nHigh]);

	return nSortedPosition;
}

void QuickSort(int* pArr, int nLow, int nHigh)
{
	if (nLow < nHigh)
	{
		int p = Partition(pArr, nLow, nHigh);
		QuickSort(pArr, nLow, p - 1);
		QuickSort(pArr, p + 1, nHigh);
	}
}

int Partition2(vector< int >& vArr, int l, int nPivotIdx)
{
	int nSortedIdx = l;

	for (int i = l; i < nPivotIdx; ++i)
	{
		if (vArr[i] < vArr[nPivotIdx])
			swap(vArr[i], vArr[nSortedIdx++]);
	}

	swap(vArr[nPivotIdx], vArr[nSortedIdx]);

	return nSortedIdx;
}

void QuickSort2(vector< int >& vArr, int l, int u)
{
	if (l > u)
		return;

	int nPivotIdx = Partition2(vArr, l, u);
	QuickSort2(vArr, l, nPivotIdx - 1);
	QuickSort2(vArr, nPivotIdx + 1, u);
}

int main()
{
	int aArr[] = {10, 5, 2, 3, 1, 4, 7, 8, 9, 6};
	QuickSort(aArr, 0, 9);
	copy(aArr, &aArr[10], ostream_iterator< int >(cout, " "));

	cout << endl;

	vector< int > vArr(&(aArr[0]), &aArr[(sizeof(aArr) / sizeof (int))]);
	QuickSort2(vArr, 0, vArr.size() - 1);
	copy(vArr.begin(), vArr.end(), ostream_iterator< int >(cout, " "));

	return 0;
}

#endif