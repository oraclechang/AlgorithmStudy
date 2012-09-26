#ifdef _9_5_NEW_

/*
Problem

Solution

*/

#include "Header.h"

void AddParen(list< string >& result, int nLeftRem, int nRightRem, string& str, int nCount)
{
	if ( (0 > nLeftRem) || (nLeftRem > nRightRem) )
		return;

	if ( 0 == nLeftRem && 0 == nRightRem)
	{
		string tmp(str);
		result.push_back(tmp);
	}
	else
	{
		if (0 < nLeftRem)
		{
			str[nCount] = '(';
			AddParen(result, nLeftRem - 1, nRightRem, str, nCount + 1);
		}

		if (nLeftRem < nRightRem)
		{
			str[nCount] = ')';
			AddParen(result, nLeftRem, nRightRem - 1, str, nCount + 1);
		}
	}
}

list< string> GenParens(int nCount)
{
	string str(nCount * 2, ' ');
	list< string > result;
	AddParen(result, nCount, nCount, str, 0);

	return result;
}

void main()
{
	auto result = GenParens(5);

	for (auto x : result)
		cout << x << endl;
}

#endif
