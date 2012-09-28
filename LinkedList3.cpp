#include "LinkedList3.h"

void Insert(Node** pHead, int data)
{
	Node* pNewNode = new Node(data);
	
	if (nullptr == *pHead)
		*pHead = pNewNode;
	else
	{
		Node* pCur = *pHead;
		while (nullptr != pCur->pNext)	// Áß¿ä
			pCur = pCur->pNext;

		pCur->pNext = pNewNode;
	}
}

void InsertBefore(Node** pHead, int data)
{
	Node* pNewNode = new Node(data);

	if (nullptr == *pHead)
		*pHead = pNewNode;
	else
	{
		pNewNode->pNext = *pHead;
		*pHead = pNewNode;
	}
}
