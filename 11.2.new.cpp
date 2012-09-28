#ifdef _11_2_NEW_

/*
Problem
	Anagram이 다음에 위치하도록 배열 정열
Solution
	
*/

#include "Header.h"

bool CompareAnagram(string lhs, string rhs)
{
	sort(lhs.begin(), lhs.end());
	sort(rhs.begin(), rhs.end());

	return lhs < rhs;
}

int Partition(vector< string >& vArr, int nLowIdx, int nUpIdx)
{
	int nFirstIdx = nLowIdx;
	int nSecondIdx = nUpIdx - 1;
	string strCompVal = vArr[nUpIdx];

	while (nFirstIdx < nSecondIdx)
	{
		while (CompareAnagram(vArr[nFirstIdx], vArr[nUpIdx]))	// vArr[nFirstIdx] < vArr[nUpIdx]
			++nFirstIdx;

		while (CompareAnagram(vArr[nUpIdx], vArr[nSecondIdx]))	// vArr[nSecondIdx] > vArr[nUpIdx]
			--nSecondIdx;

		if (nFirstIdx < nSecondIdx)
			swap(vArr[nFirstIdx++], vArr[nSecondIdx--]);
	}

	if (CompareAnagram(vArr[nUpIdx], vArr[nFirstIdx]))			// vArr[nFirstIdx] > vArr[nUpIdx]
		swap(vArr[nFirstIdx], vArr[nUpIdx]);

	return nSecondIdx;
}

void doAnagramSort(vector< string >& vArr, int nLowIdx, int nUpIdx)
{
	if (nLowIdx >= nUpIdx)
		return;

	int nMid = Partition(vArr, nLowIdx, nUpIdx);
	doAnagramSort(vArr, nLowIdx, nMid - 1);
	doAnagramSort(vArr, nMid + 1, nUpIdx);
}

void AnagramSort(vector< string >& vArr)
{
	doAnagramSort(vArr, 0, vArr.size() - 1);
}

void AnagramHash(vector< string >& vArr)
{
	map< string, list< string >* > mHash;

	for (auto strTmp : vArr)
	{
		auto strSortedString(strTmp);
		sort(strSortedString.begin(), strSortedString.end());

		auto it = mHash.find(strSortedString);
		if (it == mHash.end())
		{
			list< string >* newList = new list< string >();
			newList->push_back(strTmp);
			mHash.insert(make_pair(strSortedString, newList));
		}
		else
		{
			it->second->push_back(strTmp);
		}
	}

	for (auto x : mHash)
	{
		cout << x.first << " : ";
		for (auto y : (*x.second))
		{
			cout << y << " ";
		}
		cout << endl;
	}
}

void main()
{
	vector< string > vArr;
	vArr.push_back( "bba" );
	vArr.push_back( "abb" );
	vArr.push_back( "tba" );
	vArr.push_back( "xaw" );
	vArr.push_back( "oxaw" );
	vArr.push_back( "xab" );
	vArr.push_back( "gbb" );
	vArr.push_back( "lll" );

	/*
	AnagramSort(vArr);
	copy(vArr.begin(), vArr.end(), ostream_iterator< string >(cout, " "));
	cout << endl;
	*/

	AnagramHash(vArr);
}

#endif
