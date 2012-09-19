#ifdef P_4_4_NEW

/*
Problem
	BST에서 depth 별 linked list 생성
Solution

*/

#include "Header.h"
#include "BSTree.h"

void CreateLevelLinkedList(Node* pHead)
{
	vector< list< Node* > > vResultList;
	list< Node* > liCurrLevelList;

	pHead->status = visiting;
	deque< Node* > que;
	que.push_back(pHead);
	//liCurrLevelList.push_back(pHead);

	while (!liCurrLevelList.empty())
	{
		Node* pTmp = que.front();
		que.pop_front();

		for (int i = 0; i < 2; ++i)
		{
			Node* pTmpDescNode;
			if (0 == i)
				pTmpDescNode = pTmp->pLeft;
			else if (1 == i)
				pTmpDescNode = pTmp->pRight;

			pTmpDescNode->status = visiting;
			que.push_back(pTmpDescNode);
	//		liCurrLevelList.push_back(pTmpDescNode);
		}
	}
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

	oBSTree.BFS(oBSTree.pRoot);
}

#endif
