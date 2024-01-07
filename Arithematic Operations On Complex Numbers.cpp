//Problem Statement:-

/*Implement a class Complex which represents the Complex Number data type.
Implement the following operations:
1. Constructor (including a default constructor which creates the complex number (0+0i).
2. Overloaded operator+ to add two complex numbers.
3. Overloaded operator* to multiply two complex numbers.*/

//Code:-

#include <iostream>
using namespace std;

class complex
{
	float x;
	float y;

	public:
	complex()           //constructor
	{
		x=0;
		y=0;
	}
	complex operator+(complex);
	complex operator*(complex);
	friend istream &operator>>(istream &input,complex &t);
	friend ostream &operator<<(ostream &input,complex &t);
};

complex complex::operator+(complex c)
{
	complex temp;
	temp.x=x+c.x;
	temp.y=y+c.y;
	return(temp);
}


complex complex::operator*(complex c)
{
	complex temp2;
	temp2.x=(x*c.x)-(y*c.y);
	temp2.y=(y*c.x)+(x*c.y);
	return (temp2);
}

istream &operator >>(istream &input,complex &t)
{
	cout<<"ENTER THE REAL PART : ";
	input>>t.x;
	cout<<"ENTER THR IMAGINARY PART : ";
	cin>>t.y;
}
ostream &operator <<(ostream &output,complex &t)
{
	output<<t.x<<"+"<<t.y<<"i\n";
}

int main()
{
	complex c1,c2,c3,c4;

	cout<<"DEFAULT CONSTRUCTOR VALUE = ";
	cout<<c1;
	
	cout<<"\nENTER THE 1ST NUMBER :\n";
	cin>>c1;

	cout<<"\nENTER THE 2ND NUMBER :\n";
	cin>>c2;

	c3=c1+c2;
	c4=c1*c2;

	cout<<"\nTHE FIRST NUMBER IS : ";
	cout<<c1;

	cout<<"\nTHE SECOND NUMBER IS : ";
	cout<<c2;

	cout<<"\nTHE ADDITION IS : ";
	cout<<c3;

	cout<<"\nTHE MULTIPLICATION IS : ";
	cout<<c4;

	return 0;
}