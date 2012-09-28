struct Node
{
	int data;
	Node* pNext;
	Node(int _data) : data(_data), pNext(nullptr) {}
};

void Insert(Node**, int);
void InsertBefore(Node**, int);