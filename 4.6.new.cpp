#ifdef _4_6_NEW_

/*
Problem
	BST���� next node�� ã�� �Լ� �ۼ�. parent node�� �� link
Solution

*/

#include "Header.h"
#include "BSTree.h"

Node* GetLeftMost(Node* pNode)
{
	if (nullptr == pNode)
		return nullptr;

	while (nullptr != pNode->pLeft)
		pNode = pNode->pLeft;

	return pNode;
}

/*
Node* NextNode(Node* pRoot)
{
	if (nullptr == pRoot)
		return nullptr;

	if ( (nullptr == pRoot->pParent) || nullptr != pRoot->pRight)
		return GetLeftMost(pRoot->pRight);
	else
	{
		Node* q = pRoot;
		Node* x = q->pParent;
		while (nullptr != x && q == x->pRight)
		{
			q = x;
			x = x->pParent;
		}

		return q;
	}
}
*/

void main()
{
}

#endif
