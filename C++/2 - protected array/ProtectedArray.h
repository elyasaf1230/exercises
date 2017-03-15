#pragma once

#include <iostream>
#include <exception>
#include <string>

template <class T> 
class ProtectedArray
{
private:
	T *_array;

	int _capacity;	//(real) size of the array in memory.
	int _size;		//size of the array.
	int _index;		//first element in array (for operator++)

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
};