#ifndef SORT_H
#define SORT_H
#define SIZE 49

class Sort
{
	protected:
		int *point[SIZE];				//pointer to the integer array
	
	public:
		Sort()
		{
			//empty constructor			//empty constructor
		}
		
		virtual void sorter()=0;		//pure virtual class for sorting
};
#endif //SORT_H