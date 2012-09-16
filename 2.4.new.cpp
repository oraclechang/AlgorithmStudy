#ifdef P_2_4_NEW

/*
Problem
	x값을 기준으로 linked list 를 partition

Solution

*/

#include "Header.h"
#include "LinkedList_shared_ptr.h"

template< typename T >
shared_ptr< Node< T > > SplitNodes(shared_ptr< Node< T > > pHead, int x)
{
	shared_ptr< Node< T > > pFirst = nullptr;
	shared_ptr< Node< T > > pSecond = nullptr;
	shared_ptr< Node< T > > pTmp = pHead;

	while (nullptr != pTmp)
	{
		shared_ptr< Node< T > > pNextNode = pTmp->pNext;

		if (x > pTmp->data)
		{
			pTmp->pNext = pFirst;
			pFirst = pTmp;
		}
		else
		{
			pTmp->pNext = pSecond;
			pSecond = pTmp;
		}

		pTmp = pNextNode;
	}

	pTmp = pFirst;
	while (nullptr != pTmp->pNext)
		pTmp = pTmp->pNext;

	pTmp->pNext = pSecond;

	return pFirst;
}


void main()
{
	shared_ptr< Node< int > > pHead;

	InsertNodeAtTail(&pHead, 4);
	InsertNodeAtTail(&pHead, 5);
	InsertNodeAtTail(&pHead, 1);
	InsertNodeAtTail(&pHead, 2);
	InsertNodeAtTail(&pHead, 3);

	auto result = SplitNodes(pHead, 3);

	TravelseNode(result);
}

#endif
