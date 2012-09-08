#ifdef P_1_2
/*
Problem
	Write code to reverse a C-Style String (C-String means that ¡°abcd¡± is represented as 
	five characters, including the null character )

Solution
	This is a classic interview question The only ¡°gotcha¡± is to try to do it in place, and to be careful for the null character

	void reverse(char *str) {
		char * end = str;
		char tmp;
		if (str) {
			while (*end) {
				++end;
			}
			--end;
			while (str < end) {
				tmp = *str;
				*str++ = *end;
				*end-- = tmp;
			}
		}
	}
*/

#include <iostream>

using namespace std;

char* ReverseString(char* pszStr)
{
	int nStrSize = sizeof(pszStr);
	char* pszEnd = pszStr + nStrSize - 1;

	char tmp;
	while (pszStr < pszEnd)
	{
		tmp = *pszStr;
		*pszStr++ = *pszEnd;
		*pszEnd-- = tmp;
	}

	return pszStr;
}

void reverse(char *str) {
	char * end = str;
	char tmp;
	if (str) {
		while (*end) {
			++end;
		}
		--end;
		while (str < end) {
			tmp = *str;
			*str++ = *end;
			*end-- = tmp;
		}
	}
}

int main()
{
	char pszStr[] = "abcd";

	cout << ReverseString(pszStr);

	return 0;
}

#endif