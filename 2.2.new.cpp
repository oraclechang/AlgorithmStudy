#ifdef _2_2_NEW_

/*
Problem
	Implement an algorithm to find the nth to last element of a singly linked list

Solution

*/

#include "Header.h"
#include "LinkedList3.h"
/*
#include "LinkedList_shared_ptr.h"

template< typename T >
shared_ptr< Node< T > > FindKthToLast_Recur(shared_ptr< Node< T > > pHead, int& i, int k)
{
	if (nullptr == pHead->pNext)
		return nullptr;

	shared_ptr< Node< T > > pNode = FindKthToLast_Recur(pHead->pNext, i, k);

	i = i + 1;
	if (k == i)
		return pHead;

	return pNode;
}

template< typename T >
shared_ptr< Node< T > > FindKthToLast_Iter(shared_ptr< Node< T > > pHead, int k)
{
	shared_ptr< Node< T > > pFirst = pHead;
	shared_ptr< Node< T > > pSecond = pHead;

	for (int i = 0; i < k; ++i)
	{
		if (nullptr == pFirst)
			return nullptr;
		pFirst = pFirst->pNext;
	}

	while (nullptr != pFirst->pNext)
	{
		pFirst = pFirst->pNext;
		pSecond = pSecond->pNext;
	}

	return pSecond;
}

void main()
{
	shared_ptr< Node< int > > pHead;

	InsertNodeAtTail(&pHead, 1);
	InsertNodeAtTail(&pHead, 2);
	InsertNodeAtTail(&pHead, 3);
	InsertNodeAtTail(&pHead, 4);
	InsertNodeAtTail(&pHead, 5);

	int i = 0;
	auto pTmp = pHead;
	auto pResult = FindKthToLast_Recur(pTmp, i, 1);
	cout << pResult->data << endl;

	pResult = FindKthToLast_Iter(pTmp, 1);
	cout << pResult->data << endl;
}
*/
Node* FineKthNode(Node* pHead, int k)
{
	Node* pKthNode = nullptr;
	int count = 0;

	while (nullptr != pHead)
	{
		++count;
		if (count == k)
			pKthNode = pHead;
		else if (count > k)
			pKthNode = pKthNode->pNext;

		pHead = pHead->pNext;
	}

	return pKthNode;
}

void main()
{
	Node* pHead = nullptr;

	Insert(&pHead, 1);
	Insert(&pHead, 2);

	Node* pResult = FineKthNode(pHead, 2);
	cout << pResult->data;
}

#endif
