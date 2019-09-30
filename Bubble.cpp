#include <iostream>
#include "Bubble.h"
#define SIZE 49

	Bubble::Bubble(int array[])
	{
		int count;
		for (count=0; count<=SIZE; count++)
			point[count]=&array[count];							//constrcuctor to point pointer to integer array
	}
	Bubble::~Bubble()
	{
		//empty deconstructor									//deconstructor
	}
	
	void Bubble::sorter()
	{
		int count, count2, temp;
		bool isSorted = false;
		
		for(count=1; (count<=SIZE) && isSorted==false; count++)
		{
			isSorted = true;
			for (count2=0; count2<SIZE; count2++)
				if (*point[count2+1] > *point[count2]) 	
				{
					temp = *point[count2];
					*point[count2] = *point[count2+1];
					*point[count2+1] = temp;
					isSorted = false;
				}
		}														//Bubble sorter
		std::cout<<"Bubble Sort: ";
		for (count=0;count<=SIZE;count++)
			std::cout << *point[count] << " ";
	}