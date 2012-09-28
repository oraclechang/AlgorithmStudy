#ifdef _2_1_NEW_

/*
Problem

Solution

*/

#include "Header.h"

struct Node
{
	int data;
	Node* pNext;
	Node(int _data) : data(_data), pNext(nullptr) {}
};

void Insert(Node** pHead, int data)
{
	Node* pNewNode = new Node(data);
	
	if (nullptr == *pHead)
		*pHead = pNewNode;
	else
	{
		Node* pCur = *pHead;
		while (nullptr != pCur->pNext)	// 중요
			pCur = pCur->pNext;

		pCur->pNext = pNewNode;
	}
}

void DeleteDupHash(Node** pHead)
{
	if (nullptr == *pHead || nullptr == (*pHead)->pNext)
		return;

	set< int > setHash;
	Node* pPrev = nullptr;
	Node* pCur = *pHead;

	while (nullptr != pCur)	// 중요
	{ 
		auto result = setHash.insert(pCur->data);
		if (false == result.second)
		{
			Node* pRemove = pCur;
			pPrev->pNext = pCur->pNext;
			pCur = pCur->pNext;

			delete pRemove;
		}
		else
		{
			pPrev = pCur;
			pCur = pCur->pNext;
		}
	}
}

void DeleteDupNoHash(Node** pHead)
{
	if (nullptr == *pHead || nullptr == (*pHead)->pNext)
		return;

	Node* pCur = *pHead;
	Node* pRun = pCur->pNext;

	while (nullptr != pCur)
	{
		while (nullptr != pRun)
		{
			if (pCur->data == pRun->data)
			{
				Node* pTmp = pRun;
				pCur->pNext = pRun->pNext;
				pRun = pRun->pNext;
				delete pTmp;
			}
			else
			{
				pCur = pRun;
				pRun = pRun->pNext;
			}
		}
		
		pCur = pCur->pNext;
	}
}


void PrintNode(Node* pHead)
{
	while (nullptr != pHead)
	{
		cout << pHead->data << " ";
		pHead = pHead->pNext;
	}
	cout << endl;
}


void main()
{
	Node* pHead = nullptr;
	Insert(&pHead, 1);	
	Insert(&pHead, 1);	
	Insert(&pHead, 2);	

	PrintNode(pHead);
	//DeleteDupHash(&pHead);
	DeleteDupNoHash(&pHead);

	PrintNode(pHead);
}

#endif
