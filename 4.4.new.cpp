#ifdef _4_4_NEW_

/*
Problem
	BST에서 depth 별 linked list 생성
Solution

*/

#include "Header.h"
#include "BSTree.h"

auto CreateLevelLinkedList(Node* pHead) -> list< list< Node * > >
{
	list< list< Node* > > vResultList;
	list< Node* >* liLevelList = new list< Node * >;

	liLevelList->push_back(pHead);

	while (!liLevelList->empty())
	{
		vResultList.push_back(*liLevelList);
		list< Node * >* liParentList = liLevelList;

		liLevelList = new list< Node * >;
		for (auto i = liParentList->begin(); i != liParentList->end(); ++i)
		{
			if (nullptr != (*i)->pLeft)
				liLevelList->push_back((*i)->pLeft);
			if (nullptr != (*i)->pRight)
				liLevelList->push_back((*i)->pRight);
		}
	}

	return vResultList;
}

vector< list< Node * > > LevelList(Node* pRoot)
{
	vector< list< Node * > > vResult;
	list< Node * >* liCurr = new list< Node * >();
	liCurr->push_back(pRoot);

	list< Node *>* liParent = nullptr;
	while (!liCurr->empty())
	{
		vResult.push_back(*liCurr);

		liParent = liCurr;
		liCurr = new list< Node * >();

		for (auto item : *liParent)
		{ 
			if ( nullptr != item->pLeft )
				liCurr->push_back(item->pLeft);
			if ( nullptr != item->pRight )
				liCurr->push_back(item->pRight);
		}

	}

	return vResult;
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

	//oBSTree.BFS(oBSTree.pRoot);
	//auto Result = CreateLevelLinkedList(oBSTree.pRoot);

	int i = 0;
	/*
	for (auto it = Result.begin(); it != Result.end(); ++it)
	{
		list< Node * > tmpList = *it;
		cout << "Level " << i << " : ";
		for (auto it2 = tmpList.begin(); it2 != tmpList.end(); ++it2)
			cout << (*it2)->data << " ";

		i++;
		cout << endl;
	}
	*/

	auto Result = LevelList(oBSTree.pRoot);
	for (auto it : Result )
	{
		list< Node * > tmpList = it;
		cout << "Level " << i << " : ";
		for (auto it2 : tmpList)
			cout << it2->data << " ";

		i++;
		cout << endl;
	}
}

#endif
