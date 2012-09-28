#ifdef _13_8_NEW_

/*
Problem

Solution

*/

#include "Header.h"

template< typename T >
class SmartPtr
{
public:
	SmartPtr(T* ptr)
	{
		pRef = ptr;
		pRefCnt = new int(1);
	}

	~SmartPtr()
	{
			remove();
	}

	SmartPtr< T >& operator=(SmartPtr< T >& sPtr)
	{
		if (this == &sPtr)
			return *this;

		if (0 < *pRefCnt)
			remove();

		pRef = sPtr.pRef;
		pRefCnt = sPtr.pRefCnt;
		++(*pRefCnt);

		return *this;
	}

private:
	void remove()
	{
		--(*pRefCnt);
		if (0 == *pRefCnt)
		{
			delete pRef;
			delete pRefCnt;
			pRef = nullptr;
			pRefCnt = nullptr;
		}
	}


	T*		pRef;
	int*	pRefCnt;
};


void main()
{
	SmartPtr< int > spTmp(new int(5));
	//SmartPtr< int > spTmp2 = spTmp;
	auto spTmp2 = spTmp;

}

#endif
