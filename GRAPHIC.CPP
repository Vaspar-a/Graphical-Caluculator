#include<graphics.h>
#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#define PI 3.14
void graph(int c,int c1=0);
void id(int c,int c1=0);
class L                                 //Line
{
    float A,B,C,x,y,n;

    public:
L()         //Enter data
{
clrscr();
cout<<"Enter equation of line as Ax + By + C = 0\n";
cout<<"\nEnter A:";
cin>>A;
fflush(stdin);
cout<<"\nEnter B:";
cin>>B;
fflush(stdin);
cout<<"\nEnter C:";
cin>>C;
fflush(stdin);
if(C==0)            //Passes through origin
	{
		x=200;
		y=(x)*(-A/B);
		getch();
		n=0;
	}
else if(A==0)       //Parallel to X-axis
{
	C/=B;
	x=0;
	n=-C;
}

else if(B==0)       //Parallel to Y-axis
{
	C/=A;
	y=0;
	n=-C;
}

else                //Makes intercept with both axes
	{
		x=(-1)*((C/A)*25);
		y=((C/B)*25);
		getch();
		n=C;
	}
	clrscr();
graph(1);
gl();
id(1);
}
private:
void gl()
{
char b[20];
if(n==0)
	{
		line((int)x+319,(int)239-y,(int)319-x,(int)y+239);
		setcolor(4);
		sprintf(b,"Slope=%0.2f",y/(x));
		outtextxy(469,19,b);
		outtextxy(469,29,(char *)"X-intercept=0");
		outtextxy(469,39,(char *)"Y-intercept=0");
	}
else if(x==0)
{
	line(119,239-(25*n),519,239-(25*n));
	setcolor(4);
	outtextxy(469,19,(char *)"Slope=0");
	outtextxy(469,29,(char *)"X-intercept=0");
	sprintf(b,"Y-intercept=%0.2f",n);
	outtextxy(469,39,b);
}

else if(y==0)
{
	line((int)319+(25*n),39,(int)319+(25*n),439);
	setcolor(4);
	outtextxy(469,19,(char *)"Slope=INF");
	sprintf(b,"X-intercept=%0.2f",n);
	outtextxy(469,29,b);
	outtextxy(469,39,(char *)"Y-intercept=0");
}

else
	{
		line((int)x+319,239,319,(int)y+239);
		moveto((int)x+319,239);
		linerel((int)2*(x),(int)-2*(y));
		moveto(319,(int)y+239);
		linerel((int)-2*(x),(int)2*(y));
		setcolor(4);
		sprintf(b,"Slope=%0.2f",y/(x));
		outtextxy(469,19,b);
		sprintf(b,"X-intercept=%0.2f",(x)/25);
		outtextxy(469,29,b);
		sprintf(b,"Y-intercept=%0.2f",(-1)*(y)/25);
		outtextxy(469,39,b);
	}

}
};

class C     //Circle
{
    float x,y,r;
    public:
C()
{
clrscr();
cout<<"Enter equation of circle as: (x-h)^2 + (y-k)^2 = r^2\n";
cout<<"Enter h:";
cin>>x;
fflush(stdin);
cout<<"Enter k:";
cin>>y;
fflush(stdin);
cout<<"Enter r:";
cin>>r;
fflush(stdin);
clrscr();
graph(2);
gc();
id(2);
}
private:
void gc()
{
char b[25];
setcolor(BLUE);
(x)=(x)*25;
(y)=(y)*25;
circle((int)x+319,(int)239-y,(int)r*25);
setcolor(4);
sprintf(b,"Centre: (%0.2f,%0.2f)",x/25,y/25);
outtextxy(469,19,b);
sprintf(b,"Radius: %0.2f",r);
outtextxy(469,29,b);
}

};

