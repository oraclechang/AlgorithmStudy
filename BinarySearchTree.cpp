#ifdef P_4
#include <iostream>
//#include <algorithm>

using namespace std;

template< typename T >
struct stTreeNode
{
	T				data;
	stTreeNode*		pLeft;
	stTreeNode*		pRight;

	stTreeNode(T x) : data(x), pLeft(nullptr), pRight(nullptr) {}
};

template< typename T >
class tree
{
public:
	tree();
	tree< T >*	Search_Tree(tree< T >*, T);
	tree< T >*	Find_min(tree< T >*, T); 
	void		InOrder(tree< T >*);
	void		Insert_Tree_Iterative(T);
	void		Insert_Tree_Recursive(T);
	void		Insert_Tree_Recursive_Internal(stTreeNode< T >*, T);
	int			GetMinDepth(stTreeNode< T >*);
	int			GetMaxDepth(stTreeNode< T >*);
	bool		IsBalanced();

private:
	stTreeNode< T >* m_pRoot;
};

template< typename T >
tree< T >::tree()
{
	m_pRoot = nullptr;
}

template< typename T >
tree< T >* tree< T >::Search_Tree(tree< T >* pTree, T data)
{
	if (nullptr == pTree)
		return nullptr;

	if (pTree->item == data)
		return pTree;

	if (pTree->item < data)
		return Search_Tree(pTree->pLeft, data);
	else
		return Search_Tree(pTree->pRight, data);

}

template< typename T >
tree< T >* tree< T >::Find_min(tree< T >* pTree, T data)
{
	if (nullptr == pTree)
		return nullptr;

	tree< T >* pMin = pTree;

	while(nullptr != pMin->pLeft)
		pMin = pMin->pLeft;

	return pMin;
}

template< typename T >
void tree< T >::InOrder(tree< T >* pTree)
{
	if (nullptr != pTree)
	{
		InOrder(pTree->pLeft);
		cout << pTree->item;
		InOrder(pTree->pRight);
	}
}

template< typename T >
void tree< T >::Insert_Tree_Iterative(T data)
{
	stTreeNode< T >* pTmp		= new stTreeNode< T >(data);

	if (nullptr == m_pRoot)
	{
		m_pRoot = pTmp;
		return;
	}
	else
	{
		stTreeNode< T >* pCurNode = m_pRoot;
		while(nullptr != pCurNode)
		{
			if (pCurNode->data == data)		// Same value
				return;
			else if (data < pCurNode->data)	// Left insert
			{
				if (nullptr == pCurNode->pLeft)	// No left child
				{
					pCurNode->pLeft = pTmp;
					return;
				}
				else	// Left child is exist
					pCurNode = pCurNode->pLeft;
			}
			else	// Right insert
			{
				if (nullptr == pCurNode->pRight)	// No right child
				{
					pCurNode->pRight = pTmp;
					return;
				}
				else	// right child is exist
					pCurNode = pCurNode->pRight;
			}
		}
	}
}

template< typename T >
void tree< T >::Insert_Tree_Recursive(T data)
{
	Insert_Tree_Recursive_Internal(m_pRoot, data);
}

template< typename T >
void tree< T >::Insert_Tree_Recursive_Internal(stTreeNode< T >* pCurNode, T data)
{
	if (nullptr == m_pRoot)
	{
		m_pRoot = new stTreeNode< T >(data);
		return;
	}
	else
	{
		if (data == pCurNode->data)
			return;
		else if (data < pCurNode->data)		// Left child node insert
		{
			if (nullptr == pCurNode->pLeft)	// Left child exists
			{
				pCurNode->pLeft = new stTreeNode< T >(data);
				return;
			}
			else
				Insert_Tree_Recursive_Internal(pCurNode->pLeft, data);
		}
		else 		// Right child node insert
		{
			if (nullptr == pCurNode->pRight)	// Right child exists
			{
				pCurNode->pRight = new stTreeNode< T >(data);
				return;
			}
			else
				Insert_Tree_Recursive_Internal(pCurNode->pRight, data);
		}
	}
}

template< typename T >
int tree< T >::GetMinDepth(stTreeNode< T >* pCurNode)
{
	if (nullptr == pCurNode)
		return 0;

	return 1 + min(GetMinDepth(pCurNode->pLeft), GetMinDepth(pCurNode->pRight));
}

template< typename T >
int tree< T >::GetMaxDepth(stTreeNode< T >* pCurNode)
{
	if (nullptr == pCurNode)
		return 0;

	return 1 + max(GetMaxDepth(pCurNode->pLeft), GetMaxDepth(pCurNode->pRight));
}

template< typename T >
bool tree< T >::IsBalanced()
{
	stTreeNode< T >* pTmp = m_pRoot;
	return ((GetMaxDepth(pTmp)) - (GetMinDepth(pTmp)) <= 1);
}


#endif