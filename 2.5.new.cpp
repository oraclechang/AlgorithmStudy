#ifdef _2_5_NEW_

/*
Problem
	1. 역순으로 digit을 정렬한 linked list 더하기
	2. 순서대로 digit을 정렬한 linked list 더하기

Solution

*/

#include "Header.h"
/*
#include "LinkedList_shared_ptr.h"

template< typename T >
shared_ptr< Node< T > > AddLists(shared_ptr< Node < T > > pFirst, shared_ptr< Node < T > > pSecond)
{
	shared_ptr< Node< T > > pResult;
	int nFirstData = 0;
	int nSecondData = 0;
	int nCarry = 0;

	while(nullptr != pFirst || nullptr != pSecond)
	{
		if (nullptr != pFirst)
			nFirstData = pFirst->data;
		else
			nFirstData = 0;

		if (nullptr != pSecond)
			nSecondData = pSecond->data;
		else
			nSecondData = 0;

		int nResult = (nFirstData + nSecondData + nCarry) % 10;
		nCarry = (nFirstData + nSecondData + nCarry) / 10;

		//InsertNodeAtAfter(&pResult, nResult);
		InsertNodeAtTail(&pResult, nResult);

		if (nullptr != pFirst) pFirst = pFirst->pNext;
		if (nullptr != pSecond) pSecond = pSecond->pNext;
	}

	return pResult;
}


void main()
{
	shared_ptr< Node< int > > pFirst;
	shared_ptr< Node< int > > pSecond;

	InsertNodeAtTail(&pFirst, 1);
	InsertNodeAtTail(&pFirst, 2);
	InsertNodeAtTail(&pFirst, 3);
	InsertNodeAtTail(&pFirst, 4);
	InsertNodeAtTail(&pFirst, 5);

	InsertNodeAtTail(&pSecond, 4);
	InsertNodeAtTail(&pSecond, 5);
	InsertNodeAtTail(&pSecond, 9);
	InsertNodeAtTail(&pSecond, 8);
	//InsertNodeAtTail(&pSecond, 3);

	auto pResult = AddLists(pFirst, pSecond);

	TravelseNode(pResult);
}

*/

#include "LinkedList3.h"

Node* ListSum(Node* pFirst, Node* pSecond)
{
	if (nullptr == pFirst && nullptr == pSecond)
		return nullptr;

	int nSum = 0;
	int nCarry = 0;
	Node* pResult = nullptr;

	while(nullptr != pFirst && nullptr != pSecond)
	{
		nSum = (pFirst->data + pSecond->data + nCarry) % 10;
		nCarry = (pFirst->data + pSecond->data + nCarry) / 10;
		
		Insert(&pResult, nSum);

		pFirst = pFirst->pNext;
		pSecond = pSecond->pNext;
	}

	Node* pRemain = ( (nullptr != pFirst) ? pFirst : pSecond );
	while (nullptr != pRemain)
	{
		Insert(&pResult, pRemain->data);
		pRemain = pRemain->pNext;
	}

	return pResult;
}

int CountNode(Node* pNode)
{
	int nCnt = 0;
	while (nullptr != pNode)
	{
		++nCnt;
		pNode = pNode->pNext;
	}

	return nCnt;
}

void PadNode(Node** pNode, int nPadCnt)
{
	for (int i = 0; i < nPadCnt; ++i)
		InsertBefore(pNode, 0);
}

Node* ListSum2(Node* pFirst, Node* pSecond)
{
	int nFirstNodeCnt = CountNode(pFirst);
	int nSecondNodeCnt = CountNode(pSecond);

	int nDiff = nFirstNodeCnt - nSecondNodeCnt; 
	if (nDiff > 0)
		PadNode(&pSecond, nDiff);
	else if (nDiff < 0)
		PadNode(&pFirst, nDiff * -1);

	int nSum = 0;
	Node* pResult = nullptr;
	if ( ( (pFirst->data + pSecond->data) / 10) == 1 )	// First carry
		Insert(&pResult, 1);

	while (nullptr != pFirst)			// pFirst and pSecond have same length
	{
		int nCarry = 0;
		if (nullptr != pFirst->pNext)	// pFirst and pSecond have same length
			nCarry = (pFirst->pNext->data + pSecond->pNext->data) / 10;

		nSum = (pFirst->data + pSecond->data + nCarry) % 10;
		Insert(&pResult, nSum);

		pFirst = pFirst->pNext;
		pSecond= pSecond->pNext;
	}

	return pResult;
}

void main()
{
	Node* pFirst = nullptr;
	Insert(&pFirst, 9);
	Insert(&pFirst, 2);
	Insert(&pFirst, 3);

	Node* pSecond = nullptr;
	Insert(&pSecond, 4);
	Insert(&pSecond, 5);
	Insert(&pSecond, 6);

	//auto pResult = ListSum(pFirst, pSecond);
	auto pResult = ListSum2(pFirst, pSecond);

	while (nullptr != pResult)
	{
		cout << pResult->data << " ";
		pResult = pResult->pNext;
	}
}

#endif
