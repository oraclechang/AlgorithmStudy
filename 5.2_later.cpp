#ifdef P_5_2

/*
Problem
	Given a (decimal - e g 3.72) number that is passed in as a string, print the binary rep-resentation 
	If the number can not be represented accurately in binary, print ¡°ERROR¡±

Solution
	First, let¡¯s start off by asking ourselves what a non-integer number in binary looks like 
	By analogy to a decimal number, the number n = 0.101 = 1 * (1/2^1) + 0 * (1/2^2) + 1 * (1/2^3) 
	Printing the int part of n is straight-forward (see below) 
	To print the decimal part, we can multiply by 2 and check if the 2*n is greater than or equal to one 
	This is essentially ¡°shifting¡± the fractional sum That is:

		r = 2*n = 2*0.101 = 1*(1 / 2^0) + 0*(1 / 2^1) + 1*(1 / 2^2) = 1.01

	If r >= 1, then we know that n had a 1 right after the decimal point By doing this continu-ously, we can check every digit

	public static String printBinary(String n) {
		int intPart = Integer.parseInt(n.substring(0, n.indexOf(¡®.¡¯)));
		double decPart = Double.parseDouble(
				n.substring(n.indexOf(¡®.¡¯), n.length()));
		String int_string = ¡°¡±;
		while (intPart > 0) {
			int r = intPart % 2;
			intPart >>= 1;
			int_string = r + int_string;
		}
		StringBuffer dec_string = new StringBuffer();
		while (decPart > 0) {
			if (dec_string.length() > 32) return ¡°ERROR¡±;
			if (decPart == 1) {
				dec_string.append((int)decPart);
				break;
			}
			double r = decPart * 2;
			if (r >= 1) {
				dec_string.append(1);
				decPart = r - 1;
			} else {
				dec_string.append(0);
				decPart = r;
			}
		}
		return int_string + ¡°.¡± + dec_string.toString();
	}
*/

#include "Header.h"

void main()
{
}

#endif
