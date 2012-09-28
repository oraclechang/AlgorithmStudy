#ifdef _4_5_NEW_

/*
Problem
	binary tree 가 binary search tree 인지를 판단하는 함수 작성
Solution

*/

#include "Header.h"
#include "BSTree.h"

bool BSTCheck(Node* pRoot, int& nLastData)
{
	if (nullptr == pRoot)
		return true;

	if (!BSTCheck(pRoot->pLeft, nLastData))
		return false;

	if (pRoot->data > nLastData)
	{
		nLastData = pRoot->data;
		return true;
	}

	if (!BSTCheck(pRoot->pRight, nLastData))
		return false;

	return true;
}

bool MyCheckBST(Node* pRoot)
{
	if (nullptr == pRoot)
		return true;

	int nLeftData = 0;
	int nRightData = 0;
	int nRootData = pRoot->data;

	if (nullptr == pRoot->pLeft)
		nLeftData = numeric_limits< int >::min();
	else
		nLeftData = pRoot->pLeft->data;

	if (nullptr == pRoot->pRight)
		nRightData = numeric_limits< int >::max();
	else
		nRightData = pRoot->pRight->data;

	if ( !(nLeftData < nRootData && nRootData <= nRightData) )
		return false;
	else
		return ( MyCheckBST(pRoot->pLeft) && MyCheckBST(pRoot->pRight) );
}

void main()
{
	BSTree oBSTree;

	oBSTree.Insert(2);
	oBSTree.Insert(1);
	oBSTree.Insert(3);
	oBSTree.Insert(2);
	oBSTree.Insert(1);
	oBSTree.Insert(4);
	oBSTree.Insert(5);

	int nLastData = -100;
	cout << (BSTCheck(oBSTree.pRoot, nLastData) ? "BST" : "Not BST") << endl;

	cout << (MyCheckBST(oBSTree.pRoot) ? "BST" : "Not BST") << endl;
}

#endif
