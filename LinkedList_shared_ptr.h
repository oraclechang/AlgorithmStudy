#ifdef _LINKED_LIST_SMARTPTR_

#include "Header.h"

template< typename T >
struct Node
{
	shared_ptr< Node > pNext;
	T data;

	Node(T _data) : data(_data), pNext(nullptr) {}
};


// Insert
template< typename T >
bool InsertNodeAtAfter(shared_ptr< Node< T > >* ppNode, T data)
{
	shared_ptr< Node< T > > pNewNode(new Node(data));

	if (nullptr == *ppNode)
		*ppNode = pNewNode;
	else
	{
		shared_ptr< Node< T > >  pTmp = *ppNode;
		pNewNode->pNext = pTmp->pNext;
		pTmp->pNext = pNewNode;
	}

	return true;
}

// Delete
// Search
// Travelse

template< typename T >
bool InsertNodeAtTail(shared_ptr< Node< T > >* ppNode, int data)
{
	shared_ptr< Node< T > > pNewNode(new Node< T >(data));

	if (nullptr == *ppNode)
		*ppNode = pNewNode;
	else
	{
		shared_ptr< Node< T > > pTmp = *ppNode;

		while (nullptr != pTmp->pNext)
			pTmp = pTmp->pNext;

		pTmp->pNext = pNewNode;
	}

	return true;
}

template< typename T >
bool DeleteNode(shared_ptr< Node< T > >* ppNode,const T data)
{
	if (nullptr == *ppNode)
		return false;

	shared_ptr< Node< T > > pTmp;
	pTmp = *ppNode;
	if (data == (*ppNode)->data)
	{
		*ppNode = (*ppNode)->pNext;

		//delete pTmp;
	}
	else
	{
		shared_ptr< Node< T > > pPrevNode = pTmp;
		while (nullptr != pTmp)
		{
			if (data == pTmp->data)
			{
				pPrevNode->pNext = pTmp->pNext;
				//delete pTmp;

				return true;
			}
			pPrevNode = pTmp;
			pTmp = pTmp->pNext;
		}
	}

	return false;
}

template< typename T >
void TravelseNode(shared_ptr< Node< T > > pHead)
{
	while (nullptr != pHead)		// 주의!!! pHead->pNext 가 null일때가지 출력하면 마지막 node 가 출력되지 않음
	{
		cout << pHead->data << " ";
		pHead = pHead->pNext;
	}
	cout << endl;
}

/*
void main()
{
	shared_ptr< Node > pHead(nullptr);

	//InsertAfter(&pHead, 1);
	//InsertAfter(&pHead, 2);
	//InsertAfter(&pHead, 3);
	//InsertAfter(&pHead, 4);

	InsertNodeAtTail(&pHead, 1);
	InsertNodeAtTail(&pHead, 2);
	InsertNodeAtTail(&pHead, 3);
	InsertNodeAtTail(&pHead, 4);

	//DeleteNode(&pHead, 1);	// Head 삭제 테스트
	TravelseNode(pHead);

	//DeleteNode(&pHead, 2);		// 중간 삭제 테스트
	TravelseNode(pHead);

	DeleteNode(&pHead, 4);		// tail 삭제 테스트
	TravelseNode(pHead);
}
*/

#endif
