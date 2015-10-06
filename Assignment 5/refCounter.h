//
// Assignment  :  #5
// Class       :  CST 136
//
// Author      :  Kendra Ash 
//
// File        :  refCounter.h
//
// This file contains the declaration for a
// reference counter class. From exercise solution for Stack class
//

#ifndef refCounter_H
#define refCounter_H

//
// Reference counting class declaration
//
class RefCounter
{
public:

	RefCounter();
	RefCounter(const RefCounter  &rhs);
	~RefCounter();
	bool  onlyInstance() const;

private:

	int  *m_cnt;

	void  decrement();
	void  copy(const RefCounter  &rhs);
};


#endif