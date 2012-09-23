#ifdef _4_9_NEW_

/*
Problem

Solution

*/

#include "Header.h"
#include "BSTree.h"

int TreeDepth(Node* pRoot)
{
	if (nullptr == pRoot)
		return 0;
	else
		return 1 + max(TreeDepth(pRoot->pLeft), TreeDepth(pRoot->pRight));
}

void PrintResult(vector< int >& path, int start, int end)
{
	for (int i = start; i <= end; ++i)
		cout << path[i] << " ";

	cout << endl;
}

void FindSum(Node* pNode, vector< int >& path, int nTargetSum, int nLevel)
{
	if (nullptr == pNode)
		return;

	path[nLevel] = pNode->data;

	int nSum = 0;
	for (int i = nLevel; i >= 0; --i)
	{
		nSum += path[i]; 
		if (nSum == nTargetSum)
			PrintResult(path, i, nLevel);
	}

	FindSum(pNode->pLeft, path, nTargetSum, nLevel + 1);
	FindSum(pNode->pRight, path, nTargetSum, nLevel + 1);
}


void FindSum(Node* pNode, int nTargetSum)
{
	int nDepth = TreeDepth(pNode);
	vector< int > path(nDepth, 0);

	FindSum(pNode, path, nTargetSum, 0);
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

	FindSum(oBSTree.pRoot, 75);
}

#endif
