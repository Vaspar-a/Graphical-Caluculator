#include<graphics.h>
#include<conio.h>
#include<math.h>
#define PI 3.14
float cl(float *,float *);
void gl(float ,float *,float *);
float cc(float *,float *);
void gc(float ,float *,float *);
void ce(float *,float *,float *,float *);
void ge(float *,float *,float *,float *);
void cp(float *,float *,float *,short int *);
void gp(float *,float *,float *,short int *);
void cf(float *,float *,float *,short int *);
void gf(float *,float *,float *,short int *);
short int ch(float *,float *,float *,float *);
void gh(float *,float *,float *,float *,short int *);
void cif(float *,short int *);
void gif(float *,float *,float *,float *,short int *);
void graph(short int *,short int *);
void id(short int *,short int *);
int main()
{
int gd = DETECT,gm;
short int c1,c;
float x,y,n=0,m=0;
printf("For line press 1\nFor circle press 2\nFor ellipse press 3\nFor parabola press 4\nFor hyperbola press 5\nFor trigonometric,logarithmic & exponential functions press 6\nFor inverse trigonometric functions press 7\n");
scanf("%d",&c);
switch(c)
{
case 1:
	n=cl(&x,&y);
	break;
case 2:
       n=cc(&x,&y);
	break;
case 3:
	ce(&x,&y,&n,&m);
	break;
case 4:
	cp(&x,&y,&n,&c1);
	break;
case 5:
       c1=ch(&x,&y,&n,&m);
	break;
case 6:
	cf(&x,&y,&n,&c1);
	break;
case 7:
	cif(&n,&c1);
	break;

}
clrscr();
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
graph(&c,&c1);
switch(c)
{
case 1:
	gl(n,&x,&y);
	break;
case 2:
	gc(n,&x,&y);
	break;
case 3:
	ge(&x,&y,&n,&m);
	break;
case 4:
	gp(&x,&y,&n,&c1);
	break;
case 5:
	gh(&x,&y,&n,&m,&c1);
	break;
case 6:
	gf(&x,&y,&n,&c1);
	break;
case 7:
	gif(&x,&y,&n,&m,&c1);
	break;

}
id(&c,&c1);
//MAX_H=639 MAX_V=479
getch();
closegraph();
return 0;
}

float cl(float *x,float *y)
{
float A,B,C;
clrscr();
printf("Enter equation of line as Ax + By + C = 0\n");
printf("\nEnter A:");
scanf("%f",&A);
fflush();
printf("\nEnter B:");
scanf("%f",&B);
fflush();
printf("\nEnter C:");
scanf("%f",&C);
fflush();
if(C==0)
	{
		*x=200;
		*y=(*x)*(-A/B);
		getch();
		return 0;
	}
else if(A==0)
{
	C/=B;
	*x=0;
	return -C;
}

else if(B==0)
{
	C/=A;
	*y=0;
	return -C;
}

else
	{
		*x=(-1)*((C/A)*25);
		*y=((C/B)*25);
		getch();
		return C;
	}
}

void gl(float n,float *x,float *y)
{
char b[20];
if(n==0)
	{
		line(*x+319,239-*y,319-*x,*y+239);
		setcolor(4);
		sprintf(b,"Slope=%0.2f",*y/(*x));
		outtextxy(469,19,b);
		outtextxy(469,29,"X-intercept=0");
		outtextxy(469,39,"Y-intercept=0");
	}
else if(*x==0)
{
	line(119,239-(25*n),519,239-(25*n));
	setcolor(4);
	outtextxy(469,19,"Slope=0");
	outtextxy(469,29,"X-intercept=0");
	sprintf(b,"Y-intercept=%0.2f",n);
	outtextxy(469,39,b);
}

else if(*y==0)
{
	line(319+(25*n),39,319+(25*n),439);
	setcolor(4);
	outtextxy(469,19,"Slope=INF");
	sprintf(b,"X-intercept=%0.2f",n);
	outtextxy(469,29,b);
	outtextxy(469,39,"Y-intercept=0");
}

else
	{
		line(*x+319,239,319,*y+239);
		moveto(*x+319,239);
		linerel(2*(*x),-2*(*y));
		moveto(319,*y+239);
		linerel(-2*(*x),2*(*y));
		setcolor(4);
		sprintf(b,"Slope=%0.2f",*y/(*x));
		outtextxy(469,19,b);
		sprintf(b,"X-intercept=%0.2f",(*x)/25);
		outtextxy(469,29,b);
		sprintf(b,"Y-intercept=%0.2f",(-1)*(*y)/25);
		outtextxy(469,39,b);
	}

}

