//Problem Statement:-

/*Write C++ program to draw the following pattern.
Use DDA line and Bresenham‘s circle drawing algorithm.	
Apply the concept of encapsulation.*/

//Code:-

#include<iostream.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>

class algo
{
	public:
		void dda_line(float x1,float y1,float x2,float y2);
		void bres_circle(int r);
};

void algo::dda_line(float x1,float y1,float x2,float y2)
{
	float x,y,dx,dy,Dx,Dy,length;
	int c,i;
	dx=abs(x2-x1);
	dy=(y2-y1);
	if(dx>=dy)
	{
	length=dx;
	}
	else
	{
	length=dy;
	}
	Dx=(x2-x1)/length;
	Dy=(y2-y1)/length;
	x=x1+0.5;
	y=y1+0.5;
	i=1;
	while(i<=length)
	{
	putpixel(320+x,240-y,8);
	x=x+Dx;
	y=y+Dy;
	i=i+1;
	}
}

void algo::bres_circle(int r)
{
	int x,y,d;
	x=0;
	y=r;
	d=3-(2*r);
	do
	{
		putpixel(320+x,240+y,15);
		putpixel(320-x,240-y,4);
		putpixel(320+x,240-y,15);
		putpixel(320-x,240+y,15);
		putpixel(320+y,240-x,15);
		putpixel(320-y,240+x,15);
		putpixel(320+y,240+x,15);
		putpixel(320-y,240-x,15);

		if(d<=0)
		{
			d=d+4*x+6;
		}
		else
		{
			d=d+4*(x-y)+10;
			y=y-1;
		}
		x=x+1;
	}
	while(x<y);
}

int main()
{
	algo a1;
	int gm,gd=DETECT;
	int i;
	float r,ang,r1;
	cout<<"/n Enter the radius of large circle=";
	cin>>r;
	initgraph(&gd,&gm,"C:\\Turboc3\\BGI");
	a1.bres_circle(int (r));
	ang=3.14/180;
	float c=r*cos(30*ang);
	float s=r*sin(30*ang);
	a1.dda_line(0,r,0-c,0-s);
	a1.dda_line(0-c,0-s,0+c,0-s);
	a1.dda_line(0+c,0-s,0,r);
	r1=s;
	a1.bres_circle(int (r1));
	delay(200000);
	//closegraph();
	return 0;
}


