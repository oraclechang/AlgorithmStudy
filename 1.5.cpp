#ifdef P_1_5
/*
Problem
	Write a method to replace all spaces in a string with ¡®%20¡¯

Solution
	The algorithm is as follows:
	1   Count the number of spaces during the first scan of the string
	2   Parse the string again from the end and for each character:
	- If a space is encountered, store ¡°%20¡±
	- Else, store the character as it is in the newly shifted location 

	public static void ReplaceFun(char[] str, int length) {
		int spaceCount = 0, newLength, i = 0;
		for (i = 0; i < length; i++) {
			if (str[i] == ¡® ¡®) {
				spaceCount++;
			}
		}
		newLength = length + spaceCount * 2;
		str[newLength] = ¡®\0¡¯;
		for (i = length - 1; i >= 0; i--) {
			if (str[i] == ¡® ¡®) {
				str[newLength - 1] = ¡®0¡¯;
				str[newLength - 2] = ¡®2¡¯;
				str[newLength - 3] = ¡®%¡¯;
				newLength = newLength - 3;
			} else {
				str[newLength - 1] = str[i];
				newLength = newLength - 1;
			}
		}
	}
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void ReplaceSpace(char* szStr, int nSize)
{
	int nSpaceCnt = count(&szStr[0], &szStr[nSize], ' ');

	int nNewSize = nSize + (nSpaceCnt * 2);

	for (int i = nSize - 1; i >= 0; --i)
	{
		if (' ' == szStr[i])
		{
			szStr[nNewSize - 1] = '0';
			szStr[nNewSize - 2] = '2';
			szStr[nNewSize - 3] = '%';

			nNewSize = nNewSize - 3;
		}
		else
		{
			szStr[nNewSize - 1] = szStr[i];
			--nNewSize;
		}
	}

	cout << szStr;
}

int main()
{
	char szStr[100] = "abcd efg hijk";

	ReplaceSpace(szStr, strlen(szStr));

	return 0;
}

#endif