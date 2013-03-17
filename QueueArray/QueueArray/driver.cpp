#include "utility.h"
#include "QueueArray.h"
#include "menu.h"

int main()
{
	QueueArray workingArray;
	int choice = 0;
	Menu menuA;

	menuA.addItem("enqueue");
	menuA.addItem("Dequeue");
	menuA.addItem("List");
	menuA.addItem("Exit");

	
	while(choice!= 4)
	{
		choice = menuA.getChoice();
		switch(choice)
		{
			case 1:
				cout<<"Adding to queue:\n";
				workingArray += workingArray.makeEntry();
				break;
			case 2:
				workingArray.dq();
				pause();
				break;
			case 3:
				cout<<"Listing queue:\n";
				cout<<workingArray;
				pause();
				break;
			case 4:
				cout<<"Thank you for using queue.";
				break;
		}
	}

	pause();

	return 0;
}