float cc(float *h,float *k)
{
float r;
clrscr();
printf("Enter equation of circle as: (x-h)^2 + (y-k)^2 = r^2\n");
printf("Enter h:");
scanf("%f",h);
fflush();
printf("Enter k:");
scanf("%f",k);
fflush();
printf("Enter r:");
scanf("%f",&r);
fflush();
return r;
}

void gc(float n,float *x,float *y)
{
char b[25];
setcolor(BLUE);
(*x)=(*x)*25;
(*y)=(*y)*25;
circle(*x+319,239-*y,n*25);
setcolor(4);
sprintf(b,"Centre: (%0.2f,%0.2f)",*x/25,*y/25);
outtextxy(469,19,b);
sprintf(b,"Radius: %0.2f",n);
outtextxy(469,29,b);
}

void ce(float *h,float *k,float *a,float *b)
{
clrscr();
printf("Enter equation of ellipse as: (x-h)^2/a^2 + (y-k)^2/b^2 = 1\nEnter h:");
scanf("%f",h);
printf("Enter k:");
scanf("%f",k);
printf("Enter a:");
scanf("%f",a);
printf("Enter b:");
scanf("%f",b);
}

void ge(float *h,float *k,float *a,float *b)
{
char s[25];
*h*=25;
*k*=25;
*a*=25;
*b*=25;
ellipse(319+*h,239-*k,0,360,*a,*b);
setcolor(4);
if(*a>*b)
sprintf(s,"Eccentricity=%0.2f",sqrt(1-(*b/25**b/25)/(*a/25**a/25)));
else
sprintf(s,"Eccentricity=%0.2f",sqrt(1-(*a/25**a/25)/(*b/25**b/25)));
outtextxy(409,19,s);
if(*a>*b)
sprintf(s,"Foci:(%0.2f,%0.2f)(%0.2f,%0.2f)",*h/25-sqrt((*a/25**a/25)-(*b/25**b/25)),*k/25,*h/25+sqrt((*a/25**a/25)-(*b/25**b/25)),*k/25);
else
sprintf(s,"Foci:(%0.2f,%0.2f)(%0.2f,%0.2f)",*h/25,*k/25-sqrt((*b/25**b/25)-(*a/25**a/25)),*h/25,*k/25+sqrt((*b/25**b/25)-(*a/25**a/25)));
outtextxy(409,29,s);
if(*a>*b)
sprintf(s,"Eqn of drtx:x=%0.2f x=%0.2f",*h/25+(*a/25)/sqrt(1-(*b/25**b/25)/(*a/25**a/25)),*h/25-(*a/25)/sqrt(1-(*b/25**b/25)/(*a/25**a/25)));
else
sprintf(s,"Eqn of drtrx:y=%0.2f y=%0.2f",*k/25+(*b/25)/sqrt(1-(*a/25**a/25)/(*b/25**b/25)),*k/25-(*b/25)/sqrt(1-(*a/25**a/25)/(*b/25**b/25)));
outtextxy(409,39,s);
}

void cp(float *h,float *k,float *a,short int *c)
{
clrscr();
printf("For regular parabola press 1\nFor sideways parabola press 2\n");
scanf("%d",c);
clrscr();
switch(*c)
{
case 1:
	printf("Enter equation as: y = a(x-h)^2 + k\n");
	break;
case 2:
	printf("Enter equation as: x = a(y-k)^2 + h\n");
	break;
}
printf("Enter a:");
scanf("%f",a);
printf("Enter h:");
scanf("%f",h);
printf("Enter k:");
scanf("%f",k);
}


