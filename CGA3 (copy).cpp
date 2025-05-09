#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
class figure
{
	float length,delx,dely;
	int d,h,xc,yc;
	public:
		void drawline(float x1,float y1,float x2,float y2)
		{
			float xinc,yinc,dx,dy,steps;
			dx=x2-x1;
			dy=y2-y1;
			if(abs(dx)>abs(dy))
			steps=abs(dx);
			else
			steps=abs(dy);
			xinc=dx/steps;
			yinc=dy/steps;
			for(int i=0;i<steps;i++)
			{
				putpixel(x1,y1,WHITE);
				x1=x1+xinc;
				y1=y1+yinc;
			}
		}
		void drawcircle(int r,int  xc,int yc)
		{
			int x,y;
			d=3-2*r;
			x=0;
			y=r;
			do
			{
				putpixel(x+xc,y+yc,WHITE);
				putpixel(y+xc,x+yc,WHITE);
				putpixel(y+xc,-x+yc,WHITE);
				putpixel(x+xc,-y+yc,WHITE);
				putpixel(-x+xc,-y+yc,WHITE);
				putpixel(-y+xc,-x+yc,WHITE);
				putpixel(-y+xc,x+yc,WHITE);
				putpixel(-x+xc,y+yc,WHITE);
				if(d<0)
				{
					d=d+4*x+6;
					x=x+1;
				}
				else
				{
					d=d+4*(x-y)+10;
					y=y-1;
					x=x+1;
				}
			}
			while(x<=y);
		}
		void fig(float x11,float y11,float length)
		{
			h=(sqrt(3*length*length))/2;
			drawline(x11,y11,x11+length,y11);
			drawline(x11+length,y11,x11+(length)/2,y11-h);
			drawline(x11,y11,x11+(length)/2,y11-h);
			drawcircle(h/3,x11+(length)/2,y11-(h/3));
			drawcircle(2*h/3,x11+(length)/2,y11-(h/3));
		}
};

int main()
{
	figure f1;
	float x1,y1,length;
	cout<<"Enter the coordinate..."<<endl;
	cin>>x1>>y1;
	cout<<"Enter The length"<<endl;
	cin>>length;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	f1.fig(x1,y1,length);
	getch();
	closegraph();
	return 0;}

