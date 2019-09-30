#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include "Sort.h"
#include "Insert.h"
#include "Bubble.h"
#define SIZE 49																//set size to 49 for data.txt

std::string fileRead();

int main()

{
	int count, choice, choice2, loopTrack, intArray[SIZE], backup[SIZE];	//variables for user deisions & tracking/storing
	choice=choice2=loopTrack=0;												//initialize user decisions to zero
	
	char trash;																//used to store the comma in the data.txt file.
	
	std::string tempString;
	std::stringstream mySS;													//used to convert string in .txt file to integers
	
	Bubble *myBubble;
	Insert *myInsert;														//classes to sort the integers
		
	while (choice2!=3 && choice!=2)											//do this until the user chooses to exit (enters 2 or 3)
	{
		while (choice!=1&& choice!=2)										//this loop prevents the user from entering an invalid number
		{
			std::cout << std::endl << "1. Load Data (from file)" << std::endl;
			std::cout << "2. Exit Program" << std:: endl;					//print menu
			std::cin >> choice;												//read user input from menu

			if (choice !=1 && choice !=2)
				std::cout<< "Error: restrict entry to 1 or 2." << std::endl;	//if user enters invalid number, print error and repeat
		}
		
		if (loopTrack==0)													//if loopTrack ==0, this will be the first loop iteration
		{
			tempString=fileRead();											//if this is the first loop iteration, read the file. 

			mySS << tempString;												//if this is the first loop iteration, parse it with stringStream
			
			for (count=0; mySS >> intArray[count]; count++)
				mySS >> trash;												//discard the commas
			
			for (count=0;count<=SIZE;count++)
				backup[count]=intArray[count];								//if this is the first loop iteration, backup the original integer order
		}
		
		else
			for(count=0;count<=SIZE;count++)
				intArray[count]=backup[count];								//if this is not the first loop iteration, reset the integer order
	
		if (choice!=2)														//if the user has not chosen to exit..
		{
			choice=choice2=0;std::cout << "Unsorted array: ";				//print the unsorted integers
			for (count=0;count<=SIZE; count++)
				std::cout << backup[count] << " ";
		}
		
		loopTrack++;														//this is a way to know if we are on our first loop
		
		while ((choice2>3 || choice2 <1) && choice !=2)						//if user has not chosen exit and user has entered a valid integer..
		{
			std::cout << std::endl << "1. Insertion sort." << std::endl;
			std::cout << "2. Bubble sort." << std::endl;
			std::cout << "3. Exit" << std::endl;
			std::cin >> choice2;											//print menu and get user choice
			
			switch (choice2)
			{
				case 1:
				{
					myInsert = new Insert(intArray);
					myInsert->sorter();
					delete(myInsert);										//clears memory / calls destructor
				}
				break;
				case 2:
				{
					myBubble=new Bubble(intArray);
					myBubble->sorter();
					delete(myBubble);										//clears memory / calls destructor
				}
				break;
				case 3:
					// do nothing
				break;
				default:
					std::cerr << "Error: restrict entry to 1-3." << std::endl;
				break;
			}
		}
	}
	std::cout << "Thank you! Goodbye!";
	return 0;
}

std::string fileRead()
{
	std::string temp;														//temporarily store into a string (transfer to integer array below)
	std::ifstream inFile;													//inFile for data.txt

	inFile.open("data.txt");
	
	if (!inFile)
	{
		std::cerr<< "Unable to open file: data.txt.";
		exit(1);
	}																		//exception for file not opened
	inFile >> temp;															//temporarily pull values onto tempString
	inFile.close();															//close file
	return temp;															//return string (to be transferred to IntArray in main
}