void gp(float *h,float *k,float *a,short int *c)
{
 float x,y,i;
 char b[25];
switch(*c)
{
case 1:
	for(i=*h-2;i<=*h+2;i+=0.00001)
	{
	x=i;
	y=*a*(x-*h)*(x-*h)+*k;
	x*=25;y*=25;
	putpixel(319+x,239-y,1);
	}
	setcolor(4);
	sprintf(b,"Focus: (%0.2f,%0.2f)",*h,*k+(1/(4**a)));
	outtextxy(469,19,b);
	sprintf(b,"Directrix: y=%0.2f",*k-(1/(4**a)));
	outtextxy(469,29,b);
	sprintf(b,"Axis of symm: x=%0.2f",*h);
	outtextxy(469,39,b);
	break;
case 2:
	for(i=*k-2;i<=*k+2;i+=0.00001)
	{
	y=i;
	x=*a*(y-*k)*(y-*k)+*h;
	x*=25;y*=25;
	putpixel(319+x,239-y,1);
	}
	setcolor(4);
	sprintf(b,"Focus: (%0.2f,%0.2f)",*h+(1/(4**a)),*k);
	outtextxy(469,19,b);
	sprintf(b,"Directrix: y=%0.2f",*h-(1/(4**a)));
	outtextxy(469,29,b);
	sprintf(b,"Axis of symm: y=%0.2f",*k);
	outtextxy(469,39,b);
	break;
}

}
short int ch(float *h,float *k,float *a,float *b)
{
short int c;
clrscr();
printf("For transverse axis as Y-axis press 1\nFor transverse axis as X-axis press 2\n");
scanf("%d",&c);
clrscr();
if(c==1)
	printf("Enter equation as: (y-k)^2/a^2 - (x-h)^2/b^2 =1\n");
else if(c==2)
	printf("Enter equation as: (x-h)^2/a^2 - (y-k)^2/b^2 =1\n");
printf("Enter h:");
scanf("%f",h);
printf("Enter k:");
scanf("%f",k);
printf("Enter a:");
scanf("%f",a);
printf("Enter b:");
scanf("%f",b);
return c;
}

void gh(float *h,float *k,float *a,float *b,short int *n)
{
char s[25];
float x,y,i;
switch(*n)
{
case 1:
	for(i=*h-4;i<=*h+4;i+=0.00001)
	{
		x=i;
		y=((*a**a)/(*b**b))*((x-*h)*(x-*h)+1);
		y=sqrt(y);
		y+=*k;
		x*=25;y*=25;
		putpixel(319+x,239-y,1);
	}

	for(i=*h-4;i<=*h+4;i+=0.00001)
	{
		x=i;
		y=((*a**a)/(*b**b))*((x-*h)*(x-*h)+1);
		y=-sqrt(y);
		y+=*k;
		x*=25;y*=25;
		putpixel(319+x,239-y,1);
	}
setcolor(4);
sprintf(s,"Eccentricity=%0.2f",sqrt(1+(*b/25**b/25)/(*a/25**a/25)));
outtextxy(409,19,s);
sprintf(s,"Foci:(%0.2f,%0.2f)(%0.2f,%0.2f)",*h/25,*k/25-sqrt((*b/25**b/25)+(*a/25**a/25)),*h/25,*k/25+sqrt((*b/25**b/25)+(*a/25**a/25)));
outtextxy(409,29,s);
sprintf(s,"Eqn of drtrx:y=%0.2f y=%0.2f",*k/25+(*b/25)/sqrt(1+(*b/25**b/25)/(*a/25**a/25)),*k/25-(*b/25)/sqrt(1+(*b/25**b/25)/(*a/25**a/25)));
outtextxy(409,39,s);

	break;
case 2:
	for(i=*h+1;i<=*h+4;i+=0.00001)
	{
		x=i;
	       y=((*b**b)/(*a**a))*((x-*h)*(x-*h)-1);
		y=sqrt(y);
		y+=*k;
		x*=25;y*=25;
		putpixel(319+x,239-y,1);
	}

	for(i=*h+1;i<=*h+4;i+=0.00001)
	{
		x=i;
		y=((*b**b)/(*a**a))*((x-*h)*(x-*h)-1);
		y=-sqrt(y);
		y+=*k;
		x*=25;y*=25;
		putpixel(319+x,239-y,1);
	}

	for(i=*h-4;i<=*h-1;i+=0.00001)
	{
		x=i;
	       y=((*b**b)/(*a**a))*((x-*h)*(x-*h)-1);
		y=sqrt(y);
		y+=*k;
		x*=25;y*=25;
		putpixel(319+x,239-y,1);
	}

	for(i=*h-4;i<=*h-1;i+=0.00001)
	{
		x=i;
		y=((*b**b)/(*a**a))*((x-*h)*(x-*h)-1);
		y=-sqrt(y);
		y+=*k;
		x*=25;y*=25;
		putpixel(319+x,239-y,1);
	}
setcolor(4);
sprintf(s,"Eccentricity=%0.2f",sqrt(1+(*b/25**b/25)/(*a/25**a/25)));
outtextxy(409,19,s);
sprintf(s,"Foci:(%0.2f,%0.2f)(%0.2f,%0.2f)",*h/25-sqrt((*a/25**a/25)+(*b/25**b/25)),*k/25,*h/25+sqrt((*a/25**a/25)+(*b/25**b/25)),*k/25);
outtextxy(409,29,s);
sprintf(s,"Eqn of drtx:x=%0.2f x=%0.2f",*h/25+(*a/25)/sqrt(1+(*b/25**b/25)/(*a/25**a/25)),*h/25-(*a/25)/sqrt(1+(*b/25**b/25)/(*a/25**a/25)));
outtextxy(409,39,s);

	break;
}

}

