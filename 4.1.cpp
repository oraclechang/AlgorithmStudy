#ifdef P_4_1

/*
Problem
	Implement a function to check if a tree is balanced  
	For the purposes of this question, 
	a balanced tree is defined to be a tree such that no two leaf nodes differ in distance from the root by more than one 

Solution
	The  idea  is  very  simple:  the  difference  of  min  depth  and  max  depth  should  not  exceed  1, 
	since the difference of the min and the max depth is the maximum distance difference pos-sible in the tree 

	public static int maxDepth(TreeNode root) {
		if (root == null) {
			return 0;
		}
		return 1 + Math.max(maxDepth(root.left), maxDepth(root.right));
	}

	public static int minDepth(TreeNode root) {
		if (root == null) {
			return 0;
		}
		return 1 + Math.min(minDepth(root.left), minDepth(root.right));
	}

	public static boolean isBalanced(TreeNode root){
		return (maxDepth(root) - minDepth(root) <= 1);
	}
*/

#include "Header.h"
#include "BSTree.h"

bool doCheckBalance(Node* pNode, int nLevel, int& nMaxDepth)
{
	if (nullptr == pNode)
	{
		if (nMaxDepth < nLevel)
			nMaxDepth = nLevel;

		if (nMaxDepth > nLevel + 1)
			return false;
		else
			return true;
	}
	else
	{
		return (doCheckBalance(pNode->pLeft, nLevel + 1, nMaxDepth) && doCheckBalance(pNode->pRight, nLevel + 1, nMaxDepth));
	}
}

bool CheckBalance(Node* pNode)
{
	int nMaxDepth = 0;
	
	return doCheckBalance(pNode, 0, nMaxDepth);
}

int MinDepth(Node* pNode)
{
	if (nullptr == pNode)
		return 0;

	return 1 + min(MinDepth(pNode->pLeft), MinDepth(pNode->pRight));
}

int MaxDepth(Node* pNode)
{
	if (nullptr == pNode)
		return 0;

	return 1 + max(MaxDepth(pNode->pLeft), MaxDepth(pNode->pRight));
}

bool IsBalanced(Node* pNode)
{
	int nMaxDepth = MaxDepth(pNode);
	int nMinDepth = MinDepth(pNode);
	return (nMaxDepth - nMinDepth) <= 1;
}


void main()
{
	BSTree oBSTree;

	//*
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

	//cout << (CheckBalance(oBSTree.pRoot) ? "Balanced Tree" : "Unbalanced Tree") << endl;
	cout << (IsBalanced(oBSTree.pRoot) ? "Balanced Tree" : "Unbalanced Tree") << endl;


	oBSTree.Insert(3);
	//cout << (CheckBalance(oBSTree.pRoot) ? "Balanced Tree" : "Unbalanced Tree") << endl;
	cout << (IsBalanced(oBSTree.pRoot) ? "Balanced Tree" : "Unbalanced Tree") << endl;
}

#endif