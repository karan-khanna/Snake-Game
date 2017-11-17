#include<conio.h>
#include<graphics.h>
#include<stdio.h>
#include<dos.h>
#include<string.h>
#include<stdlib.h>
#include<process.h>
#include<stdio.h>
#include<iostream.h>
void ran_co();
void about();
void game_over();
void print_food();
void play();
void chk_food();
void sound();
void score(long fd );
int x1=20,x2=40,y1=30,y2=40;
int width=10;
int X1=x1,X2=x2,Y1=y1,Y2=y2;
int t=1;
int length=20;
int dir=1;
int m;
long sc ,fd;
char str[50];
int f_x ,f_y;
/***************************/
void maze_sample();
void bound_check();
void drawMenu (int  selected ,int defcol ,int selcol  );
int main_menu();
void snake_print();


void setting( );
void barprint(int a);
void drawprint(int maze,int speed,int color);
void textprint();
void print_maze(int );
char ch;
int row=1,maze=1,speed=3,color=1;


//*******************SETTINGS OPTION FROM MENU**********************

void setting()
{
int choice=1;
int gd=DETECT;
int gm;
initgraph(&gd,&gm,"c:\\tc\\bgi");
setbkcolor(0);
setlinestyle(4,0,5);
textprint();
check:

drawprint(maze,speed,color);
textprint();
while(ch=getch())
{
if(ch=='s')
{
++row;
if(row>3)
row=1;
}

else if(ch=='w')
{
--row;
if(row<1)
row=3;
}

else if(ch=='a')
{
switch(row)
{
case 1:--maze;
	if(maze<1)
	maze=4;
	break;
case 2:speed-=3;
	if(speed<3)
	speed=12;
	break;
case 3:--color;
	if(color<1)
	color=4;
	break;
default: goto check;
}
drawprint(maze,speed,color);
}

else if(ch=='d')
{
switch(row)
{
case 1:++maze;
	if(maze>4)
	maze=1;
	break;
case 2:speed+=3;
	if(speed>12)
	speed=3;
	break;
case 3:++color;
	if(color>4)
	color=1;
	break;
default: goto check;

}
drawprint(maze,speed,color);

}

else if(ch==' ')
break;
else
goto check;

}



}

void drawprint(int maze,int speed,int color)
{
int i;
int x=0;
for(i=1;i<=4;++i)
{
setfillstyle(9,WHITE);
if(i==maze)
{setfillstyle(1,LIGHTRED);
bar(270+x,150,340+x,210);
}
setcolor(BLACK);
rectangle(270+x,260,340+x,320);
bar(270+x,150,340+x,210);

x=x+90;
}

maze_sample();


x=0;
for(i=3;i<=12;i+=3)
{
setfillstyle(9,WHITE);
if(i==speed)
{setfillstyle(1,LIGHTRED);
bar(270+x,260,340+x,320);
}
setcolor(BLACK);
rectangle(270+x,260,340+x,320);
bar(270+x,260,340+x,320);

x=x+90;
}
x=0;
setfillstyle(1,0);
for(i=1;i<=4;++i)
{

setfillstyle(1,i);
bar(270+x,370,340+x,430);

if(i==color)
{
setfillstyle(1,15);
fillellipse(305+x,400,10,10);
}
x=x+90;
}


textprint();

}

void textprint()
{
setcolor(RED);
settextstyle(1,0,6);
setfillstyle(1,15);
bar(0,20,getmaxx(),100);
outtextxy(getmaxx()/2-120,30,"SETTINGS");
setcolor(CYAN);
settextstyle(2,0,4);
outtextxy(200,getmaxy()-20,"PRESS SPACEBAR TO SAVE THE SETTINGS AND EXIT....");
settextstyle(1,0,4);
outtextxy(50,160,"1.MAZE--->");
outtextxy(50,270,"2.SPEED-->");
outtextxy(50,380,"3.COLOUR->");
setcolor(0);
settextstyle(8,0,3);
outtextxy(275,270,"SLOW");
settextstyle(8,0,3);
outtextxy(370,270,"MED.");
outtextxy(455,270,"FAST");
outtextxy(545,260,"VERY");
settextstyle(8,0,3);
outtextxy(545,285,"FAST");



}





/*********************/



