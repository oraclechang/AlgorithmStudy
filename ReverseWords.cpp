#ifdef _REVERSEWORDS

/*
	���ڿ����� �ܾ �������� ����
*/

#include "Header.h"

void ReverseWord(string& str, int nBegin, int nEnd)
{
	while (nBegin < nEnd)
		swap(str[nBegin++], str[nEnd--]);
}

void ReverseWords(string& str)
{
	// ��ü ���ڿ� ������
	ReverseWord(str, 0, str.size() - 1);

	// �� �ܾ� ������
	int nBegin = 0;
	int nEnd = 0;
	int nSize = str.size();

	for (; nBegin < nSize; ++nBegin)
	{
		if (nBegin == nSize - 1)
			ReverseWord(str, nEnd, nBegin);

		if (' ' == str[nBegin])
		{
			ReverseWord(str, nEnd, nBegin - 1);
			++nBegin;
			nEnd = nBegin;
		}
	}

	cout << str << endl;
}

void main()
{
	string str = "abc def ghi jkl";

	ReverseWords(str);

}

#endif