#ifdef _FIND_NON_REPETED_

/*
Problem

Solution

*/

#include "Header.h"

void FindNonRepeted(vector< char > vArr)
{
	map< char, int > mp;

	for (int i = 0; i < vArr.size(); ++i)
	{
		auto it = mp.insert(make_pair(vArr[i], 1));
		if (false == it.second)
		{
			mp[vArr[i]] = it.first->second + 1;
		}

	}

	for (int i = 0; i < vArr.size(); ++i)
	{
		auto it = mp.find(vArr[i]);
		if (1 == it->second)
		{
			cout << vArr[i] << endl;
			break;
		}
	}
}

void main()
{
	string tmp = "eeoiuruobiulkjw3";
	vector< char > vArr(tmp.begin(), tmp.end());

	FindNonRepeted(vArr);
}

#endif
