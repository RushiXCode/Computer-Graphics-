#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

class line_1
{
  public:
     void drawline(int x1,int x2,int y1,int y2)
     {
     line(x1, x2, y1, y2);
     }
};
class polygon1:public line_1
{
  int n,i,j,b[10][10],inx[10];
  float dx,dy,m[10];
  int ymin,ymax,y,temp;
  public:
     polygon1()
     {
     ymin=40;
     ymax=0;
     for(int i=0;i<10;i++)
        m[i]=0;
     }
     void accept()
     {
       cout<<"Enter the no. of sides:";
       cin>>n;
       cout<<"Enter the coordinates::";
       for(i=0;i<n;i++)
       {
         for(j=0;j<2;j++)
           {
             cin>>b[i][j];
           }
           if(b[i][1]>ymax)
             ymax=b[i][1];
           if(b[i][1]<ymin);
             ymin=b[i][1];
           }
      b[i][0]=b[0][0];
      b[i][1]=b[0][1];
     }
     void find()
     {
      for(i-0;i<n;i++)
        {
           line(b[i][0],b[i][1],b[i+1][0],b[i+1][1]);
           dx=b[i+1][0]-b[i][0];
           dy=b[i+1][1]-b[i][1];
           if(dy==0)
              m[i]=1;
           if(dx!=0&&dy!=0)
              m[i]=float(dx/dy);
         }
      }
      void scanline()
      {
         for(y=ymax;y>=ymin;y--)
         {
           int count=0;
           for(int i=0;i<n;i++)
           {
              if((b[i][1]>y&&b[i+1][1]<=y)||(b[i][1]<=y&&b[i+1][1]>y))
              {
                inx[count]=b[i][0]+(m[i]*(y-b[i][1]));
                count++;
              }
           }      
           for(int k=0;k<count-1;k++)
           {
             for(int i=0;i<n;i++)
             {
               if(inx[i]>inx[i+1])
                 {
                   temp=inx[i];
                   inx[i]=inx[i+1];
                   inx[i+1]=temp;
                 }
             }
           }
           setcolor(RED);
           for(int i=0;i<count-1;i=i+2)
           {
             drawline(inx[i],y,inx[i+1],y);
             delay(50);
           }
         }  
      }  
};
int main()
{
  int gd=DETECT,gm;
  polygon1 p;
  p.accept();
  initgraph(&gd,&gm,NULL);
  p.find();
  p.scanline();
  getch();
  closegraph();
   
  return 0;
}     

	

