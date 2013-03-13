#ifndef QUEUE_ARRAY_INTERFACE
#define QUEUE_ARRAY_INTERFACE
#include "utility.h"

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
	int numEntries;
	int head;
	int tail;
public:
	QueueArray();
	ArrayEntry* makeEntry();
	void nq(ArrayEntry*);
	void dq();
	QueueArray& operator+(ArrayEntry*);
	QueueArray& operator+=(ArrayEntry*);
	void double();
	friend ostream& operator<<(ostream&,const QueueArray&);
	~QueueArray();
};

#endif