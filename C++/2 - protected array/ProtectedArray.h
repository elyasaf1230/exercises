#pragma once

#include <iostream>
#include <exception>
#include <string>

const int ioor_i = 1;
const std::string ioor_s = "Index out of range!";

template <class T>
class ProtectedArray
{
private:
	T *_array;

	int _capacity;	//(real) size of the array in memory.
	int _size;		//size of the array.
	int _index;		//first element in array (for operator++)

	int* _count;		//this will idicates how much objects have the same array.

	ProtectedArray<T>& precedeArray(const int offset);

public:
	//constructors:
	ProtectedArray(int size);
	ProtectedArray(ProtectedArray<T> &other);

	//destructor:
	~ProtectedArray();

	//getters:
	int getCapacity() const;
	int getSize() const;

	//operators:
	T& operator[](const int index);
	T& operator*();
	ProtectedArray<T>& operator++();
	ProtectedArray<T>& operator--();
	ProtectedArray<T> operator+(int offset);
	ProtectedArray<T> operator-(int offset);
	ProtectedArray<T>& operator+=(int offset);
	ProtectedArray<T>& operator-=(int offset);
};

/*
	Constructor.

	INPUT:
		size - the size of the array to allocate.

	OUTPUT:
		None.
*/
template <typename T>
ProtectedArray<T>::ProtectedArray(int size)
{
	this->_array = new T[size];
	this->_capacity = size;
	this->_size = size;
	this->_index = 0;

	this->_count = new(int);
	*this->_count = 1;
}

/*
	Copy constructor.

	INPUT:
		other - ProtectedArray to copy.

	OUTPUT:
		None.
*/
template <typename T>
ProtectedArray<T>::ProtectedArray(ProtectedArray<T> &other)
{
	//We won't 'deep' copy the array because we want it to behave just like a normal array.
	this->_array = other._array;

	this->_capacity = other._capacity;
	this->_index = other._index;
	this->_size = other._size;

	this->_count = other._count;
	*this->_count += 1;
}

/*
	Destructor:

	INPUT:
		None.

	OUTPUT:
		None.
*/
template <typename T>
ProtectedArray<T>::~ProtectedArray()
{
	*this->_count -= 1;

	if (*this->_count == 0) //is this the last object the this array??? 
	{
		delete[] this->_array;
		delete this->_count;
	}
}

/*
	getCapacity:
		This method return the aloocated size of the array.

	INPUT:
		None.

	OUTPUT:
		int - the allocated size of the array.
*/
template <typename T>
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
template <typename T>
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
		will throw exception of "index out of range" if index is not in the range of the array.
*/
template <typename T>
T& ProtectedArray<T>::operator[](const int index)
{
	//   for possitive index        for negative index
	if (index > this->_size || index < this->_index * -1) //not in range
	{
		throw std::exception(ioor_s.c_str(), ioor_i);
	}

	return (this->_array + this->_index)[index];
}

/*
	operator*:

	INPUT:
		None.

	OUTPUT:
		T - referance to the first element in the array.
*/
template <typename T>
T& ProtectedArray<T>::operator*()
{
	return (this->_array + this->_index)[0];
}

/*
	operator++:

	INPUT:
		None.

	OUTPUT:
		Referance to the current object (array is + 1).
		Will throw exception of "index out of range" if reach to the last element and try to go after it.
*/
template <typename T>
ProtectedArray<T>& ProtectedArray<T>::operator++()
{
	return this->precedeArray(1);
}

/*
	operator--:

	INPUT:
		None.

	OUTPUT:
		Referance to the current object (array is -1).
		Will throw exception of "index out of range" if reach to the first element and try to go before it.
*/
template <typename T>
ProtectedArray<T>& ProtectedArray<T>::operator--()
{
	return this->precedeArray(-1);
}

/*
	operator +:

	INPUT:
		offset - number to move on the array (like operator ++, but more advanced :P)

	OUTPUT:
		New object.
		Will throw exception of "index out of range" if will go out of range... da...
*/
template <typename T>
ProtectedArray<T> ProtectedArray<T>::operator+(int offset)
{
	ProtectedArray<T> ret(*this);

	ret.precedeArray(offset);

	return ret;
}

/*
	operator -:

	INPUT:
		offset - number to move on the array (like operator --, but more advanced :P)

	OUTPUT:
		New object.
		Will throw exception of "index out of range" if will go out of range... da...
*/
template <typename T>
ProtectedArray<T> ProtectedArray<T>::operator-(int offset)
{
	ProtectedArray ret(*this);

	ret.precedeArray(-offset);

	return ret;
}

/*
	operator +=:

	INPUT:
		offset - number to move on the array.

	OUTPUT:
		referance to the current object.
		Will throw exceprion of "index out of range" if out of the range of the array.
*/
template <typename T>
ProtectedArray<T>& ProtectedArray<T>::operator+=(int offset)
{
	return this->precedeArray(offset);
}

/*
	operator -=:

	INPUT:
		offset - number to move on the array.

	OUTPUT:
		referance to the current object.
		Will throw exceprion of "index out of range" if out of the range of the array.
*/
template <typename T>
ProtectedArray<T>& ProtectedArray<T>::operator-=(int offset)
{
	return this->precedeArray(-offset);
}

/*
	This is a private method for the class use.
	It moving the array first pointer by 'offset' steps.

	INPUT:
		offset - steps to move the array pointer.

	OUTPUT:
		Referance to the current object.
		This method will throw "index out of range" exception if the offset is too high of low.
*/
template <typename T>
ProtectedArray<T>& ProtectedArray<T>::precedeArray(const int offset)
{
	//if offset is positive - size will decrease (and need to check if size will be greater then 0).
	//if offset is negative - size will increase (and need to check is size will be less then capacity).
	if ((offset >= 0 && this->_size - offset < 0) ||
		(offset < 0 && this->_size + (-offset) > this->_capacity))
			throw std::exception(ioor_s.c_str(), ioor_i);

	this->_index += offset;
	this->_size -= offset;

	return *this;
}
