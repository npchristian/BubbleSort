#include <iostream>
#include "Insert.h"
#define SIZE 49

	Insert::Insert(int array[])										
	{
		int count;
		for (count=0; count<=SIZE; count++)
			point[count]=&array[count];								//constructor class to assign integer values (unsorted)
	}
	
	Insert::~Insert()
	{
		//empty
	}

	void Insert::sorter()
	{
		int count, count2, temp;
		for (count=1; count<=SIZE; count++)
		{
			count2 = count;
			while (count2>0 && *point[count2-1] < *point[count2])
			{
				temp = *point[count2];
				*point[count2] = *point[count2-1];
				*point[count2-1] = temp;
				count2--;
			}
		}
		std::cout<<"Insertion Sort: ";
		for (count=0;count<=SIZE;count++)
			std::cout << *point[count] << " ";					//Insertion sort
	}