class E         //Ellipse
{
      float h,k,a,b;
public:
E()
{
clrscr();
cout<<"Enter equation of ellipse as: (x-h)^2/a^2 + (y-k)^2/b^2 = 1\nEnter h:";
cin>>h;
cout<<"Enter k:";
cin>>k;
cout<<"Enter a:";
cin>>a;
cout<<"Enter b:";
cin>>b;
clrscr();
graph(3);
ge();
id(3);
}
private:
void ge()
{
char s[25];
h*=25;
k*=25;
a*=25;
b*=25;
ellipse((int)319+h,(int)239-k,0,360,(int)a,(int)b);
setcolor(4);
if(a>b) //e=sqrt(1-b^2/a^2)
sprintf(s,"Eccentricity=%0.2f",sqrt(1-((b/25)*(b/25))/((a/25)*(a/25))));
else    //e=sqrt(1-a^2/b^2)
sprintf(s,"Eccentricity=%0.2f",sqrt(1-((a/25)*(a/25))/((b/25)*(b/25))));
outtextxy(409,19,s);
if(a>b) //(h-sqrt(a^2-b^2),k)   (h+sqrt(a^2-b^2),k)
sprintf(s,"Foci:(%0.2f,%0.2f)(%0.2f,%0.2f)",h/25-sqrt(((a/25)*(a/25))-((b/25)*(b/25))),k/25,h/25+sqrt(((a/25)*(a/25))-((b/25)*(b/25))),k/25);
else    //(h,k-sqrt(b^2-a^2))   (h,k+sqrt(b^2-a^2))
sprintf(s,"Foci:(%0.2f,%0.2f)(%0.2f,%0.2f)",h/25,k/25-sqrt(((b/25)*(b/25))-((a/25)*(a/25))),h/25,k/25+sqrt(((b/25)*(b/25))-((a/25)*(a/25))));
outtextxy(409,29,s);
if(a>b) //h+a/e   h-a/e
sprintf(s,"Eqn of drtx:x=%0.2f x=%0.2f",h/25+(a/25)/sqrt(1-((b/25)*(b/25))/((a/25)*(a/25))),h/25-(a/25)/sqrt(1-((b/25)*(b/25))/((a/25)*(a/25))));
else    //k+b/e   k-b/e
sprintf(s,"Eqn of drtrx:y=%0.2f y=%0.2f",k/25+(b/25)/sqrt(1-((a/25)*(a/25))/((b/25)*(b/25))),k/25-(b/25)/sqrt(1-((a/25)*(a/25))/((b/25)*(b/25))));
outtextxy(409,39,s);
}


};

class P     //Parabola
{
    float h,k,a;
    short int c;
    void gp();
public:
    P();
};

P::P()
{
clrscr();
cout<<"For regular parabola press 1\nFor sideways parabola press 2\n";
cin>>c;
clrscr();
switch(c)
{
case 1:
	cout<<"Enter equation as: y = a(x-h)^2 + k\n";
	break;
case 2:
	cout<<"Enter equation as: x = a(y-k)^2 + h\n";
	break;
}
cout<<"Enter a:";
cin>>a;
cout<<"Enter h:";
cin>>h;
cout<<"Enter k:";
cin>>k;
clrscr();
graph(4);
gp();
id(4);
}


void P::gp()
{
 float x,y,i;
 char b[25];
switch(c)
{
case 1:
	for(i=h-2;i<=h+2;i+=0.00001)
	{
	x=i;
	y=a*(x-h)*(x-h)+k;  //y=a^2*(x-h)^2+k
	x*=25;y*=25;
	putpixel((int)319+x,(int)239-y,1);
	}
	setcolor(4);
	sprintf(b,"Focus: (%0.2f,%0.2f)",h,k+(1/(4*a)));    //focus=(h,k+1/4a)
	outtextxy(469,19,b);
	sprintf(b,"Directrix: y=%0.2f",k-(1/(4*a)));        //drtx=k-1/4a
	outtextxy(469,29,b);
	sprintf(b,"Axis of symm: x=%0.2f",h);               //x=h
	outtextxy(469,39,b);
	break;
case 2:
	for(i=k-2;i<=k+2;i+=0.00001)
	{
	y=i;
	x=a*(y-k)*(y-k)+h;  //x=a^2*(y-k)^2+h
	x*=25;y*=25;
	putpixel((int)319+x,(int)239-y,1);
	}
	setcolor(4);
	sprintf(b,"Focus: (%0.2f,%0.2f)",h+(1/(4*a)),k);        //focus=(h+1/4a,k)
	outtextxy(469,19,b);
	sprintf(b,"Directrix: y=%0.2f",h-(1/(4*a)));            //drtx=h-1/4a
	outtextxy(469,29,b);
	sprintf(b,"Axis of symm: y=%0.2f",k);                   //y=k
	outtextxy(469,39,b);
	break;
}
}

