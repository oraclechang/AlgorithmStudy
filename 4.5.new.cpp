#ifdef P_4_5_NEW

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
}

#endif