void cf(float *a,float *b,float *c,short int *n)
{
clrscr();
printf("For sin press 1\nFor cos press 2\nFor tan press 3\nFor cosec press 4\nFor sec press 5\nFor cot press 6\nFor log press 7\nFor exp press 8\n");
scanf("%d",n);
switch(*n)
	{
	case 1: clrscr();
		printf("Enter equation as: y = a*sin( bx + c )\n");
		break;

	case 2: clrscr();
		printf("Enter equation as: y = a*cos( bx + c )\n");
		break;

	case 3: clrscr();
		printf("Enter equation as: y = a*tan( bx + c )\n");
		break;

	case 4: clrscr();
		printf("Enter equation as: y = a*cosec( bx + c )\n");
		break;

	case 5: clrscr();
		printf("Enter equation as: y = a*sec( bx + c )\n");
		break;

	case 6: clrscr();
		printf("Enter equation as: y = a*cot( bx + c )\n");
		break;

	case 7: clrscr();
		printf("Enter equation as: y = a*log( bx + c )\n");
		break;

	case 8: clrscr();
		printf("Enter equation as: y = a*e^( bx + c )\n");
		break;
	}
printf("Enter a:");
scanf("%f",a);
printf("Enter b:");
scanf("%f",b);
printf("Enter c:");
scanf("%f",c);
}

void gf(float *a,float *b,float *c,short int *n)
{
float x,y,i,s=-2*PI,e=2*PI;
if(*n==7)
{
	s=0;
}
	for(i=s;i<=e;i+=0.00001)
	{
		x=*b*i+*c;
	switch(*n)
	{
	case 1:
		y=*a*sin(x);
		break;
	case 2:
		y=*a*cos(x);
		break;
	case 3:
		y=*a*tan(x);
		break;
	case 4:
		y=*a*(1/sin(x));
		break;
	case 5:
		y=*a*(1/cos(x));
		break;
	case 6:
		y=*a*(1/tan(x));
		break;
	case 7:
		y=*a*log(x);
		break;
	case 8:
		y=*a*exp(x);
		break;
	}

		x*=25;y*=25;
		putpixel(319+x,239-y,1);
	}
}

void cif(float *a,short int *n)
{
clrscr();
printf("For sin inverse press 1\nFor cos inverse press 2\nFor tan inverse press 3\nFor cosec inverse press 4\nFor sec inverse press 5\nFor cot inverse press 6\n");
scanf("%d",n);
switch(*n)
	{
	case 1: clrscr();
		printf("Enter equation as: y = a*sin^-1 (x)\n");
		break;

	case 2: clrscr();
		printf("Enter equation as: y = a*cos^-1 (x)\n");
		break;

	case 3: clrscr();
		printf("Enter equation as: y = a*tan^-1 (x)\n");
		break;

	case 4: clrscr();
		printf("Enter equation as: y = a*cosec^-1 (x)\n");
		break;

	case 5: clrscr();
		printf("Enter equation as: y = a*sec^-1 (x)\n");
		break;

	case 6: clrscr();
		printf("Enter equation as: y = a*cot^-1 (x)\n");
		break;
	}
printf("Enter a:");
scanf("%f",a);
}

