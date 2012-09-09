#ifdef P_5

/*
Problem

Solution

*/

#include "Header.h"

bool GetBit(int num, int i)
{
	num >>= i;
	return (1 && num);
}

bool GetBit2(int num, int i)
{
	int mask = (1 << i);

	return ((num && mask) != 0);
}

int SetBit(int num, int i)
{
	return (num | (1 << i));
}

int ClearBit(int num, int i)
{
	int mask = ~(1 << i);

	return (num & mask);
}

int UpdateBit(int num, int i)
{
	int mask = (1 << i); 

	return (num ^ mask);
}

int CountBit(int num)
{
	int nCount = 0;

	while (0 < num)
	{
		if (1 & num)
			++nCount;

		num >>= 1;
	}

	return nCount;
}

void main()
{
	int num = 13;

	cout << GetBit2(num, 2) << endl;

	cout << SetBit(num, 1) << endl;
	
	cout << ClearBit(num, 2) << endl;

	cout << UpdateBit(num, 3) << endl;

	cout << CountBit(num) << endl;
}

#endif
