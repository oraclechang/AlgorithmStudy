#ifdef _QUICKSORT

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

int main()
{
	int aArr[] = {10, 5, 2, 3, 1, 4, 7, 8, 9, 6};

	QuickSort(aArr, 0, 9);

	copy(aArr, &aArr[10], ostream_iterator< int >(cout, " "));

	return 0;
}

#endif