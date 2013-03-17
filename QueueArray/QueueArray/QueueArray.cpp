//------------------------------------QueueArray.cpp
#include "QueueArray.h"

//initializes class data members
QueueArray::QueueArray()
{
	maxEntries = 3;
	numEntries = 0;
	head = 0;
	tail = maxEntries-1;
	workingArray = new ArrayEntry[maxEntries];
	if(!workingArray)
	{
		cout<<"Heap is full, exiting.";
		exit(0);
	}

}

//Creates a temporary struct and prompts user for data members, returns pointer to struct
ArrayEntry* QueueArray::makeEntry()
{
	ArrayEntry* tempEntry = nullptr;
	tempEntry = new ArrayEntry;
	if(!tempEntry)
	{
		cout<<"Failure in allocating memory.\n";
		exit(0);
	}

	cout<<"String 1: ";
	while(!(cin>>tempEntry->a))
	{
		cin.sync();
		cin.clear();
		cout<<"Invalid entry, try again:";
	}
	cout<<"String 2: ";
	while(!(cin>>tempEntry->b))
	{
		cin.sync();
		cin.clear();
		cout<<"Invalid entry, try again:";
	}
	
	return tempEntry;
}

//Adds data struct from argument to tail of array.
QueueArray& QueueArray::operator+(ArrayEntry* tempEntry)
{
	if(numEntries == maxEntries)
	{
		extend();
	}
	tail = (tail+1)%maxEntries;
	workingArray[tail] = *tempEntry;
	numEntries++;
	cout<<"Added "<<workingArray[tail].a;

	return *this;
}

//Allows use of += operator to add a struct via operator+ overload
QueueArray& QueueArray::operator+=(ArrayEntry* tempEntry)
{
	*this = *this + tempEntry;
	return *this;
}

//removes head from queue
void QueueArray::dq()
{
	if(numEntries == 0)
	{
		cout<<"The queue is empty!";
	}
	else
	{
		cout<<"Deleting "<<workingArray[head].a<<endl;
		head = (head+1)%maxEntries;
		numEntries--;
		cout<<" Deleted.\n";
	}
}

//Doubles the size of the working array 
void QueueArray::extend()
{
	unsigned int i = 0;
	unsigned int curr = head;
	ArrayEntry *tempArray = new ArrayEntry[maxEntries*2];
	if(!tempArray)
	{
		cout<<"Heap is full, exiting.";
		exit(0);
	}
	for(i ; i<numEntries ; i++)
	{
		tempArray[i] = workingArray[curr];
		curr = (curr+1)%maxEntries;
	}
	maxEntries *= 2;
	delete []workingArray;
	workingArray = tempArray;
	tempArray = nullptr;
	head = 0;
	tail = numEntries-1;
}

//Overloads extraction operator to output array contents to ostream.
ostream& operator<<(ostream& outStream , const QueueArray& inQueue)
{
	unsigned int h = inQueue.head;
	ArrayEntry *tempArray = inQueue.workingArray;
	for(unsigned int i = 0; i<inQueue.numEntries; i++)
	{
		outStream<<setw(10)<<tempArray[h].a<<setw(10)<<tempArray[h].b<<endl;
		h=(h+1)%inQueue.maxEntries;
	}

	return outStream;
}

QueueArray::~QueueArray()
{
	//de-allocates dynamically allocated memory
	delete[] workingArray;
	if(!workingArray)
	{
		cout<<"Deleted Array.";
	}
	else
	{
		cout<<"ERROR DELETING ARRAY! MEMORY LEAK DETECTED!";
		exit(0);
	}
}