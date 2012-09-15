#ifdef _LINKED_LIST_

#include "Header.h"

struct Node
{
	Node* pNext;
	int data;

	Node(int _data) : data(_data), pNext(nullptr) {}
};


// Insert
bool InsertNodeAtAfter(Node** pNode, int data)
{
	Node* pNewNode = new Node(data);

	if (nullptr == *pNode)
		*pNode = pNewNode;
	else
	{
		Node* pTmp = *pNode;
		pNewNode->pNext = pTmp->pNext;
		pTmp->pNext = pNewNode;
	}

	return true;
}

// Delete
// Search
// Travelse

bool InsertNodeAtTail(Node** ppNode, int data)
{
	Node* pNewNode = new Node(data);

	if (nullptr == *ppNode)
		*ppNode = pNewNode;
	else
	{
		Node* pTmp = *ppNode;

		while (nullptr != pTmp->pNext)
			pTmp = pTmp->pNext;

		pTmp->pNext = pNewNode;
	}

	return true;
}

bool DeleteNode(Node** ppNode,const int data)
{
	if (nullptr == *ppNode)
		return false;

	Node* pTmp;
	pTmp = *ppNode;
	if (data == (*ppNode)->data)
	{
		*ppNode = (*ppNode)->pNext;

		delete pTmp;
	}
	else
	{
		Node* pPrevNode = pTmp;
		while (nullptr != pTmp)
		{
			if (data == pTmp->data)
			{
				pPrevNode->pNext = pTmp->pNext;
				delete pTmp;

				return true;
			}
			pPrevNode = pTmp;
			pTmp = pTmp->pNext;
		}
	}

	return false;
}

void TravelseNode(Node* pHead)
{
	while (nullptr != pHead)		// ����!!! pHead->pNext �� null�϶����� ����ϸ� ������ node �� ��µ��� ����
	{
		cout << pHead->data << " ";
		pHead = pHead->pNext;
	}
	cout << endl;
}

void main()
{
	Node* pHead = nullptr;

	/*
	InsertAfter(&pHead, 1);
	InsertAfter(&pHead, 2);
	InsertAfter(&pHead, 3);
	InsertAfter(&pHead, 4);
	*/
	InsertNodeAtTail(&pHead, 1);
	InsertNodeAtTail(&pHead, 2);
	InsertNodeAtTail(&pHead, 3);
	InsertNodeAtTail(&pHead, 4);

	//DeleteNode(&pHead, 1);	// Head ���� �׽�Ʈ
	TravelseNode(pHead);

	//DeleteNode(&pHead, 2);		// �߰� ���� �׽�Ʈ
	TravelseNode(pHead);

	DeleteNode(&pHead, 4);		// tail ���� �׽�Ʈ
	TravelseNode(pHead);
}

#endif
