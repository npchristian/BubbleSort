#include "Sort.h"	

class Bubble: public Sort
{
	public:
		Bubble(int array[]);			//constructor header
		~Bubble();						//destructor header
		
		virtual void sorter();			//pure virtual class from sort.h
};

