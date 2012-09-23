#ifdef _5_PREORDER_TRAVELSE_

/*
Problem
	1. 재귀를 쓰는 preorder travelse
	2. 재귀를 쓰지 않는 preorder travelse
Solution

*/

#include "Header.h"
#include "BSTree.h"

void PreOrderTravelse_Recurse(Node* pRoot)
{
	if (nullptr == pRoot)
		return;
	cout << pRoot->data << " ";
	PreOrderTravelse_Recurse(pRoot->pLeft);
	PreOrderTravelse_Recurse(pRoot->pRight);
}

void PreOrderTravelse_Iter(Node* pRoot)
{
	stack< Node* > stk;
	while (nullptr != pRoot)
	{
		cout << pRoot->data << " ";
		if (nullptr != pRoot->pRight)
			stk.push(pRoot->pRight);

		if (nullptr != pRoot->pLeft)
		{
			pRoot = pRoot->pLeft;
			continue;
		}

		if (nullptr == pRoot->pLeft && nullptr == pRoot->pRight)
		{
			if (stk.empty())
				break;
			pRoot = stk.top();
			stk.pop();
		}
	}
}

void PreOrderTravelse_Book(Node* pRoot)
{
	stack< Node * > stk;
	stk.push(pRoot);

	while (!stk.empty())
	{
		Node* pTmp = stk.top();
		stk.pop();

		cout << pTmp->data << " ";

		if (nullptr != pTmp->pRight)
			stk.push(pTmp->pRight);

		if (nullptr != pTmp->pLeft)
			stk.push(pTmp->pLeft);
	}
}


void main()
{
	BSTree oBSTree;

	oBSTree.Insert(100);
	oBSTree.Insert(50);
	oBSTree.Insert(150);
	oBSTree.Insert(25);
	oBSTree.Insert(75);
	oBSTree.Insert(125);
	oBSTree.Insert(175);
	oBSTree.Insert(110);

	PreOrderTravelse_Recurse(oBSTree.pRoot);

	cout << endl;

	PreOrderTravelse_Iter(oBSTree.pRoot);
	
	cout << endl;

	PreOrderTravelse_Book(oBSTree.pRoot);
}

#endif
