#ifdef P_2_7_NEW

/*
Problem

Solution

*/

#include "Header.h"
#include "LinkedList_shared_ptr.h"

template< typename T >
bool IsPalindrome(shared_ptr< Node< T > > pNode)
{
	stack< T > stk;
	shared_ptr< Node< T > > pSlow = pNode;
	shared_ptr< Node< T > > pFast = pNode;

	while(nullptr != pFast && nullptr != pFast->pNext)
	{
		stk.push(pSlow->data);

		pSlow = pSlow->pNext;
		pFast = pFast->pNext->pNext;
	}

	if (nullptr != pFast)
		pSlow = pSlow->pNext;

	while(nullptr != pSlow)
	{
		T TopData = stk.top();
		stk.pop();

		if (pSlow->data != TopData)
			return false;

		pSlow = pSlow->pNext;
	}

	return true;
}

void main()
{
	shared_ptr< Node< int > > pHead;

	InsertNodeAtTail(&pHead, 0);
	InsertNodeAtTail(&pHead, 1);
	InsertNodeAtTail(&pHead, 2);
	InsertNodeAtTail(&pHead, 1);
	InsertNodeAtTail(&pHead, 0);

	cout << (IsPalindrome(pHead) ? "true" : "false") << endl;
}

#endif
