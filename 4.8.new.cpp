#ifdef _4_8_NEW_

/*
Problem
	아주 큰 binary tree T1(수백만 node) 에서 T2 (몇백 node)가 subtree 인지 판단하는 함수
Solution

*/

#include "Header.h"
#include "BSTree.h"

bool IsSameTree(Node* pRoot1, Node* pRoot2)
{
	if (nullptr == pRoot1 && nullptr == pRoot2)
		return true;

	if (nullptr == pRoot1 || nullptr == pRoot2)
		return false;

	if (pRoot1->data == pRoot2->data)
	{
		return IsSameTree(pRoot1->pLeft, pRoot2->pLeft) &&
			IsSameTree(pRoot1->pRight, pRoot2->pRight);
	}
	else
		return false;
}

bool FindMatch(Node* pRoot1, Node* pRoot2)
{
	if (nullptr == pRoot1)
		return false;

	if (pRoot1->data == pRoot2->data)
		if (IsSameTree(pRoot1, pRoot2))
			return true;

		return ( FindMatch(pRoot1->pLeft, pRoot2) || 
			 FindMatch(pRoot1->pRight, pRoot2) );
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

	BSTree oBSTree2;

	oBSTree2.Insert(100);
	oBSTree2.Insert(50);
	oBSTree2.Insert(150);

	cout << ( FindMatch(oBSTree.pRoot, oBSTree2.pRoot) ? "Include" : "Not Include" ) << endl;
	
	BSTree oBSTree3;

	oBSTree3.Insert(50);
	oBSTree3.Insert(25);
	oBSTree3.Insert(75);

	cout << ( FindMatch(oBSTree.pRoot, oBSTree3.pRoot) ? "Include" : "Not Include" ) << endl;
}

#endif
