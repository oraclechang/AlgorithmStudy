#ifdef _2_4_NEW_

/*
Problem
	x값을 기준으로 linked list 를 partition

Solution

*/

#include "Header.h"
#include "LinkedList3.h"

/*
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

*/

Node* SplitNode(Node* pHead, const int x)
{
	if (nullptr == pHead || nullptr == pHead->pNext)
		return nullptr;

	Node* pFirst = nullptr;
	Node* pSecond = nullptr;
	Node* pNode = pHead;
	while (nullptr != pNode)
	{
		Node* pNext = pNode->pNext;

		if (x > pNode->data)
		{
			pNode->pNext = pFirst;
			pFirst = pNode;
		}
		else if (x < pNode->data)
		{
			pNode->pNext = pSecond;
			pSecond = pNode;
		}

		pNode = pNext;
	}

	pNode = pFirst;
	while (nullptr != pNode->pNext)
		pNode = pNode->pNext;

	pNode->pNext = pSecond;

	return pFirst;
}

void main()
{
	Node* pHead = nullptr;
	Insert(&pHead, 1);
	Insert(&pHead, 2);
	Insert(&pHead, 3);
	Insert(&pHead, 6);
	Insert(&pHead, 7);

	Node* result = SplitNode(pHead, 5);

	while (nullptr != result)
	{
		cout << result->data << " ";
		result = result->pNext;
	}
}

#endif
