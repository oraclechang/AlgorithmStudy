#ifdef _4_7_NEW_

/*
Problem
	binary tree 에서 두 node 의 첫 공통 조상을 찾는 함수
Solution

*/

#include "Header.h"
#include "BSTree.h"

bool CheckNode(Node* pRoot, Node* pTarget)
{
	if (nullptr == pRoot)
		return false;

	if (pRoot == pTarget)
		return true;

	return ( CheckNode(pRoot->pLeft, pTarget) || CheckNode(pRoot->pRight, pTarget) );
}

Node* CommonAncestor(Node* pRoot, Node* pNode1, Node* pNode2)
{
	if (nullptr == pRoot)
		return nullptr;

	bool b1ExistLeft = CheckNode(pRoot->pLeft, pNode1);
	bool b2ExistLeft = CheckNode(pRoot->pLeft, pNode2);

	if (b1ExistLeft != b2ExistLeft)
		return pRoot;
	else if (b1ExistLeft)
		return CommonAncestor(pRoot->pLeft, pNode1, pNode2);
	else
		return CommonAncestor(pRoot->pRight, pNode1, pNode2);
}

bool IsNodeExist(Node* pNode, Node* pTarget)
{
	if (nullptr == pNode)
		return false;

	if (pTarget == pNode)
		return true;

	return ( IsNodeExist(pNode->pLeft, pTarget) || IsNodeExist(pNode->pRight, pTarget) );
}

Node* CommonAncestor2(Node* pRoot, Node* pNodeA, Node* pNodeB)
{
	if (nullptr == pRoot)
		return nullptr;

	bool bAExistLeft = IsNodeExist(pRoot->pLeft, pNodeA);
	bool bBExistLeft = IsNodeExist(pRoot->pLeft, pNodeB);

	if (bAExistLeft != bBExistLeft)
		return pRoot;
	else
	{
		if (bAExistLeft)
			return CommonAncestor2(pRoot->pLeft, pNodeA, pNodeB);
		else
			return CommonAncestor2(pRoot->pRight, pNodeA, pNodeB);
	}
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
	Node* pNode2 = oBSTree.Insert(175);
	Node* pNode1 = oBSTree.Insert(110);

	//Node* pTmp = CommonAncestor(oBSTree.pRoot, pNode1, pNode2);
	Node* pTmp = CommonAncestor2(oBSTree.pRoot, pNode1, pNode2);

	cout << pTmp->data << endl;

	/*
	pTmp = CommonAncestor_Book(oBSTree.pRoot, 110, 175);

	cout << pTmp->data << endl;
	*/

}

#endif
