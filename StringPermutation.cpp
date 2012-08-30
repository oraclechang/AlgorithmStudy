#ifdef _STRINGPERMUTATION

#include "Header.h"

void DoStringPermutation(string str, string strResult, vector< bool >& pvbUsed, int nLength, int nLevel)
{
	if (0 == nLevel)
	{
		cout << strResult << endl;
		return;
	}
	else
	{
		for (int i = 0; i < nLength; ++i)
		{
			if (true == pvbUsed[i])
				continue;
			
			strResult.push_back(str[i]);
			pvbUsed[i] = true;
			DoStringPermutation(str, strResult, pvbUsed, nLength, nLevel - 1);
			pvbUsed[i] = false;
			strResult.pop_back();
		}

	}


}

void StringPermutation(string str)
{
	string	strResult;
	int		nLength = str.size();
	vector< bool > vbUsed(nLength, false);

	DoStringPermutation(str, strResult, vbUsed, nLength, nLength);
}

int main()
{
	string str = "abcd";

	StringPermutation(str);

	return 0;
}

#endif
