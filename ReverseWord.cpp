#ifdef _REVERSEWORD

#include "Header.h"

void ReverseWord(string& str, int nStart, int nEnd)
{
	// 전체 문자열 Reverse
	while (nStart < nEnd)
	{
		swap(str[nStart++], str[nEnd--]);
	}
}

void ReverseWords(string str)
{
	ReverseWord(str);

	int nStart = 0;
	int nEnd = 0;
	int i = 0;
	while (i < str.size())
	{
		if (' ' == str[i])
		{
			--nEnd;
			ReverseWord(str, nStart, nEnd);
		}
		else
		{
			++
		}


	}


	cout << str << endl;

}

int main()
{
	string str = "abc def ghi jkl";

	ReverseWords(str);

	return 0;
}

#endif
