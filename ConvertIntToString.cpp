#ifdef _CONVERTINTTOSTRING

#include "Header.h"

void ConvertIntToString(int nValue)
{
	bool bMinus = false;

	string strResult;

	if (0 > nValue)
	{
		bMinus = true;
		nValue *= -1;
	}

	do {
		int nRemainder = nValue % 10;
		strResult.push_back('0' + nRemainder);
		nValue /= 10;
	} while (0 != nValue);

	if (bMinus)
		strResult.push_back('-');

	int nStart = 0;
	int nEnd = strResult.size() - 1;

	while (nStart < nEnd)
		swap(strResult[nStart++], strResult[nEnd--]);

	cout << strResult << endl;
}

void main()
{
	int nValue = -3215479;

	ConvertIntToString(nValue);
}

#endif