
//
// Assignment  :  #5
// Class       :  CST 136
//
// Author      :  Kendra Ash 
//
// File        :  array.h
//
//
// Description :  Declarations for the Array and SafeArray Templates.
//

#ifndef  array_H

#define  array_H

// Error condition definitions
#define ERR_BAD_BOUNDS 1
#define ERR_MEM_ALLOC 2
#define ERR_OUT_OF_BOUNDS 3

#include "refCounter.h"


template<class ELEMENT_TYPE>
class Array
{
	public :
		Array(int upper, int lower=0);
		~Array();
		
		int lowerBound() const;
		int upperBound() const;
		int size() const;
		int numElements() const
		{
			return abs(upperBound() - lowerBound()) + 1;
		}
		
		// Overloading []
		ELEMENT_TYPE &operator[](int index) const;
		ELEMENT_TYPE &operator[](int index); 
		Array<ELEMENT_TYPE> &operator=(const Array<ELEMENT_TYPE> &rhs);
	private :
		const int m_upper;
		const int m_lower; 
		ELEMENT_TYPE *m_index; // pointer to the data 

		int  realIndex(int  index)  const 
		{
			return  index - m_lower; 
		}

		RefCounter m_refCounter;

};
// ------------------------------------ SafeArray -------------------------------------------

template<class  ELEMENT_TYPE>
class  SafeArray : public  Array<ELEMENT_TYPE>
{
public:
		SafeArray(int upper, int lower = 0);
		
		ELEMENT_TYPE &operator[](int index) const;
		ELEMENT_TYPE &operator[](int index);
		SafeArray<ELEMENT_TYPE> &operator=(const SafeArray<ELEMENT_TYPE> &rhs);

	private:

	 void  m_checkRange(int index) const 
		{
			if (index < lowerBound() || index > upperBound())
			{
				throw ERR_OUT_OF_BOUNDS;
			}
		}
};

#include "array.inc"

#endif