//
// Assignment  :  #5
// Class       :  CST 136
//
// Author      :  Kendra Ash 
//
// File        :  array.inc
//
//
// Description :  Member function declarations for the template.
//

#include "array.h"
#include <iostream>
#include <cstdlib>

using namespace std;

// Constructor Array, allocating memory 

template<class  ELEMENT_TYPE>
Array<ELEMENT_TYPE>::Array(int upper, int lower) : m_upper(upper), m_lower(lower), m_index(new ELEMENT_TYPE[numElements()])
{
	if (!m_index)
	{
		throw ERR_MEM_ALLOC;
	}
	if (m_upper < m_lower)
	{
		throw ERR_BAD_BOUNDS;
	}
}
// Destructor
template<class  ELEMENT_TYPE>
Array<ELEMENT_TYPE>:: ~Array()
{
	if (m_refCounter.onlyInstance())
		delete[] m_index;
}

template<class  ELEMENT_TYPE>
int Array<ELEMENT_TYPE>::lowerBound() const
{
	return m_lower;
}
template<class  ELEMENT_TYPE>
int Array<ELEMENT_TYPE>::upperBound()const
{	
	return m_upper; 
}
template<class  ELEMENT_TYPE>
int Array<ELEMENT_TYPE>::size() const
{
	// number of elements times the number of bytes for the ELEMENT_TYPE  
	return sizeof(ELEMENT_TYPE)*numElements();
}
template<class  ELEMENT_TYPE>
ELEMENT_TYPE& Array<ELEMENT_TYPE>::operator[](int index) const 
{
	return m_index[realIndex(index)];
}
template<class  ELEMENT_TYPE>
ELEMENT_TYPE& Array<ELEMENT_TYPE>::operator[](int index)
{
	return m_index[realIndex(index)];
}
template<class ELEMENT_TYPE>
Array<ELEMENT_TYPE>& Array<ELEMENT_TYPE>:: operator=(const Array<ELEMENT_TYPE> &rhs)
{
	// check for self assignment
	if (this == &rhs)
		return *this;
	delete[] m_index;
	m_index = new ELEMENT_TYPE[numElements()];
	for (int index = lowerBound(); index <= upperBound(); index++)
		m_index[index] = rhs[index];

	return *this;
}
// ------------------------------------ SafeArray -------------------------------------------
// Allocating memory
template<class    ELEMENT_TYPE>
SafeArray<ELEMENT_TYPE>::SafeArray(int upper, int lower) : Array(upper, lower)
{
}

template<class  ELEMENT_TYPE>
ELEMENT_TYPE& SafeArray<ELEMENT_TYPE>::operator[](int index) const
{
	m_checkRange(index);
	return  Array<ELEMENT_TYPE>::operator[](index) const;
}
template<class  ELEMENT_TYPE>
ELEMENT_TYPE& SafeArray<ELEMENT_TYPE>::operator[](int index)
{
	m_checkRange(index);
	return  Array<ELEMENT_TYPE>::operator[](index);

}
template<class ELEMENT_TYPE>
SafeArray<ELEMENT_TYPE>& SafeArray<ELEMENT_TYPE>::operator=(const SafeArray<ELEMENT_TYPE> &rhs)
{
	// check for self assignment
	if (this == &rhs)
		return *this;
	delete [] m_index;
	m_index = new ELEMENT_TYPE[numElements()];

	for (int index = lowerBound(); index <= upperBound(); index++)
		m_index[index]=rhs[index];

	return *this;
}
