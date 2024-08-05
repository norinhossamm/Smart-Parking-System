const int trigpin1 =3;
const int echopin1 =2;
const int redpin1 = A5;
const int greenpin1 = A4;

const int trigpin2 =5;
const int echopin2 =4;
const int redpin2 = A3;
const int greenpin2 = A2;

const int trigpin3 =7;
const int echopin3 =6;
const int redpin3 = A1;
const int greenpin3 = A0;

const int trigpin4 =9;
const int echopin4 =8;
const int redpin4 = 13;
const int greenpin4 = 12;

long duration1;
int distance1;
int flag1; 

long duration2;
int distance2;
int flag2;

long duration3;
int distance3;
int flag3;

long duration4;
int distance4;
int flag4;

//int led = 6;
int threshold = 5;

void setup() {
  // put your setup code here, to run once:

  pinMode(trigpin1, OUTPUT);
  pinMode(echopin1, INPUT);
  pinMode(greenpin1, OUTPUT);
  pinMode(redpin1, OUTPUT);

  pinMode(trigpin2, OUTPUT);
  pinMode(echopin2, INPUT);
  pinMode(greenpin2, OUTPUT);
  pinMode(redpin2, OUTPUT);

  pinMode(trigpin3, OUTPUT);
  pinMode(echopin3, INPUT);
  pinMode(greenpin3, OUTPUT);
  pinMode(redpin3, OUTPUT);

  pinMode(trigpin4, OUTPUT);
  pinMode(echopin4, INPUT);
  pinMode(greenpin4, OUTPUT);
  pinMode(redpin4, OUTPUT);

  Serial.begin(9600);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  digitalWrite(trigpin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin1, LOW);

  duration1 = pulseIn(echopin1, HIGH);
  distance1 = duration1 * 0.034/2;
Serial.println(distance1);
  digitalWrite(trigpin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin2, LOW);

  duration2 = pulseIn(echopin2, HIGH);
  distance2 = duration2 * 0.034/2;

  digitalWrite(trigpin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin3, LOW);

  duration3 = pulseIn(echopin3, HIGH);
  distance3 = duration3 * 0.034/2;

  digitalWrite(trigpin4, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin4, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin4, LOW);

  duration4 = pulseIn(echopin4, HIGH);
  distance4 = duration4 * 0.034/2;


if (distance1>0 && distance1<=threshold)
{
  flag1 = 1;
  digitalWrite(greenpin1,LOW);
  digitalWrite(redpin1,HIGH);
}

else if (distance1==0)
{
  if (flag1==1)
  {
    digitalWrite(greenpin1,LOW);
    digitalWrite(redpin1,HIGH);
 }

  else if (flag1 ==0)
    {digitalWrite(greenpin1,HIGH);
    digitalWrite(redpin1,LOW);
    }

}
else
{
  flag1 =0;
   digitalWrite(greenpin1,HIGH);
   digitalWrite(redpin1,LOW);

}

////////////////////////////////////////////

if (distance2>0 && distance2<=threshold)
{
  flag2 = 1;
  digitalWrite(greenpin2,LOW);
  digitalWrite(redpin2,HIGH);
}

else if (distance2==0)
{
  if (flag2==1)
    {digitalWrite(greenpin2,LOW);
    digitalWrite(redpin2,HIGH);
    }

  else if (flag2 ==0)
    {digitalWrite(greenpin2,HIGH);
    digitalWrite(redpin2,LOW);}
}

else
{
  flag2 =0;
   digitalWrite(greenpin2,HIGH);
   digitalWrite(redpin2,LOW);
}

////////////////////////////////////////

if (distance3>0 && distance3<=threshold)
{
  flag3 = 1;
  digitalWrite(greenpin3,LOW);
      digitalWrite(redpin3,HIGH);

}

else if (distance3==0)
{
  if (flag3==1)
    {digitalWrite(greenpin3,LOW);
        digitalWrite(redpin3,HIGH);
}

  else if (flag3 ==0)
    {digitalWrite(greenpin3,HIGH);
        digitalWrite(redpin3,LOW);
}
}
else
{
  flag3 =0;
   digitalWrite(greenpin3,HIGH);
   digitalWrite(redpin3,LOW);
}

////////////////////////////////////////

if (distance4>0 && distance4<=threshold)
{
  flag4 = 1;
  digitalWrite(greenpin4,LOW);
  digitalWrite(redpin4,HIGH);
 
}

else if (distance4==0)
{
  if (flag4==1)
    {digitalWrite(greenpin4,LOW);
    digitalWrite(redpin4,HIGH);
    }

  else if (flag4 ==0)
    {digitalWrite(greenpin4,HIGH);
    digitalWrite(redpin4,LOW);}
}
else
{
  flag4 =0;
   digitalWrite(greenpin4,HIGH);
   digitalWrite(redpin4,LOW);
}

}