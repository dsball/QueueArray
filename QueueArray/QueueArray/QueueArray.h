/*------------------------------------QueueArray.h
Purpose: provides general utility functions, headers, and generic using declarations.

--- Member Data ---
Name            Type           Description
-------------------------------------------------------------------------------------------
a               string          arbitrary data member
b               string          arbitrary data member
maxEntries      unsigned int    Size of working array
numEntries      unsigned int    number of array cells filled
head            unsigned int    index of first cell of queue
tail            unsigned int    index of last cell of queue

--- Functions ---
Name                            Return    Description; Parameter description
--------------------------------------------------------------------------------------------
QueueArray()                    none   
            Constructor, initializes class data members
makeEntry()                     ArrayEntry* 
            Creates a temporary struct and prompts user for data members, returns pointer to struct
dq()                            void 
            removes head from queue
operator+()                     QueueArray& 
			Adds data struct from argument to tail of array.
            ArrayEntry*   - pointer to data to be copied into array

operator+=()                    QueueArray& 
            Allows use of += operator to add a struct via operator+ overload
            ArrayEntry*    pointer to data to be copied into array
extend()                        void 
            Doubles the size of the working array 
operator<<();                   ostream& 
			Overloads extraction operator to output array contents to ostream.
			ostream&  - address of ostream being added to
			const QueueArray& - address of array being read

~QueueArray();      none
            destructor, de-allocates dynamically allocated memory

*/

#ifndef QUEUE_ARRAY_INTERFACE
#define QUEUE_ARRAY_INTERFACE
#include "utility.h"

using namespace std;

struct ArrayEntry
{
	string a;
	string b;
};

class QueueArray
{
private:
	ArrayEntry* workingArray;
	unsigned int maxEntries;
	unsigned int numEntries;
	unsigned int head;
	unsigned int tail;
public:
	QueueArray();
	ArrayEntry* makeEntry();
	void dq();
	QueueArray& operator+(ArrayEntry*);
	QueueArray& operator+=(ArrayEntry*);
	void extend();
	friend ostream& operator<<(ostream& , const QueueArray&);
	~QueueArray();
};

#endif