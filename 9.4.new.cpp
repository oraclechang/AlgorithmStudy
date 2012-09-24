#ifdef _9_4_NEW_

/*
Problem

Solution

*/

#include "Header.h"

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

void main()
{
	deque< int > set;
	set.push_back( 1 );
	set.push_back( 2 );
	set.push_back( 3 );
	set.push_back( 4 );

	auto result = GetSubsets(set, 0);
}

#endif
