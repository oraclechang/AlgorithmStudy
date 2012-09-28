#ifdef _13_7_NEW_

/*
Problem

Solution

*/

#include "Header.h"
#include "BSTree.h"

void CopyTree(Node* pSrc, Node** pDest)
{
	if (nullptr == pSrc)
		return;

	*pDest = new Node(pSrc->data);

	if (nullptr != pSrc->pLeft)
		CopyTree(pSrc->pLeft, &(*pDest)->pLeft);

	if (nullptr != pSrc->pRight)
		CopyTree(pSrc->pRight, &(*pDest)->pRight);
}

void BFS(Node* pRoot)
{
	deque< Node * > que;
	pRoot->status = visiting;
	que.push_back(pRoot);

	while (!que.empty())
	{
		Node* pNode = que.front(); que.pop_front();
		if (nullptr != pNode)
		{
			cout << pNode->data << " ";
			for (int i = 0; i < 2; ++i)
			{
				if (0 == i)
				{
					pNode->status = visiting;
					que.push_back(pNode->pLeft);
				}
				if (1 == i)
				{
					pNode->status = visiting;
					que.push_back(pNode->pRight);
				}
			}
		
			pNode->status = visited;
		}
	}
}

void main()
{
	BSTree oBSTree;
	oBSTree.Insert( 10 );
	oBSTree.Insert( 5 );
	oBSTree.Insert( 15 );
	oBSTree.Insert( 1 );
	BFS(oBSTree.pRoot);

	Node* pDest = nullptr;

	CopyTree(oBSTree.pRoot, &pDest);
	cout << endl;
	BFS(pDest);
}

#endif
