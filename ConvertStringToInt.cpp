#ifdef _CONVERTSTRINGTOINT

#include "Header.h"

void ConvertStringToInt(string& str)
{
	int nResult = 0;
	int i = 0;
	bool bMinus = false;

	if ('-' == str[0])
	{
		i = 1;
		bMinus = true;
	}

	for (; i < str.size(); ++i)
	{
		nResult *= 10;
		nResult += (str[i] - '0');
	}

	if (bMinus)
		nResult *= -1;
	
	cout << nResult << endl;
}

void main()
{
	string strValue = "3126894";

	ConvertStringToInt(strValue);

	strValue = "-3126894";

	ConvertStringToInt(strValue);
}

#endif