#ifdef P_1_3
/*
Problem
	Design an algorithm and write code to remove the duplicate characters in a string without using any additional buffer 
	NOTE: One or two additional variables are fine 
	An extra copy of the array is not 
	
	FOLLOW UP
	Write the test cases for this method

Solution 1
	First, ask yourself, what does the interviewer mean by an additional buffer? 
	Can we use an additional array of constant size? 

	Algorithm - No (Large) Additional Memory:
	1   For each character, check if it is a duplicate of already found characters
	2   Skip duplicate characters and update the non duplicate characters
	Time complexity is O(N2)

	public static void removeDuplicates(char[] str) {
		if (str == null) return;
		int len = str.length;
		if (len < 2) return;

		int tail = 1;

		for (int i = 1; i < len; ++i) {
			int j;
			for (j = 0; j < tail; ++j) {
				if (str[i] == str[j]) break;
			}
			if (j == tail) {
				str[tail] = str[i];
				++tail;
			}
		}
		str[tail] = 0;
	}

	Test Cases:
	1   String does not contain any duplicates, e g : abcd
	2   String contains all duplicates, e g : aaaa
	3   Null string
	4   String with all continuous duplicates, e g : aaabbb
	5   String with non-contiguous duplicate, e g : abababa
*/
/*
Solution 2
	Algorithm - With Additional Memory of Constant Size 

	public static void removeDuplicatesEff(char[] str) {
		if (str == null) return;
		int len = str.length;
		if (len < 2) return;
		boolean[] hit = new boolean[256];
		for (int i = 0; i < 256; ++i) {
			hit[i] = false;
		}
		hit[str[0]] = true;
		int tail = 1;
		for (int i = 1; i < len; ++i) {
			if (!hit[str[i]]) {
				str[tail] = str[i];
				++tail;
				hit[str[i]] = true;
			}
		}
		str[tail] = 0;
	}

	Test Cases:
	1   String does not contain any duplicates, e g : abcd
	2   String contains all duplicates, e g : aaaa
	3   Null string
	4   Empty string
	5   String with all continuous duplicates, e g : aaabbb
	6   String with non-contiguous duplicates, e g : abababa
*/

#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

void RemoveDuplicateChar(char* pszStr)
{
	if (NULL == pszStr)		return;

	int nStrSize = strlen(pszStr);
	if (2 > nStrSize)	return;

	int nTail = 1;
	for (int i = 1; i < nStrSize; ++i)
	{
		int j;
		for (j = 0; j < nTail; ++j)
		{
			if (pszStr[j] == pszStr[i]) 
				break;
		}

		if (j == nTail)
		{
			pszStr[nTail] = pszStr[i];
			++nTail;
		}
	}
	pszStr[nTail] = 0;

	cout << pszStr;
}

void RemoveDuplicateChar2(char* pszStr)
{
	set< char > sNoDupCharList;
	int nStrSize = strlen(pszStr);

	int nTail = 1;
	sNoDupCharList.insert(pszStr[0]);

	for (int i = 1; i < nStrSize; ++i)
	{
		auto it = sNoDupCharList.find(pszStr[i]);
		if (it == sNoDupCharList.end())
		{
			sNoDupCharList.insert(pszStr[i]);
			pszStr[nTail] = pszStr[i]; 
			++nTail;
		}
	}

	pszStr[nTail] = 0;

	cout << pszStr;
}


int main()
{
	char pszStr[] = "aaaaabcd";
	//char pszStr[] = "abcd";
	//RemoveDuplicateChar(pszStr);
	RemoveDuplicateChar2(pszStr);

	return 0;
}
#endif