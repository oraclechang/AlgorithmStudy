#ifdef P_3_5_NEW

/*
Problem
	2개의 stack으로 1개의 queue 구현
Solution

*/

#include "Header.h"
#include "Stack_LinkedList.h"

template< typename T >
class Myqueue
{
public:
	void Push(T data);
	T Pop();
	void shiftStack();
private:
	stack< T > stkNewStack;
	stack< T > stkOldStack;
};

template< typename T >
void Myqueue< T >::Push(T data)
{
	stkNewStack.push(data);
}

template< typename T >
T Myqueue< T >::Pop()
{
	shiftStack();

	T tmp = stkOldStack.top();
	stkOldStack.pop();

	return tmp;
}

template< typename T >
void Myqueue< T >::shiftStack()
{
	if (stkOldStack.empty())
		while (!stkNewStack.empty())
		{
			T tmp = stkNewStack.top();
			stkNewStack.pop();
			stkOldStack.push(tmp);
		}
}

void main()
{
	Myqueue< int > oMyQueue;
	oMyQueue.Push(1);
	oMyQueue.Push(2);
	oMyQueue.Push(3);
	oMyQueue.Push(4);
	oMyQueue.Push(5);

	cout << oMyQueue.Pop() << endl;
	cout << oMyQueue.Pop() << endl;
	cout << oMyQueue.Pop() << endl;
	cout << oMyQueue.Pop() << endl;
	cout << oMyQueue.Pop() << endl;
}

#endif
