#include "QueueArray.h"



QueueArray::QueueArray()
{
	maxEntries = 3;
	numEntries = 0;
	head = 0;
	tail = maxEntries-1;
	workingArray = new ArrayEntry[maxEntries];

}

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

void QueueArray::nq(ArrayEntry* tempEntry)
{
	if(numEntries == maxEntries)
	{
		double();
	}
	tail = (tail+1)%maxEntries;
	workingArray[tail] = *tempEntry;
	numEntries++;
	cout<<"Added.\n";
}

void QueueArray::dq()
{
	if(numEntries == 0)
	{
		cout<<"The queue is empty!";
	}
	else
	{
		head = (head+1)%maxEntries;
		numEntries--;
		cout<<"Deleted.\n";
	}
}

QueueArray::~QueueArray()
{
	delete workingArray;
}