class H
{
    float h,k,a,b;
    short int n;
    void gh();
public:
H()
{

clrscr();
cout<<"For transverse axis as Y-axis press 1\nFor transverse axis as X-axis press 2\n";
cin>>n;
clrscr();
if(n==1)
	cout<<"Enter equation as: (y-k)^2/a^2 - (x-h)^2/b^2 =1\n";
else if(n==2)
	cout<<"Enter equation as: (x-h)^2/a^2 - (y-k)^2/b^2 =1\n";
cout<<"Enter h:";
cin>>h;
cout<<"Enter k:";
cin>>k;
cout<<"Enter a:";
cin>>a;
cout<<"Enter b:";
cin>>b;
clrscr();
graph(5);
gh();
id(5);
}
};
void H::gh()
{
char s[25];
float x,y,i;
switch(n)
{
case 1:
	for(i=h-4;i<=h+4;i+=0.00001)
	{
		x=i;
		y=((a*a)/(b*b))*((x-h)*(x-h)+1);    //y=[(a^2/b^2)*((x-h)^2+1)]^1/2+k
		y=sqrt(y);
		y+=k;
		x*=25;y*=25;
		putpixel(319+x,239-y,1);
	}

	for(i=h-4;i<=h+4;i+=0.00001)
	{
		x=i;
		y=((a*a)/(b*b))*((x-h)*(x-h)+1);   //y=[(a^2/b^2)*((x-h)^2+1)]^1/2+k
		y=-sqrt(y);
		y+=k;
		x*=25;y*=25;
		putpixel(319+x,239-y,1);
	}
setcolor(4);
sprintf(s,"Eccentricity=%0.2f",sqrt(1+((b/25)*(b/25))/((a/25)*(a/25))));
outtextxy(409,19,s);
sprintf(s,"Foci:(%0.2f,%0.2f)(%0.2f,%0.2f)",h/25,k/25-sqrt(((b/25)*(b/25))+((a/25)*(a/25))),h/25,k/25+sqrt(((b/25)*(b/25))+((a/25)*(a/25))));
outtextxy(409,29,s);
sprintf(s,"Eqn of drtrx:y=%0.2f y=%0.2f",k/25+(b/25)/sqrt(1+((b/25)*(b/25))/((a/25)*(a/25))),k/25-(b/25)/sqrt(1+((b/25)*(b/25))/((a/25)*(a/25))));
outtextxy(409,39,s);

	break;
case 2:
	for(i=h+1;i<=h+4;i+=0.00001)
	{
		x=i;
	       y=((b*b)/(a*a))*((x-h)*(x-h)-1); //y=[(b^2/a^2)*((x-h)^2-1)]^1/2+k
		y=sqrt(y);
		y+=k;
		x*=25;y*=25;
		putpixel(319+x,239-y,1);
	}

	for(i=h+1;i<=h+4;i+=0.00001)
	{
		x=i;
		y=((b*b)/(a*a))*((x-h)*(x-h)-1);    //y=[(b^2/a^2)*((x-h)^2-1)]^1/2+k
		y=-sqrt(y);
		y+=k;
		x*=25;y*=25;
		putpixel(319+x,239-y,1);
	}

	for(i=h-4;i<=h-1;i+=0.00001)
	{
		x=i;
        y=((b*b)/(a*a))*((x-h)*(x-h)-1);    //y=[(b^2/a^2)*((x-h)^2-1)]^1/2+k
		y=sqrt(y);
		y+=k;
		x*=25;y*=25;
		putpixel(319+x,239-y,1);
	}

	for(i=h-4;i<=h-1;i+=0.00001)
	{
		x=i;
		y=((b*b)/(a*a))*((x-h)*(x-h)-1);    //y=[(b^2/a^2)*((x-h)^2-1)]^1/2+k
		y=-sqrt(y);
		y+=k;
		x*=25;y*=25;
		putpixel(319+x,239-y,1);
	}
setcolor(4);
sprintf(s,"Eccentricity=%0.2f",sqrt(1+(b/25*b/25)/(a/25*a/25)));
outtextxy(409,19,s);
sprintf(s,"Foci:(%0.2f,%0.2f)(%0.2f,%0.2f)",h/25-sqrt((a/25*a/25)+(b/25*b/25)),k/25,h/25+sqrt((a/25*a/25)+(b/25*b/25)),k/25);
outtextxy(409,29,s);
sprintf(s,"Eqn of drtx:x=%0.2f x=%0.2f",h/25+(a/25)/sqrt(1+(b/25*b/25)/(a/25*a/25)),h/25-(a/25)/sqrt(1+(b/25*b/25)/(a/25*a/25)));
outtextxy(409,39,s);

	break;
}

}


