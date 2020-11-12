
#include <Stepper.h>

#include <Ultrasonic.h>
Ultrasonic ultrasonic1(A0 ,A1 ,12000);
Ultrasonic ultrasonic2(A2 ,A3 ,10000);

int arraysize = 96;  //quantity of values to find the median (sample size). Needs to be an odd number
int rangevalue[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0};    

int count=0;
const int stepsPerRevolution = 96;  // change this to fit the number of steps per revolution
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);
int stepCount = 0;         // number of steps the motor has taken
int distance;
int distance2;
int x1=0,y1=0,x2=0,y2=0;
int z=0;
int t1=0;
int a=0,b=0;

int m1=0,n1=0,m2=0,n2=0;
int y=0;
int t2=0;
int c=0,d=0;

int p1=0,q1=0,p2=0,q2=0;
int x=0;
int t3=0;
int e=0,f=0;

int r1=0,s1=0,r2=0,s2=0;
int w=0;
int t4=0;
int g=0,h=0;


int spd=0,spd1=0,spd2=0,spd3=0,spd4=0;
int distance1 ;
int t;
char s;

void setup() 
{
  delay(5);
  pinMode(2,OUTPUT);
  pinMode(4,OUTPUT);
  Serial.begin (115200); //SERIAL
}

void loop() 
//---------------------------Main for loop starts----------------------------------//
{
  digitalWrite(2,HIGH);
  digitalWrite(4,HIGH);
  for(int i = 1; i <= arraysize; i++)
  {
         delay(13);
         distance=ultrasonic1.Ranging(CM); 
         myStepper.step(1);
         rangevalue[i] = distance;
       //  distance2=ultrasonic2.Ranging(CM);
       //  Serial.println(distance2);
       //  Serial.print(i);
         //Serial.print("-");
         //Serial.print(rangevalue[i]);
         //Serial.print("  ");
         
  distance2=ultrasonic2.Ranging(CM);
  if(i%14==0 && s!=0 )
  {
      //Serial.print("speed-");
      Serial.print(s);
      //Serial.print("turn @");
      Serial.print(t);
      Serial.print(".");
      Serial.print(distance2);
      Serial.println();
      Serial.flush();
      }
//      delay(1);

    //  if(i==35){
     //delay(3000);}
  if(rangevalue[i] <=11)
  {count++;
    }
  
         if(rangevalue[i] > 11 && rangevalue[i-1] <= 11 && rangevalue[i-2] <= 11 && rangevalue[i-3] <= 11&& rangevalue[i-4] <= 11
         && rangevalue[i-5] <= 11 && i>1  && i!=96 )
          {//Serial.print("start");
            i=0;
            //Serial.println();
            }     


 

//delay(18); 




}
//--------------------------Main for loop ends----------------------------------//

{
//------------------------------calculations starts here------------------------------//
//------------------------------ circle stage 35 starts-------------------------------//
{
for( int j=26 ; j<=35 ; j++)
    {if(rangevalue[j] <= 35 )
   {x1=j;
    }
    }
for( int j=35 ; j>=26 ; j--)
    {if(rangevalue[j] <= 35)
   {x2=j;
    }
    }
for( int j=44 ; j>=35 ; j--)
    {if(rangevalue[j] <= 35)
   {y1=j;
    }
    }
for( int j=35 ; j<=44 ; j++)
    {if(rangevalue[j] <= 35 )
   {y2=j;
    }
    }


if(x1==0 && x2==0 && y1==0 && y2 ==0)
{t1=35;}


   
if((x1!=0 && x2!=0) || (y1!=0 && y2!=0))
  {
    if( x1!=0 && x2!=0)
   {for( z=x2-1 ; z>=5 ; z--)
    {
  if(rangevalue[z] > 35 && rangevalue[z-1] > 35 && rangevalue[z-2] > 35 && rangevalue[z-3] > 35 && rangevalue[z-4] > 35
  && rangevalue[z-5] > 35 && rangevalue[z-6] > 35 && rangevalue[z-7] > 35 && rangevalue[z-8] > 35 && rangevalue[z-9] > 35
  && rangevalue[z-10] > 35 && rangevalue[z-11] > 35 && rangevalue[z-12] > 35 && rangevalue[z-13] > 35 && rangevalue[z-14] > 35
  && rangevalue[z-15] > 35 && rangevalue[z-16] > 35 && rangevalue[z-17] > 35 && rangevalue[z-18] > 35)
   {a=z-7;
    break;
    }
    }
   }
   else 
   {for( z=y1-1 ; z>=5 ; z--)
    {
  if(rangevalue[z] > 35 && rangevalue[z-1] > 35 && rangevalue[z-2] > 35 && rangevalue[z-3] > 35 && rangevalue[z-4] > 35
  && rangevalue[z-5] > 35 && rangevalue[z-6] > 35 && rangevalue[z-7] > 35 && rangevalue[z-8] > 35 && rangevalue[z-9] > 35
  && rangevalue[z-10] > 35 && rangevalue[z-11] > 35 && rangevalue[z-12] > 35 && rangevalue[z-13] > 35 && rangevalue[z-14] > 35
   && rangevalue[z-15] > 35 && rangevalue[z-16] > 35 && rangevalue[z-17] > 35 && rangevalue[z-18] > 35)
   {a=z-7;
    break;
    }
    }
    }


  if(y1 !=0 && y2 !=0)
  { 
  for( z=y2+1 ; z<=70 ; z++)
    {
  if(rangevalue[z] > 35 && rangevalue[z+1] > 35 && rangevalue[z+2] > 35 && rangevalue[z+3] > 35 && rangevalue[z+4] > 35
  && rangevalue[z+5] > 35 && rangevalue[z+6] > 35 && rangevalue[z+7] > 35 && rangevalue[z+8] > 35 && rangevalue[z+9] > 35
  && rangevalue[z+10] > 35 && rangevalue[z+11] > 35 && rangevalue[z+12] > 35 && rangevalue[z+13] > 35 && rangevalue[z+14] > 35
  && rangevalue[z+15] > 35 && rangevalue[z+16] > 35 && rangevalue[z+17] > 35 && rangevalue[z+18] > 35)
   {b=z+7;
    break;
    }
    }
  }
  else
  {for( z=x1+1 ; z<=70 ; z++)
    {
  if(rangevalue[z] > 35 && rangevalue[z+1] > 35 && rangevalue[z+2] > 35 && rangevalue[z+3] > 35 && rangevalue[z+4] > 35
  && rangevalue[z+5] > 35 && rangevalue[z+6] > 35 && rangevalue[z+7] > 35 && rangevalue[z+8] > 35 && rangevalue[z+9] > 35
  && rangevalue[z+10] > 35 && rangevalue[z+11] > 35 && rangevalue[z+12] > 35 && rangevalue[z+13] > 35 && rangevalue[z+14] > 35
  && rangevalue[z+15] > 35 && rangevalue[z+16] > 35 && rangevalue[z+17] > 35 && rangevalue[z+18] > 35)
   {b=z+7;
    break;
    }
    }
    }
    
  }
  }
//------------------------------ circle stage 35 ends-------------------------------//


//------------------------------ circle stage 80 starts-------------------------------//
{
for( int j=31 ; j<=35 ; j++)
    {if(rangevalue[j] <= 80 )
   {m1=j;
    }
    }
for( int j=35 ; j>=31 ; j--)
    {if(rangevalue[j] <= 80)
   {m2=j;
    }
    }
for( int j=39 ; j>=35 ; j--)
    {if(rangevalue[j] <= 80)
   {n1=j;
    }
    }
for( int j=35 ; j<=39 ; j++)
    {if(rangevalue[j] <= 80)
   {n2=j;
    }
    }


if(m1==0 && m2==0 && n1==0 && n2 ==0)
{t2=35;}

   
if((m1!=0 && m2!=0) || (n1!=0 && n2!=0))
  {
    if( m1!=0 && m2!=0)
   {for( y=m2-1 ; y>=5 ; y--)
    {
  if(rangevalue[y] > 80 && rangevalue[y-1] > 80 && rangevalue[y-2] > 80 && rangevalue[y-3] > 80 && rangevalue[y-4] > 80
  && rangevalue[y-5] > 80 && rangevalue[y-6] > 80 && rangevalue[y-7] > 80 && rangevalue[y-8] > 80)
   {c=y-3;
    break;
    }
    }
   }
   else 
   {for( y=n1-1 ; y>=5 ; y--)
    {
  if(rangevalue[y] > 80 && rangevalue[y-1] > 80 && rangevalue[y-2] > 80 && rangevalue[y-3] > 80 && rangevalue[y-4] > 80
  && rangevalue[y-5] > 80 && rangevalue[y-6] > 80 && rangevalue[y-7] > 80 && rangevalue[y-8] > 80)
   {c=y-3;
    break;
    }
    }
    }


  if(n1 !=0 && n2 !=0)
  { 
  for( y=n2+1 ; y<=70 ; y++)
    {
  if(rangevalue[y] > 80 && rangevalue[y+1] > 80 && rangevalue[y+2] > 80 && rangevalue[y+3] > 80 && rangevalue[y+4] > 80
  && rangevalue[y+5] > 80 && rangevalue[y+6] > 80 && rangevalue[y+7] > 80 && rangevalue[y+8] > 80)
   {d=y+3;
    break;
    }
    }
  }
  else
  {for( y=m1+1 ; y<=70 ; y++)
    {
  if(rangevalue[y] > 80 && rangevalue[y+1] > 80 && rangevalue[y+2] > 80 && rangevalue[y+3] > 80 && rangevalue[y+4] > 80
  && rangevalue[y+5] > 80 && rangevalue[y+6] > 80 && rangevalue[y+7] > 80 && rangevalue[y+8] > 80)
   {d=y+3;
    break;
    }
    }
    }
    
  }
  }
//------------------------------ circle stage 80 ends-------------------------------//



//------------------------------ circle stage 120 starts-------------------------------//
{
for( int j=32 ; j<=35 ; j++)
    {if(rangevalue[j] <= 120 )
   {p1=j;
    }
    }
for( int j=35 ; j>=32 ; j--)
    {if(rangevalue[j] <= 120)
   {p2=j;
    }
    }
for( int j=38 ; j>=35 ; j--)
    {if(rangevalue[j] <= 120)
   {q1=j;
    }
    }
for( int j=35 ; j<=38 ; j++)
    {if(rangevalue[j] <= 120)
   {q2=j;
    }
    }


if(p1==0 && p2==0 && q1==0 && q2 ==0)
{t3=35;}

   
if((p1!=0 && p2!=0) || (q1!=0 && q2!=0))
  {
    if( p1!=0 && p2!=0)
   {for( x=p2-1 ; x>=5 ; x--)
    {
  if(rangevalue[x] > 120 && rangevalue[x-1] > 120 && rangevalue[x-2] > 120 && rangevalue[x-3] > 120 && rangevalue[x-4] > 120 
  && rangevalue[x-5] > 120 && rangevalue[x-6] > 120)
   {e=x-2;
    break;
    }
    }
   }
   else 
   {for( x=q1-1 ; x>=5 ; x--)
    {
  if(rangevalue[x] > 120 && rangevalue[x-1] > 120 && rangevalue[x-2] > 120 && rangevalue[x-3] > 120 && rangevalue[x-4] > 120
  && rangevalue[x-5] > 120 && rangevalue[x-6] > 120)
   {e=x-2;
    break;
    }
    }
    }


  if(q1 !=0 && q2 !=0)
  { 
  for( x=q2+1 ; x<=70 ; x++)
    {
  if(rangevalue[x] > 120 && rangevalue[x+1] > 120 && rangevalue[x+2] >120 && rangevalue[x+3] > 120 && rangevalue[x+4] >120
  && rangevalue[x+5] > 120 && rangevalue[x+6] >120)
   {f=x+2;
    break;
    }
    }
  }
  else
  {for( x=p1+1 ; x<=70 ; x++)
    {
  if(rangevalue[x] > 120 && rangevalue[x+1] > 120 && rangevalue[x+2] > 120 && rangevalue[x+3] > 120 && rangevalue[x+4] >120
  && rangevalue[x+5] > 120 && rangevalue[x+6] >120)
   {f=x+2;
    break;
    }
    }
    }
}
}
//------------------------------ circle stage 120 ends-------------------------------//



//------------------------------ circle stage 160 starts-------------------------------//
{
for( int j=33 ; j<=35 ; j++)
    {if(rangevalue[j] <= 160 )
   {r1=j;
    }
    }
for( int j=35 ; j>=33 ; j--)
    {if(rangevalue[j] <= 160)
   {r2=j;
    }
    }
for( int j=37 ; j>=35 ; j--)
    {if(rangevalue[j] <= 160)
   {s1=j;
    }
    }
for( int j=35 ; j<=37 ; j++)
    {if(rangevalue[j] <= 160)
   {s2=j;
    }
    }


if(r1==0 && r2==0 && s1==0 && s2 ==0)
{t4=35;}

   
if((r1!=0 && r2!=0) || (s1!=0 && s2!=0))
  {
    if( r1!=0 && r2!=0)
   {for( w=r2-1 ; w>=5 ; w--)
    {
  if(rangevalue[w] > 160 && rangevalue[w-1] > 160 && rangevalue[w-2] > 160 && rangevalue[w-3] > 160 && rangevalue[w-4] > 160)
   {g=w-1;
    break;
    }
    }
   }
   else 
   {for( w=s1-1 ; w>=5 ; w--)
    {
  if(rangevalue[w] > 160 && rangevalue[w-1] > 160 && rangevalue[w-2] > 160 && rangevalue[w-3] > 160 && rangevalue[w-4] > 160)
   {g=w-1;
    break;
    }
    }
    }


  if(s1 !=0 && s2 !=0)
  { 
  for( w=s2+1 ; w<=70 ; w++)
    {
  if(rangevalue[w] > 160 && rangevalue[w+1] > 160 && rangevalue[w+2] > 160 && rangevalue[w+3] > 160 && rangevalue[w+4] > 160 )
   {h=w+1;
    break;
    }
    }
  }
  else
  {for( w=r1+1 ; w<=70 ; w++)
    {
  if(rangevalue[w] > 160 && rangevalue[w+1] > 160 && rangevalue[w+2] > 160 && rangevalue[w+3] > 160 && rangevalue[w+4] > 160)
   {h=w+1;
    break;
    }
    }
    }
  
}
}

// //------------------------------ circle stage 160 ends-------------------------------// //
  }

//--------------------------speed from 1-4----------------------------------//
{
  if(t1==35 && t2==35 && t3==35 && t4==35)
 {spd=1;
  s= 'a';
  t=35;
  }
  else if(t1==35 && t2==35 && t3==35 && t4==0)
 {spd=2;
  s='b';
  if(abs(35-g) > abs(h-35))
    {t=h;
    }
    else
    {t=g;
      }
  }
  else if(t1==35 && t2==35 && t3==0 && t4==0)
 {spd=3;
  s='c';
  if(abs(35-e) > abs(f-35))
    {t=f;
    }
    else
    {t=e;
      }
  }
  else if(t1==35 && t2==0 && t3==0 && t4==0)
 {spd=4;
  s='d';
  if(abs(35-c) > abs(d-35))
    {t=d;
    }
    else
    {t=c;
      }
  }
  else
  {spd=0;
   s='e';
    if(abs(35-a) > abs(b-35))
    {t=b;
    }
    else
    {t=a;
      }
    }
}

//--------------------------calculations ends here---------------------------//

//---------------------------printing--------------------------------//
//Serial.println(); 
//Serial.print(count);
//Serial.print("speed rank :------- ");
//Serial.println(spd);
//Serial.print("---------------circle range 35--------------");
//Serial.print("x1-");
//Serial.println(x1);
//Serial.print("x2-");
//Serial.println(x2);
//Serial.print("y1-");
//Serial.println(y1);
//Serial.print("y2-");
//Serial.println(y2);
//Serial.print("t1-");
//Serial.println(t1);
//Serial.print("a-");
//Serial.println(a);
//Serial.print("b-");
//Serial.println(b);
//Serial.println("---------------circle range 80--------------");
//Serial.print("m1-");
//Serial.println(m1);
//Serial.print("m2-");
//Serial.println(m2);
//Serial.print("n1-");
//Serial.println(n1);
//Serial.print("n2-");
//Serial.println(n2);
//Serial.print("t2-");
//Serial.println(t2);
//Serial.print("c-");
//Serial.println(c);
//Serial.print("d-");
//Serial.println(d);
//Serial.println("---------------circle range 120--------------");
//Serial.print("p1-");
//Serial.println(p1);
//Serial.print("p2-");
//Serial.println(p2);
//Serial.print("q1-");
//Serial.println(q1);
//Serial.print("q2-");
//Serial.println(q2);
//Serial.print("t3-");
//Serial.println(t3);
//Serial.print("e-");
//Serial.println(e);
//Serial.print("f-");
//Serial.println(f);
//Serial.println("---------------circle range 160--------------");
//Serial.print("r1-");
//Serial.println(r1);
//Serial.print("r2-");
//Serial.println(r2);
//Serial.print("s1-");
//Serial.println(s1);
//Serial.print("s2-");
//Serial.println(s2);
//Serial.print("t4-");
//Serial.println(t4);
//Serial.print("g-");
//Serial.println(g);
//Serial.print("h-");
//Serial.println(h);
//Serial.print("speed-");
Serial.print(s);
//Serial.print("turn @");
Serial.print(t);
Serial.print(".");
Serial.print(distance2);
Serial.println();
Serial.flush();

//----------------------------variables clean up-------------------------//
count=0;
spd=0;
spd1=0;
spd2=0;
spd3=0;
spd4=0;


x1=0;
y1=0;
x2=0;
y2=0;
z=0;
t1=0;
a=0;
b=0;

m1=0;
n1=0;
m2=0;
n2=0;
y=0;
t2=0;
c=0;
d=0;

p1=0;
q1=0;
p2=0;
q2=0;
x=0;
t3=0;
e=0;
f=0;


r1=0;
s1=0;
r2=0;
s2=0;
w=0;
t4=0;
g=0;
h=0;

//t=0;
//s=0;
}