void main()
{


int gd=DETECT;
int gm;

char ch,ch1;



 x1=20,x2=40,y1=30,y2=40;
 width=10;
 X1=x1,X2=x2,Y1=y1,Y2=y2;
 t=1;
 length=20;
 dir=1;
 m=0;

 row=1,maze=1,speed=3,color=1;
 sc=0 ,fd=0;

initgraph(&gd,&gm,"C:\\TC\\BGI");
cleardevice();

int x = 180;
int y = 180;
setcolor(RED);
settextstyle(7,0,4);
outtextxy(x,y," PRESENTING ");
delay(1000);
cleardevice();
settextstyle(7,0,2);
outtextxy(x,y-100," PRESENTING");
delay(1000);

settextstyle(4,0,6);
setcolor(15);
outtextxy(x-50,y," S N A K E");
delay(1000);
cleardevice();



a:
int selected =main_menu();

switch(selected)
{
 case 1:  cleardevice();
	  score(fd);
	  play();
	  goto a;
	  break;
 case 2:  cleardevice();
	  setcolor(RED);
	  settextstyle(1,0,6);
	  setfillstyle(1,15);
	  bar(0,20,getmaxx(),100);
	  outtextxy(getmaxx()/2-70,30,"HELP");
	  settextstyle(2,0,7);
	  setcolor(12);
	  outtextxy(0,130,"SNAKE MOVEMENTS");
	  for(int i=0;i<2;i++)
	  {
	    bar(150,180+(i*50),180,210+(i*50));
	    bar(420,180+(i*50),450,210+(i*50));
	  }
	    setcolor(0);
	    settextstyle(1,0,2);
	    outtextxy(160,180,"w");
	    outtextxy(430,180,"s");
	    outtextxy(160,230,"a");
	    outtextxy(430,230,"d");
	    setcolor(CYAN);
	    outtextxy(200,180,"  <--  UP ");
	    outtextxy(470,180,"  <--  DOWN ");
	    outtextxy(200,230,"  <--  LEFT ");
	    outtextxy(470,230,"  <--  RIGHT ");

	    settextstyle(2,0,7);
	    setcolor(12);
	    outtextxy(0,270,"INSTRUCTIONS");
	    setcolor(CYAN);
	    settextstyle(2,0,5);

	    outtextxy(150,300," >>Use above mentioned keys to control snake . ");
	    outtextxy(150,330," >>Use any key except (A,W,D,S)keys to pause game.");
	    outtextxy(150,360," >>Don't hit the white boundary or boxes in any maze.");
	    outtextxy(150,390," >>Select different maze ,speed and color from settings.");
	    settextstyle(2,0,5);
	    setcolor(12);
	    outtextxy(200,430,"Press any key to continue.....");

	  getch();
	  goto a;
	  break;
 case 3:  cleardevice();
	  setting();
	  goto a;

	  break;

 case 4:  about();
	  outtextxy(getmaxx()/2-140,getmaxy()/2+20,"KARAN KHANNA");
	  delay(1000);
	  about();
	  outtextxy(getmaxx()/2-30,getmaxy()/2+20,"&");
	  delay(1000);
	  about();
	  outtextxy(getmaxx()/2-140,getmaxy()/2+20,"AYUSHI JAIN");
	  delay(1000);
	  about();
	  settextstyle(7,0,3);

	  outtextxy(200,getmaxy()/2-20,"KARAN KHANNA");
	
	  outtextxy(400,getmaxy()/2+40,"&");
	  outtextxy(450,getmaxy()/2+70,"AYUSHI JAIN");
	  settextstyle(2,0,5);
	  setcolor(12);
	  outtextxy(200,430,"Press any key to continue.....");

	  getch();
	  goto a;
 case 5: exit(0);

	 cleardevice();
	 closegraph();

	 break;

 default:goto a;
	 break;
}



getch();
cleardevice();
closegraph();
}


void about()
{
	  cleardevice();
	  setcolor(RED);
	  settextstyle(1,0,6);
	  setfillstyle(1,15);
	  bar(0,20,getmaxx(),100);
	  outtextxy(getmaxx()/2-80,30,"ABOUT");
	  settextstyle(2,0,7);
	  setcolor(12);
	  outtextxy(0,150,"PROGRAMMED BY");
	  settextstyle(7,0,5);
	  setcolor(CYAN);



}

