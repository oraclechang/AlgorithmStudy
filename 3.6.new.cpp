#ifdef P_3_6_NEW

/*
Problem
	stack을 오름차순으로 정렬하는 함수 작성
	top 이 가장 큰 값
	stacks 구조체만 사용 가능
Solution

*/

#include "Header.h"

template< typename T >
stack< T > StackSort(stack< T > unsortedStack)
{
	stack< T > sortedStack;

	T tmp;
	while (!unsortedStack.empty())
	{
		tmp = unsortedStack.top();
		unsortedStack.pop();

		while (!sortedStack.empty() && tmp < sortedStack.top())
		{
			unsortedStack.push(sortedStack.top());
			sortedStack.pop();
		}

		sortedStack.push(tmp);
	}

	return sortedStack;
}

void main()
{
	stack< int > unsortedStack;
	unsortedStack.push(3);
	unsortedStack.push(2);
	unsortedStack.push(1);
	unsortedStack.push(4);
	unsortedStack.push(5);

	stack< int > Result = StackSort(unsortedStack);

	while (!Result.empty())
	{
		cout << Result.top() << " ";
		Result.pop();
	}
}

#endif
