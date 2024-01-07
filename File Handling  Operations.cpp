//Problem Statement:-

/*Write a C++ program that creates an output file, writes information to it, closes the file and
open it again as an input file and read the information from the file.*/

//Code:-

#include<fstream>
#include<iostream>
#include<string.h>
using namespace std;

struct stud
{
	int rno;
	char nm[10];
}s;

void create()
{
	ofstream fout;
	int n,i;
	fout.open("stud.txt",ios::out);
	cout<<"\nENTER THE NUMBER OF RECORDS = ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"\nENTER ROOL NO & NAME = ";
		cin>>s.rno>>s.nm;
		fout<<endl<<s.rno<<"\t"<<s.nm;
	}
	fout.close();
}

void display()
{
	ifstream fin;
	fin.open("stud.txt",ios::in);
	while(!fin.eof())
	{
		fin>>s.rno>>s.nm;
		cout<<"\n"<<s.rno<<"\t"<<s.nm;
	}
	fin.close();
}

void search()
{
	ifstream fin;
	int fl,key;
	cout<<"\nENTER ROLL NO OF ELEMENT WHICH YOU WANT TO SEARCH = ";
	cin>>key;
	fin.open("stud.txt",ios::in);
	while(!fin.eof())
	{
		fin>>s.rno>>s.nm;
		if(s.rno==key)
		{
			fl=1;
			break;
		}
	}
	if(fl==1)
	{
	cout<<"\nELEMENT FOUND\n"<<s.rno<<"\t"<<s.nm;
	}
	else
	{
		cout<<"\nELEMENT NOT FOUND\n";
	}
	fin.close();
}

int main()
{
	int ch;
	do
	{
		cout<<"\n1.CREATE\n2.DISPLAY\n3.SEARCH\n4.EXIT";
		cout<<"\nENTER YOUR CHOICE == ";
		cin>>ch;
		switch(ch)
		{
			case 1:create();
			break;
			case 2:display();
			break;
			case 3:search();
			break;
		}
	}
	while(ch<4);
	return 0;
}