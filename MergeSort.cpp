#ifdef _MERGESORT_

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

void Merge2(vector< int >& vArr, int l, int m, int u)
{
	deque< int > FirstBuf(vArr.begin() + l, vArr.begin() + m + 1);
	deque< int > SecondBuf(vArr.begin() + m + 1, vArr.begin() + u + 1);

	int i = l;
	while (!FirstBuf.empty() && !SecondBuf.empty())
	{
		if (FirstBuf.front() <= SecondBuf.front())
		{
			vArr[i++] = FirstBuf.front();
			FirstBuf.pop_front();
		}
		else
		{
			vArr[i++] = SecondBuf.front();
			SecondBuf.pop_front();
		}
	}

	while (!FirstBuf.empty())
	{
		vArr[i++] = FirstBuf.front();
		FirstBuf.pop_front();
	}

	while (!SecondBuf.empty())
	{
		vArr[i++] = SecondBuf.front();
		SecondBuf.pop_front();
	}
}

void MergeSort2(vector< int >& vArr, int l, int u)
{
	if (l < u)
	{
		int m = (l + u) / 2;
		MergeSort2(vArr, l, m);
		MergeSort2(vArr, m + 1, u);
		Merge2(vArr, l, m, u);
	}
}

int main()
{
	int aArr[] = {10, 5, 2, 3, 1, 4, 7, 8, 9, 6};
	//MergeSort(aArr, 0, 9);
	//copy(aArr, &aArr[10], ostream_iterator< int >(cout, " "));

	vector< int > vArr(&aArr[0], &aArr[sizeof(aArr) / sizeof(int)]);
	MergeSort2(vArr, 0, vArr.size() - 1);
	copy(vArr.begin(), vArr.end(), ostream_iterator< int >(cout, " "));
	return 0;
}

#endif
