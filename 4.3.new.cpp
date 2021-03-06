#ifdef _4_3_NEW_

/*
Problem
	sorted array 로 부터 binary search tree 생성
Solution

*/

#include "Header.h"
#include "BSTree.h"

/*
Node* BuildBSTFromArray(vector< int > vArr, Node** ppNode, int l, int u)
{
	if (l > u)
		return nullptr;

	int m = (l + u) / 2;

	if (nullptr == *ppNode)
		*ppNode = new Node(vArr[m]);

	(*ppNode)->pLeft = BuildBSTFromArray(vArr, &((*ppNode)->pLeft), l, m - 1);
	(*ppNode)->pRight = BuildBSTFromArray(vArr, &((*ppNode)->pRight), m + 1, u);

	return *ppNode;
}
*/

void BuildBST(vector< int >& vArr, Node** ppRoot, int l, int u)
{
	if (l > u)
		return;

	int m = (l + u) /2;

	*ppRoot = new Node(vArr[m]);
	BuildBST(vArr, &(*ppRoot)->pLeft, l, m - 1);
	BuildBST(vArr, &(*ppRoot)->pRight, m + 1, u);
}

void main()
{
	vector< int > vArr;
	vArr.push_back(1);
	vArr.push_back(2);
	vArr.push_back(3);
	vArr.push_back(4);
	vArr.push_back(5);

	BSTree oBSTree;

	//BuildBSTFromArray(vArr, &oBSTree.pRoot, 0, vArr.size() - 1);
	BuildBST(vArr, &oBSTree.pRoot, 0, vArr.size() - 1);

	oBSTree.Travelse();
}

#endif
