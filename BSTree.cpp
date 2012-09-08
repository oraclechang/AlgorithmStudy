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

void BSTree::BFS()
{
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
