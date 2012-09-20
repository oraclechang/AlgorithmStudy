#ifdef P_4_4_NEW

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
			else if (nullptr != (*i)->pRight)
				liLevelList->push_back((*i)->pRight);
		}

	}

	return vResultList;
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
	auto Result = CreateLevelLinkedList(oBSTree.pRoot);

	int i = 0;
	for (auto it = Result.begin(); it != Result.end(); ++it)
	{
		list< Node * > tmpList = *it;
		cout << "Level " << i << " : ";
		for (auto it2 = tmpList.begin(); it2 != tmpList.end(); ++it2)
			cout << (*it2)->data << " ";

		i++;
		cout << endl;
	}
}

#endif