class F
{
 float a,b,c;
    short int n;
     void gf();
public:
F();
};

F::F()
{
clrscr();
cout<<"For sin press 1\nFor cos press 2\nFor tan press 3\nFor cosec press 4\nFor sec press 5\nFor cot press 6\nFor log press 7\nFor exp press 8\n";
cin>>n;
switch(n)   //y=*f(bx+c)
	{
	case 1: clrscr();
		cout<<"Enter equation as: y = a*sin( bx + c )\n";
		break;

	case 2: clrscr();
		cout<<"Enter equation as: y = a*cos( bx + c )\n";
		break;

	case 3: clrscr();
		cout<<"Enter equation as: y = a*tan( bx + c )\n";
		break;

	case 4: clrscr();
		cout<<"Enter equation as: y = a*cosec( bx + c )\n";
		break;

	case 5: clrscr();
		cout<<"Enter equation as: y = a*sec( bx + c )\n";
		break;

	case 6: clrscr();
		cout<<"Enter equation as: y = a*cot( bx + c )\n";
		break;

	case 7: clrscr();
		cout<<"Enter equation as: y = a*log( bx + c )\n";
		break;

	case 8: clrscr();
		cout<<"Enter equation as: y = a*e^( bx + c )\n";
		break;
	}
cout<<"Enter a:";
cin>>a;
cout<<"Enter b:";
cin>>b;
cout<<"Enter c:";
cin>>c;
clrscr();
graph(6,(int)n);
gf();
id(6,(int)n);
}

void F::gf()
{
float x,y,i;
float s=-2*PI,e=2*PI;
if(n==7)
{
	s=0.00001;
}
	for(i=s;i<=e;i+=0.00001)
	{
		x=b*i+c;
	switch(n)   //y=a*f(b*x+c)
	{
	case 1:
		y=a*sin(x);
		break;
	case 2:
		y=a*cos(x);
		break;
	case 3:
		y=a*tan(x);
		break;
	case 4:
		y=a*(1/sin(x));
		break;
	case 5:
		y=a*(1/cos(x));
		break;
	case 6:
		y=a*(1/tan(x));
		break;
	case 7:
		y=a*log(x);
		break;
	case 8:
		y=a*exp(x);
		break;
	}

		x*=25;y*=25;
		putpixel(319+x,239-y,1);
	}
}

class IF
{
    float a;
    short int n;
    void gif();
public:
    IF();
};

IF::IF()
{
clrscr();
cout<<"For sin inverse press 1\nFor cos inverse press 2\nFor tan inverse press 3\nFor cosec inverse press 4\nFor sec inverse press 5\nFor cot inverse press 6\n";
cin>>n;
switch(n)   //y=a*f(bx+c)
	{
	case 1: clrscr();
		cout<<"Enter equation as: y = a*sin^-1 (x)\n";
		break;

	case 2: clrscr();
		cout<<"Enter equation as: y = a*cos^-1 (x)\n";
		break;

	case 3: clrscr();
		cout<<"Enter equation as: y = a*tan^-1 (x)\n";
		break;

	case 4: clrscr();
		cout<<"Enter equation as: y = a*cosec^-1 (x)\n";
		break;

	case 5: clrscr();
		cout<<"Enter equation as: y = a*sec^-1 (x)\n";
		break;

	case 6: clrscr();
		cout<<"Enter equation as: y = a*cot^-1 (x)\n";
		break;
	}
cout<<"Enter a:";
cin>>a;
clrscr();
graph(7);
gif();
id(7);
}

void IF::gif()
{
    float x,y,i;    //y=a*f(b*x+c)
	if(n==4 || n==5)    //For cosec,sec
	{
		for(i=-5;i<=-1;i+=0.00001)
		{
			x=i;
			if(n==4)
				y=a*asin(1/(x));
			else
				y=a*acos(1/(x));
			x*=25;y*=25;
			putpixel(319+x,239-y,1);
		}
		for(i=1;i<=5;i+=0.00001)
		{
			x=i;
			if(n==4)
				y=a*asin(1/(x));
			else
				y=a*acos(1/(x));
			x*=25;y*=25;
			putpixel(319+x,239-y,1);
		}
	}
	else if(n==1 || n==2)   //For sin,cos
	{
		 for(i=-1;i<=1;i+=0.00001)
		{
			x=i;
			if(n==1)
				y=a*asin(x);
			else
				y=a*acos(x);
			x*=25;y*=25;
			putpixel(319+x,239-y,1);
		}
	}
	else if(n==3 || n==6)   //For tan,cot
	{
		for(i=-5;i<=5;i+=0.00001)
		{
			x=i;
			if(n==3)
				y=a*atan(x);
			else
				y=a*atan(1/(x));
			x*=25;y*=25;
			putpixel(319+x,239-y,1);
		}
	}

}

