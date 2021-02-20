#include <AFMotor.h> 
#define ECHOPIN 2
#define TRIGPIN 3

AF_DCMotor motor1(1); 
AF_DCMotor motor2(4); 

//char command; 
//int x=1;
void setup() 
{ 
Serial1.begin(9600); //Set the baud rate to your Bluetooth module. 
pinMode(ECHOPIN,INPUT);
pinMode(TRIGPIN,OUTPUT);// put your setup code here, to run once:

} 

void loop(){
  Serial1.begin(9600);
 //Stop(); 
//if(x==1){
if(Serial1.available() > 0){ 
char command = Serial1.read();
Serial.print(command);

Stop(); //initialize with motors stoped 
//Change pin mode only if new command is different from previous. 
Serial.println(command); 
switch(command){ 
case '1':
Serial.print(command);
forward(); 

break; 
case '2': 
back();
break; 
case '3': 
fleft(); 
break; 
case '4': 
fright(); 
break; 
case '5': 
Stop(); 
break; 
case '6': 
bank(); 
break; 
case '7': 
market(); 
break; 
case '8': 
park(); 
break; 
//case '9': 
//stadium(); 
//break; 
case 'S': 
school(); 
break; 
//case 'M': 
//mosque(); 
//break; 

/*case 'G': 
fleft(); 
break; 
case 'I': 
fright(); 
break; 
case 'H': 
bleft(); 
break; 
case 'J': 
bright(); 
break; 
*/

} 
}
//}
} 
void bank()
{int i;
  for (i=0;i<=10000;i++)
{//checkus();
  forward();
if (i==5000)
{Serial1.println("No Left Turn Sign Ahead");}
}
Stop();
delay(2000);
int j;
for (j=0;j<=4200;j++)
{fleft();}
int y;
for (y=0;y<=10000;y++)
{//checkus();
  forward();}
Stop();
delay(2000);
int k;
for (k=0;k<=4200;k++)
{fleft();}
int h;
for (h=0;h<=5000;h++)
{//checkus();
  forward();
if(h==2000)
{Serial1.println("Zebra Cross Sign Ahead");
}
}
Stop();
delay(3000);
//checkus();
int a;
for (a=0;a<=4100;a++)
{fright();}
int b;
for (b=0;b<=2000;b++)
{//checkus();
  forward();}

destStop();
}

void market()
{int i;
  for (i=0;i<=10000;i++)
{//checkus();
  forward();
if (i==10000)
{Serial1.println("No Left Turn Sign Ahead");}}
Stop();
delay(2000);

int j;
for (j=0;j<=4200;j++)
{fleft();}
int y;
for (y=0;y<=7000;y++)
{//checkus();
  forward();}
Stop();
delay(2000);

int l;
for (l=0;l<=4200;l++)
{fleft();}
int m;
for (m=0; m<=5000;m++)
{//checkus();
  forward();}
Stop();
delay(2000);

int z;
for (z=0;z<=4200;z++)
{fleft();}
int p;
for (p=0;p<=2000;p++)
{//checkus();
  forward();
if (p==5000)
{Serial1.println("Cyclists present sign ahead");}
}
destStop();
}
void school()
{int i;
  for (i=0;i<=5000;i++)
{////checkus();
  forward();
/*if (i==5000)
Serial1.write('g');
*/}
Stop();
delay(2000);
int j;
for (j=0;j<=4100;j++)
{fright();}
int y;
for (y=0;y<=5000;y++)
{////checkus();
  forward();}
destStop();
}

void park()
{int i;
  for (i=0;i<=5000;i++)
{//checkus();
  forward();
/*if (i==5000)
Serial1.write('g');
*/}
destStop();
}


void forward() 
{
motor2.setSpeed(0); //Define maximum velocity 
motor2.run(RELEASE); //rotate the motor clockwise 
motor1.setSpeed(100); //Define maximum velocity 
motor1.run(FORWARD); //rotate the motor clockwise 

}
void back() 
{ 
motor1.setSpeed(100); 
motor1.run(BACKWARD); //rotate the motor counterclockwise 
//motor2.setSpeed(255); 
//motor2.run(BACKWARD); //rotate the motor counterclockwise 
} 

/*void left() 
{ 
//motor1.setSpeed(255); //Define maximum velocity 
//motor1.run(FORWARD); //rotate the motor clockwise 
motor2.setSpeed(255); 
motor2.run(BACKWARD); //turn motor2 off 
} 

void right() 
{ 
//motor1.setSpeed(0); 
//motor1.run(RELEASE); //turn motor1 off 
motor2.setSpeed(255); //Define maximum velocity 
motor2.run(FORWARD); //rotate the motor clockwise 
} */
void fright() 
{ 
//motor1.setSpeed(0); 
//motor1.run(RELEASE); //turn motor1 off 
////checkus();
motor1.setSpeed(100); //Define maximum velocity 
motor1.run(FORWARD); //rotate the motor clockwise 
motor2.setSpeed(255); //Define maximum velocity 
motor2.run(FORWARD); //rotate the motor clockwise 
 
}
void fleft() 
{ 
//motor1.setSpeed(0); 
//motor1.run(RELEASE); //turn motor1 off 
////checkus();
motor1.setSpeed(100); //Define maximum velocity 
motor1.run(FORWARD); //rotate the motor clockwise 
motor2.setSpeed(255); //Define maximum velocity 
motor2.run(BACKWARD); //rotate the motor clockwise 
 
}
/*void bright() 
{ 
//motor1.setSpeed(0); 
//motor1.run(RELEASE); //turn motor1 off 
motor1.setSpeed(255); //Define maximum velocity 
motor1.run(BACKWARD); //rotate the motor clockwise 
momtor2.setSpeed(255); //Define maximum velocity 
motor2.run(FORWARD); //rotate the motor clockwise 
} 
void bleft() 
{ 
//motor1.setSpeed(0); 
//motor1.run(RELEASE); //turn motor1 off 
motor1.setSpeed(255); //Define maximum velocity 
motor1.run(BACKWARD); //rotate the motor clockwise 
motor2.setSpeed(255); //Define maximum velocity 
motor2.run(BACKWARD); //rotate the motor clockwise 
} 
*/
void Stop() 
{ 
motor1.setSpeed(0); 
motor1.run(RELEASE); //turn motor1 off 
motor2.setSpeed(0); 
motor2.run(RELEASE); //turn motor2 off 
}

void destStop() 
{ //x=0;
motor1.setSpeed(0); 
motor1.run(RELEASE); //turn motor1 off 
motor2.setSpeed(0); 
motor2.run(RELEASE); //turn motor2 off 
Serial1.println("destination reached");
Serial1.end();
}

/*void checkus()
{ digitalWrite(TRIGPIN,LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN,HIGH);
  delayMicroseconds(5);
  digitalWrite(TRIGPIN,LOW);
float distance=pulseIn(ECHOPIN,HIGH);
distance=distance/58;
Serial.print(distance);
if (distance<60)
{Serial1.println("Object detected with in collision range");
Stop();
//checkus();
}
else if (distance >)
{Serial1.println("ultrasonic error");
  //checkus();
}
}*/