void play()
{
//print_maze(maze);

ran_co();
//delay(20);
b:
//chk_food();
print_maze(maze);
print_food();
score(fd);
a:
while(!kbhit())
{
chk_food();
setfillstyle(INTERLEAVE_FILL,color);
setcolor(color);
if(dir==1)
{

bound_check();


if((X2-X1)<=length)
{
if(x2==627 && x2>x1)
{

x1=x1+speed;
}

if(t==1)
{

X2=X2+speed;
if(y2>Y2)
y2=y2-speed;

}
else if(t==2)
{
if(y1<Y1)
y1=y1+speed;
X2=X2+speed;
}
snake_print();
chk_food();
}
else
{
x2=X2;
y2=Y2;
y1=Y1;
x1=X1;

X1=X1+speed;
X2=X2+speed;
snake_print();
chk_food();

}
setfillstyle(1,15);
fillellipse(X2-4,Y2-8,2,2);
fillellipse(X2-4,Y2-4,2,2);
delay(20);

setfillstyle(1,0);
bar(x1,y1,x2,y2);
bar(X1,Y1,X2,Y2);
bound_check();
m=1;
goto a;
}

if(dir==2)
{
if((Y2-Y1)<=length)
{

if(y1==23 && y2>y1)
{

y2=y2-speed;
}


if(t==1)
{
Y1=Y1-speed;
if(x1<X1)
x1=x1+speed;
}
else if(t==2)
{

Y1=Y1-speed;
if(x2>X2)
x2=x2-speed;
}
snake_print();
chk_food();
}
else
{
x1=X1;
y1=Y1;
x2=X2;
y2=Y2;

Y1=Y1-speed;
Y2=Y2-speed;

snake_print();
chk_food();
}

setfillstyle(1,15);
fillellipse(X1+4,Y1+4,2,2);
fillellipse(X1+8,Y1+4,2,2);

delay(20);

setfillstyle(1,0);
bar(x1,y1,x2,y2);

bar(X1,Y1,X2,Y2);
bound_check();
m=2;
goto a;
}


if(dir==3)
{


if((X2-X1)<=length)
{

if(x1==13 && x2>x1)
{


x2=x2-speed;
}


if(t==1)
{


X1=X1-speed;
if(y2>Y2)
y2=y2-speed;
}
else if(t==2)
{
if(y1<Y1)
y1=y1+speed;
X1=X1-speed;

}
snake_print();
chk_food();
}
else
{

x1=X1;
y1=Y1;
x2=X2;
y2=Y2;

X1=X1-speed;
X2=X2-speed;
snake_print();
chk_food();

}

setfillstyle(1,15);
fillellipse(X1+4,Y1+4,2,2);
fillellipse(X1+4,Y1+8,2,2);


delay(20);
setfillstyle(1,0);
bar(x1,y1,x2,y2);
bar(X1,Y1,X2,Y2);

bound_check();
m=3;
goto a;
}


if(dir==4)
{
if((Y2-Y1)<=length)
{

if(y2==getmaxy()-13 && y1<y2)
{


y1=y1+speed;
}



if(t==1)
{
if(x1<X1)
x1=x1+speed;
Y2=Y2+speed;

}
else if(t==2)
{

if(x2>X2)
x2=x2-speed;
Y2=Y2+speed;

}
snake_print();
chk_food();
}
else
{
x1=X1;
x2=X2;
y1=Y1;
y2=Y2;

Y1=Y1+speed;
Y2=Y2+speed;

snake_print();
chk_food();

}
setfillstyle(1,15);
fillellipse(X2-4,Y2-4,2,2);
fillellipse(X2-8,Y2-4,2,2);


delay(20);

setfillstyle(1,0);
bar(x1,y1,x2,y2);


bar(X1,Y1,X2,Y2);
bound_check();

m=4;
goto a;
}

}

x1=X1;
y1=Y1;
x2=X2;
y2=Y2;

if(kbhit())
ch=getch();
switch(ch)
{
case 'w':
case 'W':dir=2;
	if(m!=2 && m!=4)
	{
	if(m==1)
	 {
	 X1=x2-width;
	 Y1=y1;
	 X2=x2;
	 Y2=y2;
	 t=1;
	 goto a;
	 }
	 else if(m==3)
	 {
	 X2=x1+width;
	 Y2=y1+width;
	 X1=x1;
	 Y1=y1;
	 t=2;
	 goto a;
	 }
	 }
	 else
	 goto a;
	 break;

case 'd':
case 'D':dir=1;
	if(m!=1 && m!=3)
	{
	if(m==2)
	 {
	 X1=x1;
	 Y1=y1;
	 X2=x1+width;
	 Y2=y1+width;
	 t=1;
	 goto a;
	 }

	 else if(m==4)
	 {
	 t=2;
	 X1=x1;
	 X2=x2;
	 Y2=y2;
	 Y1=y2-width;
	 goto a;
	 }
	 }
	 else
	 goto a;
	 break;

case 'a':
case 'A':dir=3;
	if(m!=3 && m!=1)
	{

	 if(m==2)
	 {
	 X1=x1;
	 Y1=y1;
	 X2=x1+width;
	 Y2=y1+width;
	 t=1;
	 goto a;
	 }
	 else if(m==4)
	 {
	 X1=x2-width;
	 Y1=y2-width;
	 X2=x2;
	 Y2=y2;
	 t=2;
	 goto a;
	 }
	 }
	 else
	 goto a;
	 break;

case 's':
case 'S':dir=4;
	if(m!=4 && m!=2)
	{
	if(m==1)
	 {
	 X1=x2-width;
	 Y1=y1;
	 X2=x2;
	 Y2=y2;
	 t=1;
	 goto a;
	 }
	 else if(m==3)
	 {
	 X1=x1;
	 Y1=y1;
	 X2=x1+width;
	 Y2=y1+width;
	 t=2;
	 goto a;
	 }
	 }
	 else
	 goto a;
	 break;

default :  cleardevice();
	   setbkcolor(0);
	   setcolor(4);
	   int midx=getmaxx()/2,midy=getmaxy()/2;
	   rectangle(midx-150,midy-80,midx+150,midy+80);
	   rectangle(midx-154,midy-84,midx+154,midy+84);
	   settextstyle(0,0,2);
	   outtextxy(midx-100,midy-20," GAME PAUSE  ");
	   setcolor(12);
	   settextstyle(2,0,5);
	   outtextxy(midx-120,midy+20,"Press Any Key To Resume Playing....");
	    getch();
	    cleardevice();
	    goto b;



}

}


    void ran_co()
  {



      randomize();

      a:
     // f_x=X2+50;f_y=Y1;
     f_x=rand()%1000; f_y=rand()%1000;

      if((f_x<25 || f_x>615)|| (f_y<35 || f_y>455) || getpixel(f_x+1,f_y+1)==color ||getpixel(f_x+1,f_y+1)== 15 ||getpixel(f_x+16,f_y)== 15 ||getpixel(f_x,f_y+8)== 15 ||getpixel(f_x,f_y-15)== 15 ||getpixel(f_x-16,f_y)== 15 )

      goto a;
   }
   void clear_food()
   {
	 setcolor(BLACK);
	 setfillstyle(SOLID_FILL,BLACK);
	 fillellipse(f_x,f_y,7,7);
	 fillellipse(f_x+8,f_y,7,7);
	 bar(f_x+3,f_y-3,f_x+4,f_y-13);

   }
   void print_food()
   {

	 setcolor(RED);
	 setfillstyle(SOLID_FILL,RED);
	 fillellipse(f_x,f_y,7,7);
	 fillellipse(f_x+8,f_y,7,7);

	setfillstyle(SOLID_FILL,GREEN);
	bar(f_x+3,f_y-3,f_x+4,f_y-13);

   }
 void chk_food()
{
     int i;
     switch(dir)
   {
     case 1: for( i=Y1;i<=Y2;i++)
	     {
	       if(getpixel(X2+1,i)==4 || getpixel(X2+1,i)==GREEN)
	       {
	       sound();
	       clear_food();
	       setcolor(15);
	       ran_co();
	       print_food();
	       score(++fd);
	       length+=5;

	       break;
	       }

	       else	  if(getpixel(X2+1,i)==15)
		  game_over();
	     }
	       break;
     case 2: for( i=X1;i<=X2;i++)
	     {
	       if(getpixel(i,Y1-1)==GREEN || getpixel(i,Y1-1)==4)
	       {
	       sound();
	       clear_food();
	       ran_co();
	       print_food();
	       score(++fd);
	       length+=5;

	       break;
	       }
	       else	 if(getpixel(i,Y1-1)==15)
		 game_over();
	     }
	       break;
    case 3:    for( i=Y1;i<=Y2;i++)
	     {
	       if(getpixel(X1-1,i)==GREEN || getpixel(X1-1,i)==4)
	       {
	       sound();
	       clear_food();
	       ran_co();
	       print_food();
	       length+=5;
	       score(++fd);
	       break;
	       }
	       else	if(getpixel(X1-1,i)==15)
		game_over();
	     }
	       break;

    case 4:   for( i=X1;i<=X2;i++)
	     {
	       if(getpixel(i,Y2+1)==GREEN || getpixel(i,Y2+1)==4)
	       {
	       sound();
	       clear_food();

	       ran_co();
	       print_food();
	       length+=5;
	       score(++fd);
	       break;
	       }
	       else if(getpixel(i,Y2+1)==15)
	       game_over();

	     }
	     break;
   }


}
   void sound()
   {
    sound(660);
    delay(30);
    nosound();

   }

   void score(long f)
 {

	 setfillstyle(SOLID_FILL,BLACK);
	 bar(0,0,getmaxx(),19);

	 setcolor(4);
	 setfillstyle(SOLID_FILL,RED);
	 fillellipse(15,10,7,7);
	 fillellipse(15+8,10,7,7);

	 setfillstyle(SOLID_FILL,GREEN);
	 bar(18,7,19,0);
	 setcolor(15);
	 settextstyle(2,0,5);
	 outtextxy(400,0," SCORE :");
	 char s[10];
	 char fd[10];
       //	  fd[1]='\0';
	 sprintf(fd,"%ld",f);
	 sc=f*5;

	 sprintf(s,"%ld",sc);
	 setfillstyle(SOLID_FILL,0);
	 outtextxy(50,0,fd);
	 outtextxy(500,0,s);


 }

 void game_over()
 {
   delay(1000);
   char s[1];
   cleardevice();
   setbkcolor(0);
   setcolor(4);
   int midx=getmaxx()/2,midy=getmaxy()/2;
   rectangle(midx-150,midy-80,midx+150,midy+80);
   rectangle(midx-154,midy-84,midx+154,midy+84);
   settextstyle(0,0,2);
   sprintf(s,"%ld",sc);
   outtextxy(midx-100,midy-30," YOUR SCORE  ");
   outtextxy(midx-20,midy,s);


   delay(2000) ;
  // getch();

   cleardevice();
   setbkcolor(0);
   setcolor(4) ;
   settextstyle(3,0,8);
   outtextxy(80,120," GAME OVER ");
   delay(1000);
   closegraph();

   main();

 }

 /***************************/

