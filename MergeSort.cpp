#ifdef MERGESORT

#include "Header.h"

template< typename T >
void Merge(T* pArr, int nLow, int nMid, int nHigh)
{
	int i;
	deque< T > buffer1;
	deque< T > buffer2;

	for (i = nLow; i <= nMid; ++i)			buffer1.push_back(pArr[i]);
	for (i = nMid + 1; i <= nHigh; ++i)		buffer2.push_back(pArr[i]);

	i = nLow;
	while ( !( (buffer1.empty()) || (buffer2.empty()) ) )
	{
		if ( buffer1.front() <= buffer2.front() )
		{
			pArr[i++] = buffer1.front();
			buffer1.pop_front();
		}
		else
		{
			pArr[i++] = buffer2.front();
			buffer2.pop_front();
		}
	}

	while ( !(buffer1.empty()) ) 
	{
		pArr[i++] = buffer1.front();
		buffer1.pop_front();
	}
	while ( !(buffer2.empty()) ) 
	{
		pArr[i++] = buffer2.front();
		buffer2.pop_front();
	}
}

template< typename T >
void MergeSort(T* pArr, int nLow, int nHigh)
{
	int nMid;

	if (nLow< nHigh)
	{
		nMid = (nLow + nHigh) / 2;
		MergeSort(pArr, nLow, nMid);
		MergeSort(pArr, nMid + 1, nHigh); 
		Merge(pArr, nLow, nMid, nHigh);
	}
}

int main()
{
	int aArr[] = {10, 5, 2, 3, 1, 4, 7, 8, 9, 6};

	MergeSort(aArr, 0, 9);

	copy(aArr, &aArr[10], ostream_iterator< int >(cout, " "));

	return 0;
}

#endif
