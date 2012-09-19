#ifdef P_3_7_NEW

/*
Problem
	dog, cat °ü¸® queue
Solution

*/

#include "Header.h"

class animal
{
public:
	animal(int _ID) { ID = _ID; }
	int getValue() { return ID; }
private:
	int ID;
};

class dog : public animal
{
public:
	dog(int ID) : animal(ID) {}
};

class cat : public animal
{
public:
	cat(int ID) : animal(ID) {}
};

class shelter
{
public:
	void Enqueue(animal*);
	animal* DequeueAny();
	animal* DequeueDog();
	animal* DequeueCat();
private:
	list< dog* > liDog;
	list< cat* > liCat;
};

void shelter::Enqueue(animal* oAnimal)
{
	if (typeid(*oAnimal) == typeid(dog))
		liDog.push_back((dog*)oAnimal);
	else if (typeid(*oAnimal) == typeid(cat))
		liCat.push_back((cat*)oAnimal);
	else
	{
		cout << "typeid(oAnimal).name() : " << typeid(oAnimal).name() << endl;
		cout << "typeid(*oAnimal).name() : " << typeid(*oAnimal).name() << endl;
		cout << "typeid(dog).name() : " << typeid(dog).name() << endl;
	}
}

animal* shelter::DequeueAny()
{
	animal* nDogValue = liDog.front();
	animal* nCatValue = liCat.front();

	if (nDogValue->getValue() < nCatValue->getValue())
	{
		liDog.pop_front();
		return (animal*)nDogValue;
	}
	else
	{
		liCat.pop_front();
		return (animal*)nCatValue;
	}
}

animal* shelter::DequeueDog()
{
	animal* pDog = liDog.front();
	liDog.pop_front();
	return (animal*)pDog;
}

animal* shelter::DequeueCat()
{
	animal* pCat = liCat.front();
	liCat.pop_front();
	return (animal*)pCat;
}

void main()
{
	shelter oShelter;

	oShelter.Enqueue(new dog(1));
	oShelter.Enqueue(new cat(2));
	oShelter.Enqueue(new dog(3));
	oShelter.Enqueue(new cat(4));
	oShelter.Enqueue(new cat(5));

	auto Result = oShelter.DequeueAny();
	cout << Result->getValue() << endl;
}

#endif