int main_menu ()
{
int ch;
int selected = 1;
int TotalOptions = 5;

cleardevice();
setbkcolor ( BLACK );
drawMenu ( selected , CYAN , LIGHTRED );
do
{
ch = getch();
if ( ch == 80 )
{
selected = selected >= TotalOptions ? 1 : selected + 1;
drawMenu ( selected , CYAN , LIGHTRED );
}
else if ( ch == 72 )
{
selected = selected < 2 ? TotalOptions : selected - 1;
drawMenu ( selected , CYAN , LIGHTRED );
}

}while ( ch != 13 );

return selected;
}

void drawMenu ( int selected , int defCol , int selCol )
{

int x = 230;
int y = 200;

int h = 30;
int i;
int TotalOptions = 5;
char menu_option[5][14]= {
			  " PLAY     ",
			  " HELP     ",
			  " SETTINGS ",
			  " ABOUT ",
			  " EXIT     "
			 };

cleardevice();


setfillstyle(WIDE_DOT_FILL,LIGHTRED);
setcolor(LIGHTRED);
bar(0,50,getmaxx(),150);
line(0,60,getmaxx(),60);
line(0,140,getmaxx(),140);
line(10,50,10,150);
line(getmaxx()-10,50,getmaxx()-10,150);
setcolor(15);
settextstyle(4,0,7);
outtextxy(150,60,"S N A K E");
for ( i = 1; i <= TotalOptions; i++ )
{
int tri[6]={x,y+10,x,y+40,x+15,y+25};
if ( i == selected )
{

setcolor (  selCol );
setfillstyle(INTERLEAVE_FILL,selCol);

}
else
{
setfillstyle(SOLID_FILL,0);
bar(x,y,x+15,y+40);
setcolor ( defCol );
setfillstyle(EMPTY_FILL,defCol);
}
fillpoly(3,tri);
settextstyle(7,0,3);
outtextxy ( x + 20 , y + 10 , menu_option[i - 1] );
y = y + h + 15;
sound(2020);
delay(20);
nosound();

}
}




