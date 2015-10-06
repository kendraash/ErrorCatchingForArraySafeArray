//
// Assignment  :  #5
// Class       :  CST 136
//
// Author      :  Kendra Ash 
//
// File        :  refCounter.cpp
//
// This file contains the member function bodies for the
// reference counter class. From exercise solution for Stack class
//

#include  <iostream>
#include  "refCounter.h"


//
// Constructor
//
RefCounter::RefCounter() : m_cnt(new int(1))
{
	if (!m_cnt)
	{
		std::cerr << "Memory allocation error!" << std::endl;
		exit(EXIT_FAILURE);
	}
}


//
// Copy constructor
//
RefCounter::RefCounter(const RefCounter  &rhs)
{
	copy(rhs);
}


//
// Destructor
//
RefCounter::~RefCounter()
{
	decrement();
}


//
// Return true of the reference count value is 1.
//
bool  RefCounter::onlyInstance() const
{
	return *m_cnt == 1;
}
//
// Decrement the counter and delete the memory if there's
// nothing left to count.
//
void  RefCounter::decrement()
{
	if (!--(*m_cnt))  delete  m_cnt;
}
//
// Copy the counter pointer and increment the count value.
//
void  RefCounter::copy(const RefCounter  &rhs)
{
	m_cnt = rhs.m_cnt;

	(*m_cnt)++;
}