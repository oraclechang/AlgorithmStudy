#ifdef _STRINGCOMBINE

#include "Header.h"

void DoStringCombine(string str, string result, int length, int level, int start)
{
	for (int i = start; i < length; i++)
	{
		result.push_back(str[i]); 
		cout << result << endl;

		if (i < length - 1)
		{
			DoStringCombine(str, result, length, level + 1, i + 1);
		}

		result.pop_back();
	}
}

void StringCombine(string str)
{
	int length = str.size();
	string result;

	DoStringCombine(str, result, length, 0, 0);
}

int main()
{
	string str = "wxyz";

	StringCombine(str);

	return 0;
}

#endif