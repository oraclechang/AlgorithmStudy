#ifdef _STRING_PERMUTATION_2_

/*
Problem

Solution

*/

#include "Header.h"

void StringPermutation(vector< char > vArr, queue< int > que)
{
	if (que.empty())
		return;

	int idx = que.front();
	que.pop();

	StringPermutation(vArr, que);
	cout << vArr[idx] << " ";
	StringPermutation(vArr, que);
}

void main()
{
	vector< char > vArr;

	vArr.push_back('a');
	vArr.push_back('b');

	queue< int > que;
	que.push(0);
	que.push(1);
	
	StringPermutation(vArr, que);
}

#endif
