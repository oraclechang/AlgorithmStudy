#ifdef _10_4_NEW_

/*
Problem

Solution

*/

#include "Header.h"

class BitSet
{
public:
	BitSet(int n);
	bool GetBit(int n);
	void SetBit(int n);
private:
	vector< int >* m_pBitArr;
};

BitSet::BitSet(int n)
{
	m_pBitArr = new vector< int >(n >> 5, 0);
}

bool BitSet::GetBit(int n)
{
	int nArrIdx = n >> 5;
	int nBitIdxInArr = n & 0x1f;

	return ( (*m_pBitArr)[nArrIdx] & (1 << nBitIdxInArr) ) != 0;
}

void BitSet::SetBit(int n)
{
	int nArrIdx = n >> 5;
	int nBitIdxInArr = n & 0x1f;

	(*m_pBitArr)[nArrIdx] |= (1 << nBitIdxInArr);
}

void CheckDup(vector< int >& vArr)
{
	BitSet oBitSet(32000);

	for (int i = 0; i < vArr.size(); ++i)
	{
		int num = vArr[i];
		int num2 = num - 1;

		if (oBitSet.GetBit(num2))
			cout << num;
		else
			oBitSet.SetBit(num2);
	}
}

void main()
{
	vector< int > vArr;
	vArr.push_back( 1 );
	vArr.push_back( 2 );
	vArr.push_back( 2 );
	vArr.push_back( 3 );
	vArr.push_back( 4 );
	vArr.push_back( 5 );

	CheckDup(vArr);
}

#endif
