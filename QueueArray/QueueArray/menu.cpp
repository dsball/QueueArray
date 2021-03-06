#include "menu.h"

//default class constructor
Menu::Menu()
{
	title = "Menu";
	initMenu();
}

//class constructor with custom title input
Menu::Menu(string a)
{
	title = a;
	initMenu();
}

//initializes non-unique portions of class
void Menu::initMenu()
{
	maxEntries = 8;
	numEntries = 0;
	choice = 0;
	for(int i = 0; i<maxEntries;i++)
	{
		menuEntries[i] = " ";
	}
}

//gets menu choice from user
void Menu::addItem(string item)
{
	if(numEntries>=maxEntries)
	{
		cout<<endl<<"Error: array full./nIncrease array limit.";
		cin.clear();
		cin.sync();
		cout<<"press a key to continue";
		cin.get();
	}
	else
	{
		menuEntries[numEntries] = item;
		numEntries++;
	}
	return;
}
//displays menu items

//adds a menu item to the menu
int Menu::getChoice()
{
	clearScreen();
	cout<< "\n\n\t\t"<<title<<endl<<endl;
	for(int i = 0; i<numEntries;i++)
	{
		cout<<"\t";
		cout<<i+1<<": "<<menuEntries[i];
		cout<<endl;
	}
	while(true)
	{
		cout<<"\n\tPlease select your choice: ";
		cin.clear();
		cin.sync();
		cin>>choice;
		if(cin.fail() || choice<=0 )
		{
			cout<<"Invalid choice. ";
			continue;
		}
		break;
	}
	return choice;
}
