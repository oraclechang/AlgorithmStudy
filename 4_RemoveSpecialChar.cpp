#ifdef _4_REMOVE_SPECIAL_CHAR_

/*
Problem

Solution

*/

#include "Header.h"

void RemoveSpecialChar(string& tmp, string remove)
{
	set< char > stSet(remove.begin(), remove.end());

	int j = 0;
	for (int i = 0; i < tmp.size(); ++i)
	{
		auto it = stSet.find(tmp[i]);
		if (stSet.end() != it)
			continue;

		tmp[j++] = tmp[i];
	}

	tmp.resize(j);
}

void main()
{
	string tmp = "aab bbc cdf";
	string remove = "bdf";

	RemoveSpecialChar(tmp, remove);

	cout << tmp << endl;
}

#endif