void print_maze(int m_num)
{
int i=0;
	//    cleardevice();
	    setcolor(14);
	    setbkcolor(0);
	    rectangle(10,20,630,getmaxy()-10);
	    setcolor(15);
	    setfillstyle(SOLID_FILL,15);
  switch(m_num)
  {
    case 1: setcolor(15);
	    for(i=0;i<5;++i)
	    rectangle(10+i,20+i,630-i,getmaxy()-10-i);

	    break;
    case 2:
	    for(i=0;i<400;i=i+200)
	    {
	      bar(10,80+i,530,110+i);
	      bar(80,180+i,630,210+i);
	    }
	    break;

    case 3:
	    bar(170,120,470,370);
	    setfillstyle(SOLID_FILL,0);
	    bar(200,150,440,340);
	    bar(270,120,370,370);
	    bar(170,195,470,295);
	    setfillstyle(SOLID_FILL,15);
	    for(i=0;i<=400;i=i+200)
	    bar(295,20+i,345,70+i);
	    bar(10,220,60,270);
	    bar(295,220,345,270);
	    bar(580,220,630,270);


	    break;

    case 4:
	     for( i=0;i<=400;i=i+200)
	    {
	      bar(95+i,20,125+i,190);
	      bar(95+i,470,125+i,300);
	      if(i<400)
	      bar(180+i,220,235+i,270);
	    }

	      break;


  }

}


