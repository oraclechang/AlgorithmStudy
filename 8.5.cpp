#ifdef P_8_5

/*
Problem
	Implement an algorithm to print all valid (e g , properly opened and closed) combi-nations of n-pairs of parentheses
	EXAMPLE:
	input: 3 (e g , 3 pairs of parentheses)
	output: ()()(), ()(()), (())(), ((()))

Solution
	We can solve this problem recursively by recursing through the string 
	On each iteration, we have the index for a particular character in the string 
	We need to select either a left or a right paren 
	When can we use left, and when can we use a right paren?
	- Left: As long as we haven¡¯t used up all the left parentheses, we can always insert a left paren
	- Right: We can insert a right paren as long as it won¡¯t lead to a syntax error 
	When will we get a syntax error? 
	We will get a syntax error if there are more right parentheses than left
	So, we simply keep track of the number of left and right parentheses allowed 
	If there are left parens remaining, we¡¯ll insert a left paren and recurse If there are more right parens remaining than left 
	(eg, if there are more left parens used), then we¡¯ll insert a right paren and recurse

	public static void printPar(int l, int r, char[] str, int count) {
		if (l < 0 || r < l) return; // invalid state
		if (l == 0 && r == 0) {
			System.out.println(str); // found one, so print it
		} else {
			if (l > 0) { // try a left paren, if there are some available
				str[count] = ¡®(¡®;
						printPar(l - 1, r, str, count + 1);
						}
						if (r > l) { // try a right paren, if there¡¯s a matching left
						str[count] = ¡®)¡¯;
				printPar(l, r - 1, str, count + 1);
						}
		}
	}

	public static void printPar(int count) {
		char[] str = new char[count*2];
		printPar(count, count, str, 0);
	}
*/

#include "../header.h"

void GenParen(string& str, int nLeftParenCnt, int nRightParanCnt, int nIdx)
{
	if (nLeftParenCnt > nRightParanCnt)
		return;

	if ((nLeftParenCnt == nRightParanCnt) && nLeftParenCnt == 0)
	{
		cout << str << endl;
		/*
		int nSize = str.size();
		str.clear();
		str.resize(nSize);
		*/
	}

	if (nLeftParenCnt > 0)
	{
		str[nIdx] = '(';
		GenParen(str, nLeftParenCnt - 1, nRightParanCnt, nIdx + 1);
	}

	if (nLeftParenCnt < nRightParanCnt)
	{
		str[nIdx] = ')';
		GenParen(str, nLeftParenCnt, nRightParanCnt - 1, nIdx + 1);
	}
}

int main()
{
	int nLen = 3;
	int nIdx = 0;
	string strTmp;
	strTmp.resize(nLen * 2);

	GenParen(strTmp, nLen, nLen, nIdx);

	return 0;
}

#endif