void gif(float *x,float *y,float *a,float *i,short int *n)
{
	if(*n==4 || *n==5)
	{
		for(*i=-5;*i<=-1;*i+=0.00001)
		{
			*x=*i;
			if(*n==4)
				*y=*a*asin(1/(*x));
			else
				*y=*a*acos(1/(*x));
			*x*=25;*y*=25;
			putpixel(319+*x,239-*y,1);
		}
		for(*i=1;*i<=5;*i+=0.00001)
		{
			*x=*i;
			if(*n==4)
				*y=*a*asin(1/(*x));
			else
				*y=*a*acos(1/(*x));
			*x*=25;*y*=25;
			putpixel(319+*x,239-*y,1);
		}
	}
	else if(*n==1 || *n==2)
	{
		 for(*i=-1;*i<=1;*i+=0.00001)
		{
			*x=*i;
			if(*n==1)
				*y=*a*asin(*x);
			else
				*y=*a*acos(*x);
			*x*=25;*y*=25;
			putpixel(319+*x,239-*y,1);
		}
	}
	else if(*n==3 || *n==6)
	{
		for(*i=-5;*i<=5;*i+=0.00001)
		{
			*x=*i;
			if(*n==3)
				*y=*a*atan(*x);
			else
				*y=*a*atan(1/(*x));
			*x*=25;*y*=25;
			putpixel(319+*x,239-*y,1);
		}
	}

}

void graph(short int *c,short int *c1)
{
float i;
setbkcolor(WHITE);
setcolor(RED);
line(319,0,319,479);
line(0,239,639,239);
setcolor(BLUE);
circle(319,239,2);
if(*c==6 && *c1!=7 && *c1!=8)
{
for(i=PI;i<=4*PI;i+=PI)
{
 circle(319+i*25,239,2);
 circle(319-i*25,239,2) ;
}
for(i=1;i<=8;i++)
{
 circle(319,239-i*25,2);
 circle(319,239+i*25,2) ;
}
}
else if(*c==7)
{
for(i=1;i<=12;i++)
{
 circle(319+i*25,239,2);
 circle(319-i*25,239,2) ;
}
for(i=PI;i<=3*PI;i+=PI)
{
 circle(319,239-i*25,2);
 circle(319,239+i*25,2) ;
}
}
else
{
for(i=1;i<=12;i++)
{
 circle(319+i*25,239,2);
 circle(319-i*25,239,2) ;
}
for(i=1;i<=8;i++)
{
 circle(319,239-i*25,2);
 circle(319,239+i*25,2) ;
}
}
}

void id(short int *c,short int *c1)
{
float i;
char b[5];
setcolor(4);
outtextxy(314,244,"0");
if(*c==6 && *c1!=7 && *c1!=8)
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
 outtextxy(329,229-i*25,b);
 sprintf(b,"-%0.0f",i);
 outtextxy(329,229+i*25,b);
}
}
else if(*c==7)
{
for(i=1;i<=12;i++)
{
 sprintf(b,"%0.0f",i);
 outtextxy(309+i*25,229,b);
 sprintf(b,"-%0.0f",i);
 outtextxy(309-i*25,229,b);
}
for(i=PI;i<=3*PI;i+=PI)
{
 sprintf(b,"%0.2f",i);
 outtextxy(329,229-i*25,b);
 sprintf(b,"-%0.2f",i);
 outtextxy(329,229+i*25,b);
}
}
else
{
for(i=1;i<=12;i++)
{
 sprintf(b,"%0.0f",i);
 outtextxy(309+i*25,229,b);
 sprintf(b,"-%0.0f",i);
 outtextxy(309-i*25,229,b);
}
for(i=1;i<=8;i++)
{
 sprintf(b,"%0.0f",i);
 outtextxy(329,229-i*25,b);
 sprintf(b,"-%0.0f",i);
 outtextxy(329,229+i*25,b);
}
}
}
