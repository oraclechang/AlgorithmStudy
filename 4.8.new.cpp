#ifdef _4_8_NEW_

/*
Problem
	���� ū binary tree T1(���鸸 node) ���� T2 (��� node)�� subtree ���� �Ǵ��ϴ� �Լ�
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

bool MatchTree(Node* pNode1, Node* pNode2)
{
	if (nullptr == pNode1 && nullptr == pNode2)
		return true;
	// else �� ���� nullptr != pNode1 && nullptr != pNode2 �� ��쵵 ��⶧���� �ȵ�

	if (nullptr == pNode1 || nullptr == pNode2)
		return false;

	if (pNode1->data == pNode2->data)
		return MatchTree(pNode1->pLeft, pNode2->pLeft) && MatchTree(pNode1->pRight, pNode2->pRight);
	else
		return false;
}

bool FindMatch2(Node* pSrc, Node* pDest)
{
	if (nullptr == pSrc)
		return false;

	if (pSrc->data == pDest->data)
	{
		bool result = MatchTree(pSrc, pDest);
		if (result)
			return true;
	}

	return ( FindMatch2(pSrc->pLeft, pDest) || FindMatch2(pSrc->pRight, pDest) );
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

	cout << ( FindMatch2(oBSTree.pRoot, oBSTree2.pRoot) ? "Include" : "Not Include" ) << endl;
	
	BSTree oBSTree3;

	oBSTree3.Insert(50);
	oBSTree3.Insert(25);
	oBSTree3.Insert(75);

	cout << ( FindMatch2(oBSTree.pRoot, oBSTree3.pRoot) ? "Include" : "Not Include" ) << endl;
}

#endif
