#ifdef _TELEPHONEWORDS_RECURSIVE

#include "Header.h"

char CharKey[][3] =
{
	{'0', '0', '0'},
	{'1', '1', '1'},
	{'A', 'B', 'C'},
	{'D', 'E', 'F'},
	{'G', 'H', 'I'},
	{'J', 'K', 'L'},
	{'M', 'N', 'O'},
	{'P', 'R', 'S'},
	{'T', 'U', 'V'},
	{'W', 'X', 'Y'},
};

char GetCharKey(int x, int y)
{
	return CharKey[x][y];
}

void DoTelephoneWords_Recursive(vector< int >& rArr, string strResult, int nLength, int nPosition)
{
	if (nLength == nPosition)
	{
		cout << strResult << endl;
		return;
	}

	for (int i = 0; i < 3; ++i)
	{
		strResult[nPosition] = GetCharKey(rArr[nPosition], i);
		DoTelephoneWords_Recursive(rArr, strResult, nLength, nPosition + 1);

		if ('0' == strResult[nPosition] || '1' == strResult[nPosition])
			return;
	}
}

void TelephoneWords_Recursive(vector< int >& rArr)
{
	int nLength = rArr.size();
	int nPosition = 0;
	string strResult(nLength, ' ');

	DoTelephoneWords_Recursive(rArr, strResult, nLength, nPosition);
}

int main()
{
	int aArr[] = {2, 1, 3};//, 5, 7, 7, 9};

	vector< int > vArr(aArr, &aArr[sizeof(aArr) / sizeof(aArr[0])]);

	TelephoneWords_Recursive(vArr);

	return 0;
}

#endif