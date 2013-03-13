#include "utility.h"
#include "QueueArray.h"

int main()
{
	ArrayEntry a;
	QueueArray b;

	a = *(b.makeEntry());

	cout<<a.a;
	cout<<a.b;
	pause();

	return 0;
}