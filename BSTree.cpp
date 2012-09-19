#ifdef _BSTREE

#include "BSTree.h"

void BSTree::Insert(const int data)
{
	doInsert(&pRoot, data);
}

void BSTree::doInsert(Node** pNode, const int data)
{
	if (nullptr == *pNode)
	{
		*pNode = new Node(data);
	}
	else
	{
		if (data < (*pNode)->data)
			doInsert(&((*pNode)->pLeft), data);
		else
			doInsert(&((*pNode)->pRight), data);
	}
}

void BSTree::BFS(Node* pHead)
{
	deque< Node* > que;
	que.push_back(pHead);

	while (!que.empty())
	{
		Node* pTmp = que.front();
		que.pop_front();

		if (nullptr != pTmp)
		{
			cout << pTmp->data << " ";
			for (int i = 0; i < 2; ++i) // adjcent nodes(left, right)
			{
				Node* pAdjNode;
				if (0 == i)
					pAdjNode = pTmp->pLeft;
				else
					pAdjNode = pTmp->pRight;

				que.push_back(pAdjNode);
			}
		}
	}
}

void BSTree::DFS()
{
}

void BSTree::Travelse()
{
	doTravelse(pRoot);
}

void BSTree::doTravelse(Node* pNode)
{
	if (nullptr == pNode)
		return;

	doTravelse(pNode->pLeft);
	cout << pNode->data << " ";
	doTravelse(pNode->pRight);
}


#endif
