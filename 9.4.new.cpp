#ifdef _9_4_NEW_

/*
Problem

Solution

*/

#include "Header.h"

/*
deque< deque< int >* >* GetSubsets(deque< int >& set, int index)
{
	deque< deque< int >* >* allsubsets;

	if (set.size() == index)
	{
		allsubsets = new deque< deque< int >* >();
		allsubsets->push_back(new deque< int >());
	}
	else
	{
		allsubsets = GetSubsets(set, index + 1);
		int item = set[index];
		deque< deque< int >* >* moresubsets = new deque< deque< int >* >();

		for (auto it = allsubsets->begin(); it != allsubsets->end(); ++it)
		{
			deque< int >* newsubset = new deque< int >( (*it)->begin(), (*it)->end() );
			newsubset->push_back(item);
			moresubsets->push_back(newsubset);
		}
		
		allsubsets->assign(moresubsets->begin(), moresubsets->end());
	}

	return allsubsets;
}
*/

deque< int > MyConvertIntToSet(int k, deque< int > sSet)
{
	int nMask = 1 << sSet.size();
	int nIdx = 0;
	deque< int > sSubset;


	while (0 < nMask)
	{
		nMask >>= 1;
		if (nMask & k)
			sSubset.push_back(sSet[nIdx]);

		++nIdx;
	}

	return sSubset;
}

deque< deque< int > > GetSubsets2(deque< int > set)
{
	deque< deque< int > > allsubsets;
	int nMax = 1 << set.size();

	for (int k = 0; k < nMax; ++k)
	{
		deque< int > sSubset = MyConvertIntToSet(k, set);
		allsubsets.push_back( sSubset );
	}

	return allsubsets;
}


void main()
{
	deque< int > set;
	set.push_back( 1 );
	set.push_back( 2 );
	set.push_back( 3 );
	//set.push_back( 4 );

	//auto result = GetSubsets(set, 0);
	auto result = GetSubsets2(set);

	for ( auto x : result )
	{
		for ( auto y : x )
		{
			cout << y << " ";
		}
		cout << endl;
	}

}

#endif
