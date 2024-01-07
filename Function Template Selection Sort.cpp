//Problem Statement:-

/*Implement a function template selection Sort.
Write a program that inputs, sorts and outputs an integer array and a float array.*/

//Code:-

#include <iostream>
using namespace std;
#define size 10

int n;
template<class T>
void selection(T A[size])
{
	int i,j,min;
	T temp;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(A[j]<A[min])
			min=j;
		}
		temp=A[i];
		A[i]=A[min];
		A[min]=temp;
	}

	cout<<"\nSORTED LIST=\n";
	for(i=0;i<n;i++)
	cout<<"\t"<<A[i];
    cout<<endl;
}

int main()
{
	int i,A[size];
	float B[size];
	cout<<"SELECTION SORT\n";
	cout<<"\nINTEGER ELEMENT\n";
	cout<<"\nENTER HOW MANY ELEMENTS YOU WANT\n";
	cin>>n;
	cout<<"\nENTER THE INTEGER ELEMENT\n";
	for(i=0;i<n;i++)
    {
        cin>>A[i];
    }


	selection(A);

	cout<<"\nFLOAT ELEMENT\n";
	cout<<"\nENTER HOW MANY ELEMENTS YOU WANT\n";
	cin>>n;
	cout<<"\nENTER THE FLOAT ELEMENT\n";
	for(i=0;i<n;i++)
	cin>>B[i];

	selection(B);
	return 0;
}
