#ifdef P_9_5

/*
Problem
	Given a sorted array of strings which is interspersed with empty strings, write a method to find the location of a given string 
	Example: find ¡°ball¡± in [¡°at¡±, ¡°¡±, ¡°¡±, ¡°¡±, ¡°ball¡±, ¡°¡±, ¡°¡±, ¡°car¡±, ¡°¡±, ¡°¡±, ¡°dad¡±, ¡°¡±, ¡°¡±] will return 4
	Example: find ¡°ballcar¡± in [¡°at¡±, ¡°¡±, ¡°¡±, ¡°¡±, ¡°¡±, ¡°ball¡±, ¡°car¡±, ¡°¡±, ¡°¡±, ¡°dad¡±, ¡°¡±, ¡°¡±] will return -1

Solution 
	Use ordinary binary search, but when you hit an empty string, advance to the next non-empty string; 
	if there is no next non-empty string, search the left half

	public int search(String[] strings, String str, int first, int last) {
		while (first <= last) {
			// Ensure there is something at the end
			while (first <= last && strings[last] == ¡°¡±) {
				--last;
			}
			if (last < first) {
				return -1; // this block was empty, so fail
			}
			int mid = (last + first) >> 1;
			while (strings[mid] == ¡°¡±) {
				++mid; // will always find one
			}
			int r = strings[mid].compareTo(str);
			if (r == 0) return mid;
			if (r < 0) {
				first = mid + 1;
			} else {
				last = mid - 1;
			}
		}
		return -1;
	}

	public int search(String[] strings, String str) {
		if (strings == null || str == null) return -1;
		if (str == ¡°¡±) {
			for (int i = 0; i < strings.length; i++) {
				if (strings[i] == ¡°¡±) return i;
			}
			return -1;
		}
		return search(strings, str, 0, strings.length - 1);
	}
*/

#include <vector>
#include <string>
#include <iostream>

using namespace std;

int BinarySearch(vector< string >& vArr, int nStart, int nEnd, string strTargetVal)
{
	while (nStart < nEnd)
	{
		while (nStart <= nEnd && vArr[nEnd] == string(""))
			--nEnd;

		if (nEnd < nStart) {
			return -1; // this block was empty, so fail
		}

		int nMid = (nEnd + nStart) / 2;

		while (vArr[nMid] == string(""))
			++nMid;

		int result = vArr[nMid].compare(strTargetVal);
		if (0 == result)	return nMid;
		else if (0 > result)	nStart = nMid + 1;
		else	nEnd = nMid - 1;
	}

	return -1; 
}

int main()
{
	vector< string > vArr;
	vArr.push_back("at");
	vArr.push_back("");
	vArr.push_back("");
	vArr.push_back("");
	vArr.push_back("ball");
	vArr.push_back("");
	vArr.push_back("");
	vArr.push_back("car");
	vArr.push_back("");
	vArr.push_back("");
	vArr.push_back("dad");
	vArr.push_back("");
	vArr.push_back("");

	int nPosition = BinarySearch(vArr, 0, vArr.size() - 1, string("ball"));

	cout << nPosition;

	return 0;
}

#endif