#ifdef P_9_2

/*
Problem
	Write a method to sort an array of strings so that all the anagrams are next to each other

Solution
	The basic idea is to implement a normal sorting algorithm where you override the com-pareTo method to compare the ¡°signature¡± of each string. 
	In this case, the signature is the alphabetically sorted string

	public class AnagramComparator implements Comparator<String> {
		public String sortChars(String s) {
			char[] content = s.toCharArray();
			Arrays.sort(content);
			return new String(content);
		}

		public int compare(String s1, String s2) {
			return sortChars(s1).compareTo(sortChars(s2));
		}
	}

	Now, just sort the arrays, using this compareTo method instead of the usual one

	Arrays.sort(array, new AnagramComparator()); 
*/


#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

struct AnagramSort
{
	bool operator()(string s1, string s2)
	{
		vector< char > a(s1.begin(), s1.end());
		vector< char > b(s2.begin(), s2.end());

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		return a < b;
	}
};

int main()
{
	vector< string > vArr;
	vArr.push_back("aaa");	// 1
	vArr.push_back("aba");	// 2
	vArr.push_back("bbb");	// 4
	vArr.push_back("bab");	// 3
	vArr.push_back("aaaa");	// 3
	vArr.push_back("elvis");
	vArr.push_back("lives");
	sort(vArr.begin(), vArr.end(), AnagramSort());

	copy(vArr.begin(), vArr.end(), ostream_iterator< string >(cout, " "));
	return 0;
}

#endif