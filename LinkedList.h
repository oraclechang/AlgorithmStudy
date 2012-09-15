#ifdef _LINKED_LIST_2_

#include "header.h"

template< typename T >
struct Node
{
	Node*	pNext;
	T		data;

	Node() : pNext(nullptr) {}
	Node(T x) : data(x), pNext(nullptr){}
};

template< typename T >
class LinkedList
{
public:
	LinkedList();
	int Search();
	void Insert(T);
	void Delete();
	void PrintAll();
	void deleteDups();		// with buffer
	void deleteDups2();		// without buffer

private:
	Node< T >*	pHead;
};

template< typename T >
LinkedList< T >::LinkedList()
{
	pHead = new Node< T >();
}

template< typename T >
void LinkedList< T >::Insert(T data)
{
	Node< T >* pTmp = pHead;
	Node< T >* pNewNode = new Node< T >(data);

	while (nullptr != pTmp->pNext)
		pTmp = pTmp->pNext;

	pTmp->pNext = pNewNode;
}

template< typename T >
void LinkedList< T >::PrintAll()
{
	Node< T >* pTmp = pHead;
	while (nullptr != pTmp->pNext)
	{ 
		cout << pTmp->pNext->data << " ";
		pTmp = pTmp->pNext;
	}
}

template< typename T >
void LinkedList< T >::deleteDups()
{
	set< T > setDup;

	if (nullptr == pHead->pNext)
		return;

	Node< T >* pTmp = pHead->pNext;
	Node< T >* pPrevious = nullptr;
	while (nullptr != pTmp)
	{
		auto rtn = setDup.insert(pTmp->data);
		if (false == rtn.second)
			pPrevious->pNext = pTmp->pNext;
		else
			pPrevious = pTmp;

		pTmp = pTmp->pNext;
	}
}

template< typename T >
void LinkedList< T >::deleteDups2()
{
	if (nullptr == pHead->pNext)
		return;

	Node< T >* pCurr = pHead->pNext;
	Node< T >* pPrev = pHead;

	while (nullptr != pCurr)
	{
		T curData = pCurr->data;
		Node< T >* pRunner = pHead->pNext;

		while (pRunner != pCurr)
		{
			T runnerData = pRunner->data;

			if (runnerData == curData)
			{
				pPrev->pNext = pCurr->pNext;
				pCurr = pCurr->pNext;			// 중요!!!
				break;							// 중요!!!
			}

			pRunner = pRunner->pNext;
		}

		if (pRunner == pCurr)					// 중요!!!
		{
			pPrev = pCurr;
			pCurr = pCurr->pNext;
		}

	}
}

#endif
