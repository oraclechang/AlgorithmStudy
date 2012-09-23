#ifdef _5_COMMON_ANCESTOR_

/*
Problem

Solution

*/

#include "Header.h"
#include "BSTree.h"

Node* CommonAncestor(Node* pRoot, int val1, int val2)
{
	if (nullptr == pRoot)
		return nullptr;

	if ( (val1 < pRoot->data) && (pRoot->data <= val2) )
		return pRoot;

	if (val1 > pRoot->data)
		CommonAncestor(pRoot->pRight, val1, val2);
	else if (val2 <= pRoot->data)
		CommonAncestor(pRoot->pLeft, val1, val2);
}

Node* CommonAncestor_Book(Node* pRoot, int val1, int val2)
{
	while (nullptr != pRoot)
	{
		if ( (val1 > pRoot->data) && (val2 > pRoot->data) )
			pRoot = pRoot->pRight;
		else if ( (val1 < pRoot->data) && (val2 < pRoot->data) )
			pRoot = pRoot->pLeft;
		else
			return pRoot;
	}

	return nullptr;
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

	Node* pTmp = CommonAncestor(oBSTree.pRoot, 110, 175);

	cout << pTmp->data << endl;

	pTmp = CommonAncestor_Book(oBSTree.pRoot, 110, 175);

	cout << pTmp->data << endl;
}

#endif
