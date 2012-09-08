#ifdef P_1_4
/*
Problem
	Write a method to decide if two strings are anagrams or not

Solution
	There are two easy ways to solve this problem:

	Solution #1: Sort the strings 

	boolean anagram(String s, String t) {
		return sort(s) == sort(t);
	}

	Solution #2: Check if the two strings have identical counts for each unique char.  

	public static boolean anagram(String s, String t) {
		if (s.length() != t.length()) return false;
		int[] letters = new int[256];
		int num_unique_chars = 0;
		int num_completed_t = 0;
		char[] s_array = s.toCharArray();
		for (char c : s_array) { // count number of each char in s.
			if (letters[c] == 0) ++num_unique_chars;
			++letters[c];
		}
		for (int i = 0; i < t.length(); ++i) {
			int c = (int) t.charAt(i);
			if (letters[c] == 0) { // Found more of char c in t than in s.
				return false;
			}
			--letters[c];
			if (letters[c] == 0) {
				++num_completed_t;
				if (num_completed_t == num_unique_chars) {
					// it¡¯s a match if t has been processed completely
					return i == t.length() - 1;
				}
			}
		}
		return false;
	}
*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool CheckAnagram1(string s1, string s2)
{
	vector< char > vChar1(s1.begin(), s1.end());
	vector< char > vChar2(s2.begin(), s2.end());

	sort(vChar1.begin(), vChar1.end());
	sort(vChar2.begin(), vChar2.end());
 
	return vChar1 == vChar2 ? true : false;
}

int main()
{
	string s1("abcd");
	string s2("xcdab");

	cout << CheckAnagram1(s1, s2);

	return 0;
}
#endif