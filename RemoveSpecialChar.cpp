#ifdef _REMOVESPECIALCHAR

#include "Header.h"

void RemoveSpecialChar(string& str, const string& strRemoveList)
{
	// 맵 생성
	set< char > Hash(strRemoveList.begin(), strRemoveList.end());
	
	int src = 0;
	int dest = 0;
	for (int i = 0; i < str.size(); ++i)
	{
		auto it = Hash.find(str[i]);
		// Remove 리스트에 없으면 복사
		if (Hash.end() == it)	
			str[dest++] = str[src++];
		else
			++src;
	}
	
	str.resize(dest);

	cout << str;		// 이게 중요함!!!
}

void main()
{
	string strTmp = "I know I can do it";
	string strRemoveList = "iow";

	RemoveSpecialChar(strTmp, strRemoveList);

}

#endif