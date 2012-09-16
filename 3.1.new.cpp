#ifdef P_3_1_NEW

/*
Problem
	Single arry로 3개의 stack 만들기

Solution

*/

#include "Header.h"
#include "Stack_LinkedList.h"

void main()
{
	shared_ptr< Node< int > > pTop;
	StackPush(&pTop, 1);
	StackPush(&pTop, 2);
	StackPush(&pTop, 3);
	StackPush(&pTop, 4);
	StackPush(&pTop, 5);

	auto Result = StackPop(&pTop);
	cout << Result->data << endl;
	Result = StackPop(&pTop);
	cout << Result->data << endl;
	Result = StackPop(&pTop);
	cout << Result->data << endl;
	Result = StackPop(&pTop);
	cout << Result->data << endl;
	Result = StackPop(&pTop);
	cout << Result->data << endl;
}

#endif
