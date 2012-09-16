#ifdef P_2_5_NEW

/*
Problem
	1. 역순으로 digit을 정렬한 linked list 더하기
	2. 순서대로 digit을 정렬한 linked list 더하기

Solution

*/

#include "Header.h"
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

#endif
