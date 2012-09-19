#ifdef _BSTREE

#include "Header.h"

typedef enum {unvisited, visiting, visited} eNodeStatus;

struct Node
{
	Node* pLeft;
	Node* pRight;
	int data;
	eNodeStatus status;
	
	Node(int _data) : data(_data), pLeft(nullptr), pRight(nullptr) {}
};
	
class BSTree
{
public:
	BSTree() {pRoot = nullptr;}
	void Insert(int);
	void doInsert(Node**, const int);
	void Delete();
	void DFS();
	void BFS(Node*);
	void Search();
	void Travelse();
	void doTravelse(Node*);

	Node* pRoot;
private:
};

#endif
