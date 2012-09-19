#ifdef P_4_2_NEW

/*
Problem

Solution

*/

#include "Header.h"
#include "BSTree.h"


bool FindRoute(Node* pNode, Node* pStart, Node* pEnd)
{
	deque< Node* > que;
	pStart->status = visiting;
	que.push_back(pStart);

	while (!que.empty())
	{
		Node* pTmp = que.front();
		que.pop_front();

		/*
		for (Node* pTmpNode : pTmp.getAdjNode())	// getAdjNode() 구현이 필요함
		{
			if (pTmpNode->status == unvisited)
			{
				if (pTmpNode == pEnd)
					return true;
				else
				{
					pTmpNode->status = visiting;
					que.push_back(pTmpNode);
				}
			}
		}
		*/
		
		pTmp->status = visited;
	}

	return false;
}

void main()
{
}

#endif
