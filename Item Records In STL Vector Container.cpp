//Problem Statement:-

/*Write C++ program using STL for sorting and searching user defined records such as Item records
(Item code, name, cost, quantity etc) using vector containers.*/

//Code:-

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class item
{
	public:
		char name[10];
		int quantity;
		int cost;
		int code;
	
		bool operator==(const item& i1)
		{
			if(code==i1.code)
				return 1;
			return 0;
		}
	
		bool operator<(const item& i1)
		{
			if(code<i1.code)
				return 1;
			return 0;
		}
};

vector<item> o1;
void print(item &i1);
void display();
void insert();
void search();
void dlt();

bool compare(const item &i1, const item &i2)
{
	return i1.cost<i2.cost;
}

int main()
{
	int ch;
		do
		{
			cout<<"\n******MENU*******";
			cout<<"\n1.INSERT";
			cout<<"\n2.DISPLAY";
			cout<<"\n3.SEARCH";
			cout<<"\n4.SORT";
			cout<<"\n5.DELETE";
			cout<<"\n6.EXIT";
			cout<<"\nENTER YOUR CHOICE : ";
			cin>>ch;

			switch(ch)
			{
				case 1:
					insert();
					break;
				case 2:
					display();
					break;
				case 3:
					search();
					break;
				case 4:
			        sort(o1.begin(),o1.end(),compare);
			        cout<<"\n\n SORTED ON COST ";
					display();
					break;
				case 5:
					dlt();
					break;
			}
		}while(ch<6);

		return 0;
}

void insert ()
{
	item i1;
	cout<<"\nENTER ITEM NAME : ";
	cin>>i1.name;
	cout<<"\nENTER ITEM QUANTITY : ";
	cin>>i1.quantity;
	cout<<"\nENTER ITEM COST : ";
	cin>>i1.cost;
	cout<<"\nENTER ITEM CODE : ";
	cin>>i1.code;
	o1.push_back(i1);
}

void display()
{
	for_each(o1.begin(),o1.end(),print);
}

void print(item &i1)
{
	cout<<"\n";
	cout<<"\nITEM NAME : "<<i1.name;
	cout<<"\nITEM QUANTITY : "<<i1.quantity;
	cout<<"\nITEM COST : "<<i1.cost;
	cout<<"\nITEM CODE : "<<i1.code;
}

void search()
{
	vector<item>::iterator p;
	item i1;
		
	cout<<"\nENTER ITEM CODE TO SEARCH : ";
	cin>>i1.code;

	p=find(o1.begin(),o1.end(),i1);

	if(p==o1.end())
	{
		cout<<"\nNOT FOUND.";
	}
	else
	{
		cout<<"\nFOUND.";
	}
}

void dlt()
{
	vector<item>::iterator p;
	item i1;
		
	cout<<"\nENTER ITEM CODE TO DELETE : ";
	cin>>i1.code;

	p=find(o1.begin(),o1.end(),i1);

	if(p==o1.end())
	{
		cout<<"\nNOT FOUND.";
	}
	else
	{
		o1.erase(p);
		cout<<"\nDELETED.";
	}
}
