#ifdef P_8_1

/*
Problem
	Write a method to generate the nth Fibonacci number

Solution
	There are three potential approaches: (1) recursive approach (2) iterative approach (3) using 
	matrix math We have described the recursive and iterative approach below, as you would 
	not be expected to be able to derive the matrix-based approach in an interview For the 
	interested math-geeks, you may read about the (most efficient) matrix-based algorithm at 
	http://en wikipedia org/wiki/Fibonacci_number#Matrix_form

	Recursive Solution:
	int fibo(int n) { 
		if (n == 0) {
			return 0; // f(0) = 0
		} else if (n == 1) {
			return 1; // f(1) = 1
		} else if (n > 1) {
			return fibo(n-1) + fibo(n-2); // f(n) = f(n?1) + f(n-2)
		} else {
			return ?1; // Error condition
		}
	}

	Iterative Solution:
	int fibo(int n) { 
		if (n < 0) return -1; // Error condition.
		if (n == 0) return 0;
		int a = 1, b = 1;
		for (int i = 3; i <= n; i++) {
			int c = a + b;
			a = b;
			b = c;
		}
		return b;
	}
*/
#include "../header.h"

int Fibo_Recur(int n)
{
	if (0 == n)
		return 0;
	else if (1 == n)
		return 1;
	else
	{
		return Fibo_Recur(n - 1) + Fibo_Recur(n - 2);
	}
}

int Fibo_Iter(int n)
{
	vector< int > vArr;
	vArr.push_back(0);
	vArr.push_back(1);

	for (int i = 2; i <= n; ++i)
	{
		vArr.push_back(vArr[i - 1] + vArr[i - 2]);
	}

	return vArr.back();
}

int main()
{
	//int result = Fibo_Recur(10);

	int result = Fibo_Iter(10);
	
	cout << result;


	return 0;
}

#endif
