#ifdef _4_1_NEW_

/*
Problem

Solution

*/

#include "Header.h"
#include "BSTree.h"

int CheckHeight(Node* pRoot)
{
	if (nullptr == pRoot)
		return 0;

	int nLeft = CheckHeight(pRoot->pLeft);
	if (-1 == nLeft)
		return -1;

	int nRight = CheckHeight(pRoot->pRight);
	if (-1 == nRight)
		return -1;

	int nHeightDiff = abs(nLeft - nRight);
	if (nHeightDiff > 1)
		return -1;
	else
		return max(nLeft, nRight) + 1;
}


bool IsBalanced(Node* pRoot)
{
	if (CheckHeight(pRoot) == -1)
		return false;
	else
		return true;
}

int CheckHeight2(Node* pRoot)
{
	if (nullptr == pRoot)
		return 0;

	int nLeft = CheckHeight2(pRoot->pLeft);
	if (-1 == nLeft)
		return -1;

	int nRight = CheckHeight2(pRoot->pRight);
	if (-1 == nRight)
		return -1;

	int nDiff = abs(nLeft - nRight);
	if (nDiff > 1)
		return -1;
	else
		return max(nLeft, nRight) + 1;
}

bool IsBalanced2(Node* pRoot)
{
	if (-1 == CheckHeight2(pRoot))
		return false;
	else
		return true;
}


void main()
{
	BSTree oBSTree;

	/*
	oBSTree.Insert(5);
	oBSTree.Insert(3);
	oBSTree.Insert(4);
	/*/
	oBSTree.Insert(2);
	oBSTree.Insert(1);
	oBSTree.Insert(3);
	oBSTree.Insert(2);
	oBSTree.Insert(1);
	oBSTree.Insert(4);
	oBSTree.Insert(5);
	//*/

	cout << (IsBalanced(oBSTree.pRoot) ? "Balanced Tree" : "Unbalanced Tree") << endl;
	cout << (IsBalanced2(oBSTree.pRoot) ? "Balanced Tree" : "Unbalanced Tree") << endl;

}

#endif
