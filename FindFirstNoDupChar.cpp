#ifdef _FINDFIRSTNODUPCHAR

#include "Header.h"

void FindFirstNoDupChar(string str)
{	
	int nSize = str.size();

	map< char, int > Hash;
	for (int i = 0; i < nSize; ++i)
	{
		auto it = Hash.insert(pair< char, int >(str[i], 1)); 
		if (false == it.second)
			Hash[str[i]] += 1;
	}
		

	for (int i = 0; i < nSize; ++i)
	{
		if (1 == Hash[str[i]])
		{
			cout << str[i];
			return;
		}
	}

	cout << "All chractors are duplicated" << endl;
}

void main()
{	
	string strTmp = "aabecdavoiuncelkjrw";

	FindFirstNoDupChar(strTmp);

	//return 0;
}

#endif
