//Problem Statement:-

/*Write C++ program to draw 2-D object and perform following basic transformations, Scaling,Translation Rotation.
Apply the concept of operator overloading.*/

//Code:-

#include<iostream.h>
#include<process.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>

int i,j,k;  // Declaration of Variables

class Transf // Declaration of Class
{
	private:
		int n,Before[10][3],After[10][3];
		float T[3][3];
	public:
		void GetData();
		void Menu();
		void Multi();
		void DrawPoly();
};

void Transf::GetData()
{
	cout<<"\n\n\tEnter no of Vertices ==> ";
	cin>>n;
	cout<<"\n\t Enter the Co-Ordinates of Vertices ==> ";
	for(i=0;i<n;i++)
	{
		cin>>Before[i][0];
		cin>>Before[i][1];
		Before[i][2]=1;
	}

	Before[n][0]=Before[0][0];
	Before[n][1]=Before[0][1];
	Before[n][2]=1;

	cout<<"\n\n\t Matrix Representation is ==> \n\n";
	 // The coordinates accepted from user are represented in Matrix form

	for(i=0;i<n;i++)
	{
		cout<<"\n\n\t";
		for(j=0;j<3;j++)
		{
			cout<<"\t";
			cout<<Before[i][j];
		}
	}
}

void Transf::Menu()
{
	int nCh,Tx,Ty,nC;
	float Sx,Sy;
	double X;
	cout<<"\n\n\t 1.Translation. \n\n\t 2.Rotation.";
	cout<<"\n\n\t 3.Scaling. \n\n\t 4.Exit";
	cout<<"\n\n\t Enter your Choice ==> ";
	cin>>nCh;
	switch(nCh)
	{
		case 1:
			cout<<"\n\t Enter the Translation Co-Ordinates for X = ";
			cin>>Tx;
			cout<<"\n\t Enter the Translation Co-Ordinates for Y = ";
			cin>>Ty;

			T[0][0]=1;
			T[0][1]=0;
			T[0][2]=0;
			T[1][0]=0;
			T[1][1]=1;
			T[1][2]=0;
			T[2][0]=Tx;
			T[2][1]=Ty;
			T[2][2]=1;
			break;

		case 2:
			cout<<"\n\n 1.Counter Clockwise.";
			cout<<"\n\n 2.Clockwise.";
			cout<<"\n\n Enter your Choice ==> ";
			cin>>nC;
			cout<<"\n\n\t Enter The Angle ==> ";
			cin>>X;
			X=X*(3.1432/180);
			if(nC==1)
			{

				T[0][0]=cos(X);
				T[0][1]=sin(X);
				T[0][2]=0;
				T[1][0]=(-1)*sin(X);
				T[1][1]=cos(X);
				T[1][2]=0;
				T[2][0]=0;
				T[2][1]=0;
				T[2][2]=1;
			}
			else
			{
				T[0][0]=cos(X);
				T[0][1]=(-1)*sin(X);
				T[0][2]=0;
				T[1][0]=sin(X);
				T[1][1]=cos(X);
				T[1][2]=0;
				T[2][0]=0;
				T[2][1]=0;
				T[2][2]=1;
			}
			break;

		case 3:
			cout<<"\n\t Enter the value of X Scaling = ";
			cin>>Sx;
			cout<<"\n\t Enter the value of Y Scaling = ";
			cin>>Sy;

			T[0][0]=Sx;
			T[0][1]=0;
			T[0][2]=0;
			T[1][0]=0;
			T[1][1]=Sy;
			T[1][2]=0;
			T[2][0]=0;
			T[2][1]=0;
			T[2][2]=1;
			break;

		case 4:
			exit(0);
			break;
		default:
			cout<<"\n\n Invalid Choice!!!!";
	}

} // End of Menu Function

void Transf::Multi()
{
	for(i=0;i<=n;i++)
	{
		for(j=0;j<3;j++)
		{
			After[i][j]=0;
			for(k=0;k<3;k++)
			{
				After[i][j]=After[i][j]+(Before[i][k]*T[k][j]);
			}
		}
	}
}

void Transf :: DrawPoly()
{
		int i;
		int Xc,Yc,Xmax,Ymax;
		int gd=DETECT,gm;
		initgraph(&gd,&gm,"c:\\Turboc3\\bgi");
		Xmax=640;
		Ymax=480;
		Xc=Xmax/2;
		Yc=Ymax/2;

		line(0,Yc,Xmax,Yc);
		line(Xc,0,Xc,Ymax);
		outtextxy(Xc,0,"Y axis");
		outtextxy(0,Yc,"X axis");
		outtextxy(Xc,Yc,"(0,0)");

		cout<<"\n\n\t Before Transformation ==> ";
		for(i=0;i<n;i++)
		{
			line(Xc+Before[i][0],Yc-Before[i][1],Xc+Before[i+1][0],Yc-Before[i+1][1]);
		}
		getch();
		//cleardevice();
		cout<<"\n\n\t After Transformation ==> ";
		for(i=0;i<n;i++)
		{
			line(Xc+After[i][0],Yc-After[i][1],Xc+After[i+1][0],Yc-After[i+1][1]);
		}
}

int main()
{
	Transf obj;
	clrscr();
	char nAns;
	obj.GetData();
	do
	{
		obj.Menu();
		obj.Multi();
		obj.DrawPoly();
		cout<<"\n\n\t Do you want to continue ? (y||Y) ";
		cin>>nAns;
		cleardevice();
	}while(nAns == 'y' || nAns == 'Y' );
	getch();
	closegraph();

return 0;
}
