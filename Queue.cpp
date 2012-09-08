#ifdef QUEUE

#include <iostream>

using namespace std;

template< typename T >
struct Node
{
	Node*	pNext;
	T		data;

	//Node(T) : data(T){}

	/*
	Node& operator=(const Node* rhs) 
	{ 
		pNext = rhs->pNext; 
		return *this;
	}
	*/
};

template< typename T >
class Queue_List
{
public:
	Queue_List();
	void	Enqueue(T);
	T		Dequeue();	
	
private:
	Node< T >*	pFront;
	Node< T >*	pEnd;

};

template< typename T >
Queue_List< T >::Queue_List()
{
	pFront	= nullptr;
	pEnd	= nullptr;
}

template< typename T >
void Queue_List< T >::Enqueue(T data)
{
	if (NULL == pFront)
	{
		pFront = new Node < T >();
		pFront->data = data;
		pFront->pNext = nullptr;

		pEnd = pFront;
	}
	else
	{
		//pEnd->pNext = new Node< T >();
		Node< T >* pNewNode = new Node< T >();
		pNewNode->data = data;
		pNewNode->pNext = nullptr;

		pEnd->pNext = pNewNode;
		pEnd = pNewNode;
	}
}

template< typename T >
T Queue_List< T >::Dequeue()
{
	if (NULL != pFront)
	{
		Node< T >* pTmp = pFront;
		T data = pFront->data;
		pFront = pFront->pNext;
		delete pTmp;

		return data;
	}

	return -1;
}


int main()
{
	Queue_List< int > oQueue;

	oQueue.Enqueue(1);
	oQueue.Enqueue(2);
	oQueue.Enqueue(3);
	oQueue.Enqueue(4);
	oQueue.Enqueue(5);

	cout << oQueue.Dequeue() << endl;
	cout << oQueue.Dequeue() << endl;
	cout << oQueue.Dequeue() << endl;
	cout << oQueue.Dequeue() << endl;
	cout << oQueue.Dequeue() << endl;

	return 0;
}

#endif