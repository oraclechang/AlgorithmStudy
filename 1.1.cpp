#ifdef P_1_1

/*
Problem
	Implement an algorithm to determine if a string has all unique characters 
	What if you can not use additional data structures?

Solution
	For simplicity, assume char set is ASCII (if not, we need to increase the storage size The rest 
	of the logic would be the same)  NOTE: This is a greatthing to point out to your interviewer!

	public static boolean isUniqueChars2(String str) {
		boolean[] char_set = new boolean[256];
		for (int i = 0; i < str.length(); i++) {
			int val = str.charAt(i);
			if (char_set[val]) return false;
			char_set[val] = true;
		}
		return true;
	}

	Time complexity is O(n), where n is the length of the string, and space complexity is O(n)
	We can reduce our space usage a little bit by using a bit vector 
	We will assume, in the below code, that the string is only lower case ��a�� through ��z�� 
	This will allow us to use just a single int

	public static boolean isUniqueChars(String str) {
		int checker = 0;
		for (int i = 0; i < str.length(); ++i) {
			int val = str.charAt(i) - ��a��;
			if ((checker & (1 << val)) > 0) return false;
			checker |= (1 << val);
		}
		return true;
	}

	Alternatively, we could do the following:
	1   Check every char of the string with every other char of the string for duplicate occurrences This will take O(n^2) time and no space
	2   If we are allowed to destroy the input string, we could sort the string in O(n log n) time 
		and then linearly check the string for neighboring characters that are identical 
		Careful, though - many sorting algorithms take up extra space 
*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool IsUniqueChar(string str)
{
	vector< char > vChar(str.begin(), str.end());

	sort(str.begin(), str.end());

	cout << str;

	for (int i = 0; i < str.size(); ++i)
	{
		for (int j = i + 1; j < str.size(); ++j)
			if (str[i] == str[j])
				return false; 
	}

	return true;
}

int main()
{
	cout << IsUniqueChar(string("aasdfasvzxcvlkjwerewrlkjtre"));
	//cout << IsUniqueChar(string("abcd"));

	return 0;
}

#endif