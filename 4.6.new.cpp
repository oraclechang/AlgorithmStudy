#ifdef _4_6_NEW_

/*
Problem
	BST에서 next node를 찾는 함수 작성. parent node로 의 link
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
