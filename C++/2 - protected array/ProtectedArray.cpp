#include "ProtectedArray.h"

/*
	Constructor. 

	INPUT:
		size - the size of the array to allocate.

	OUTPUT:
		None.
*/
template <class T>
ProtectedArray<T>::ProtectedArray(int size)
{
	this->_array = new T[size];
	this->_capacity = size;
	this->_size = size;
	this->_index = 0;
}

/*
	Copy constructor.

	INPUT:
		other - ProtectedArray to copy.

	OUTPUT:
		None.
*/
template <class T>
ProtectedArray<T>::ProtectedArray(ProtectedArray<T> &other)
{
	//We won't 'deep' copy the array because we want it to behave just like a normal array.
	this->_array = other._array;

	this->_capacity = other._capacity;
	this->_index = other._index;
	this->_size = other._size;
}

/*
	Destructor:

	INPUT:
		None.

	OUTPUT:
		None.
*/
template <class T>
ProtectedArray<T>::~ProtectedArray<T>()
{
	delete[this->_array];
}

/*
	getCapacity:
		This method return the aloocated size of the array.

	INPUT:
		None.

	OUTPUT:
		int - the allocated size of the array.
*/
template <class T>
int ProtectedArray<T>::getCapacity() const
{
	return this->_capacity;
}

/*
	getSize:
		This method return the size of the array.

	INPUT:
		None.

	OUTPUT:
		int - the size.
*/
template <class T>
int ProtectedArray<T>::getSize() const
{
	return this->_size;
}

/*
	operator[]:

	INPUT:
		index - index of element from the array to return.

	OUTPUT:
		T - reference to the element.
*/
template <class T>
T& ProtectedArray<T>::operator[](const int index) throw std::string
{
	if (index > )
}

/*
	operator*:
	
	INPUT:
		None.

	OUTPUT:
		T - referance to the first element in the array.
*/
template <calss T>
T& ProtectedArray<T>::operator*()
{

}

/*
	operator++:

	INPUT:
		None.

	OUTPUT:
		Referance to the current object (array is + 1).
*/
template <class T>
ProtectedArray<t>& ProtectedArray<T>::operator++()
{

}