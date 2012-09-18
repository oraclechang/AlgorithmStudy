#ifdef _STACK_LINKEDLIST_

#include "Header.h"

template< typename T >
struct Node
{
	shared_ptr< Node< T > > pNext;
	//Node* pNext;
	T data;

	Node (T _data) : data(_data), pNext(nullptr) {}
};

template< typename T >
shared_ptr< Node< T > > StackPop(shared_ptr< Node< T > >* pTop)
{
	shared_ptr< Node< T > > pTmp = *pTop;
	*pTop = (*pTop)->pNext;

	return pTmp;
}

template< typename T >
void StackPush(shared_ptr< Node< T > >* pTop, T data)
{
	shared_ptr< Node< T > > pNewNode(new Node< T >(data));

	if (nullptr == *pTop)
		*pTop = pNewNode;
	else
	{
		pNewNode->pNext = *pTop;
		*pTop = pNewNode;
	}
}

template< typename T >
void StackPushWithMin(shared_ptr< Node< T > >* pTop, 
					  shared_ptr< Node< T > >* pMinStack,
					  T data)
{
	shared_ptr< Node< T > > pNewNode(new Node< T >(data));

	if (nullptr == *pTop)
		*pTop = pNewNode;
	else
	{
		pNewNode->pNext = *pTop;
		*pTop = pNewNode;
	}

	if (data < StackPeek(pMinStack))
		StackPush(pMinStack, data);
}

template< typename T >
T StackPeek(shared_ptr< Node < T > > pTop)
{
	return pTop->data;
}

#endif