void snake_print()
{

setfillstyle(INTERLEAVE_FILL,color);
setcolor(color);
//snake's body
bar(X1,Y1,X2,Y2);
bar(x1,y1,x2,y2);
rectangle(X1,Y1,X2,Y2);
rectangle(x1,y1,x2,y2);
}

void bound_check()
{

if(X2>=627 && dir==1)
{
x2=627;
x1=X1;
y1=Y1;
y2=Y2;
X1=11;
X2=20;
}
else if(dir==2 && Y1<=23)
{
y1=23;
x1=X1;
x2=X2;
y2=Y2;
Y2=getmaxy()-11;
Y1=getmaxy()-20;
}

else if(dir==3 && X1<=13)
{
x1=13;
x2=X2;
y1=Y1;
y2=Y2;
X2=629;
X1=620;
}


else if(dir==4 && Y2>=getmaxy()-13)
{
y2=getmaxy()-13;
y1=Y1;
x1=X1;
x2=X2;
Y1=21;
Y2=30;
}

}

void maze_sample()
{
setfillstyle(1,15);
setcolor(15);
//MAZE 1 SAMPLE
for(int j=0;j<5;++j)
rectangle(275+j,155+j,335-j,205-j);

//MAZE 2 SAMPLE
rectangle(362,153,428,207);
bar(362,160,410,164);
bar(380,172,428,176);
bar(362,184,410,188);
bar(380,196,428,200);

//MAZE 3 SAMPLE
rectangle(452,153,518,207);
for(j=0;j<=46;j=j+23)
bar(480,153+j,490,160+j);
bar(452,176,460,183);
bar(510,176,518,183);

bar(470,168,473,176);
bar(496,168,499,176);
bar(470,182,473,190);
bar(496,182,499,190);
bar(470,168,477,171);
bar(491,168,499,171);
bar(470,187,477,190);
bar(491,187,499,190);

//MAZE 4 SAMPLE
rectangle(542,153,608,207);
for(j=0;j<=44;j=j+22)
bar(551+j,153,555+j,172);
for(j=0;j<=44;j=j+22)
bar(551+j,188,555+j,207);

bar(560,177,567,182);
bar(582,177,589,182);


}