int main()
{
short int c;
clrscr();
A:
cout<<"For line press 1\nFor circle press 2\nFor ellipse press 3\nFor parabola press 4\nFor hyperbola press 5\nFor trigonometric,logarithmic & exponential functions press 6\nFor inverse trigonometric functions press 7\nTo exit press -1\n";
cin>>c;
switch(c)
{
case 1:
	{L l;
	break;}
case 2:
	{C cr;
	break;}
case 3:
	{E e;
	break;}
case 4:
	{P p;
	break;}
case 5:
	{H h;
	break;}
case 6:
	{F f;
	break;}
case 7:
	{IF fi;
	break;}
case -1:
	exit(0);
	break;
default:
    cout<<"Please enter above mentioned numbers";
    getch();
    clrscr();
    goto A;
}
goto A;
//MAX_H=639 MAX_V=479
return 0;
}

void graph(int c,int c1)
{
    int gd = DETECT,gm;
    initgraph(&gd,&gm,(char *)"C:\\TURBOC3\\BGI");
float i;
setbkcolor(WHITE);  //Background=white
setcolor(RED);      //Axes=red
line(319,0,319,479);
line(0,239,639,239);
setcolor(BLUE);     //Points=Blue
circle(319,239,2);
if(c==6 && (c1!=7 && c1!=8))    //For trigo fns
{
for(i=PI;i<=4*PI;i+=PI)
{
 circle(319+(i*25),239,2);
 circle(319-(i*25),239,2) ;
}
for(i=1;i<=8;i++)
{
 circle(319,239-(i*25),2);
 circle(319,239+(i*25),2) ;
}
}
else if(c==7)   //For inverse trigo fns
{
for(i=1;i<=12;i++)
{
 circle(319+(i*25),239,2);
 circle(319-(i*25),239,2) ;
}
for(i=PI;i<=3*PI;i+=PI)
{
 circle(319,239-(i*25),2);
 circle(319,239+(i*25),2) ;
}
}
else    //For all other entities
{
for(i=1;i<=12;i++)
{
 circle(319+(i*25),239,2);
 circle(319-(i*25),239,2) ;
}
for(i=1;i<=8;i++)
{
 circle(319,239-(i*25),2);
 circle(319,239+(i*25),2) ;
}
}

}

void id(int c,int c1)
{
float i;
char b[5];
setcolor(4);
outtextxy(314,244,(char *)"0");
if(c==6 && (c1!=7 && c1!=8))    //Only for trigo fns
{
for(i=PI;i<=4*PI;i+=PI)
{
 sprintf(b,"%0.2f",i);
 outtextxy(309+i*25,229,b);
 sprintf(b,"-%0.2f",i);
 outtextxy(309-i*25,229,b);
}
for(i=1;i<=8;i++)
{
 sprintf(b,"%0.0f",i);
 outtextxy(329,229-(i*25),b);
 sprintf(b,"-%0.0f",i);
 outtextxy(329,229+(i*25),b);
}
}
else if(c==7)   //For inverse trigo fns
{
for(i=1;i<=12;i++)
{
 sprintf(b,"%0.0f",i);
 outtextxy(309+(i*25),229,b);
 sprintf(b,"-%0.0f",i);
 outtextxy(309-(i*25),229,b);
}
for(i=PI;i<=3*PI;i+=PI)
{
 sprintf(b,"%0.2f",i);
 outtextxy(329,229-(i*25),b);
 sprintf(b,"-%0.2f",i);
 outtextxy(329,229+(i*25),b);
}
}
else    //For other entities
{
for(i=1;i<=12;i++)
{
 sprintf(b,"%0.0f",i);
 outtextxy(309+(i*25),229,b);
 sprintf(b,"-%0.0f",i);
 outtextxy(309-(i*25),229,b);
}
for(i=1;i<=8;i++)
{
 sprintf(b,"%0.0f",i);
 outtextxy(329,229-(i*25),b);
 sprintf(b,"-%0.0f",i);
 outtextxy(329,229+(i*25),b);
}
}
getch();
closegraph();
}
