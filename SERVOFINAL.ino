const int intrig =3;
const int inecho =2; 

const int led = 13;

const int outrig=11;
const int outecho=12;

long Induration;
int Indistance;
long Outduration;
int Outdistance;
char c;
String voice = "";
//entering garage
int flagin=0;  //gate
int flagout=0;  //d5el 3la OUT ultrasonic

//leaving garage
int flagin2=0;  //gate
int flagout2=0;   //d5el 3la IN ultrasonic

int emptyspaces=4; //slots



//Servo
#include <Servo.h>
Servo gate;

#include <LiquidCrystal_I2C.h> // Library for LCD

/* Create object named lcd of the class LiquidCrystal */
LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows





void setup() {
  Serial.begin(9600);
  pinMode(intrig, OUTPUT);
  pinMode(inecho, INPUT);
  pinMode(outrig, OUTPUT);
  pinMode(outecho, INPUT);

  pinMode(led,OUTPUT);  

  gate.attach(10); //pi`n 10
  gate.write(0);

  lcd.init(); //initialize the lcd
  lcd.backlight(); //open the backlight 

}


void loop() 
{
  Serial.flush(); 
  digitalWrite(intrig,LOW); //IN ultrasonic reading
  delayMicroseconds(2);
  digitalWrite(intrig,HIGH);
  delayMicroseconds(10);
  digitalWrite(intrig,LOW);
  Induration =pulseIn(inecho,HIGH);
  Indistance = Induration * 0.034/2;
  Serial.println(Indistance);


  digitalWrite(outrig,LOW); //OUT ultrasonic reading
  delayMicroseconds(2);
  digitalWrite(outrig,HIGH);
  delayMicroseconds(10);
  digitalWrite(outrig,LOW);
  Outduration =pulseIn(outecho,HIGH);
  Outdistance = Outduration * 0.034/2;
  Serial.println(Outdistance);

    
   if (emptyspaces>=1 && emptyspaces<=4) //gate will open 
   {
     if ( Indistance >= 2 && Indistance < 6) //car is near the first ultrasonic for in 
    {
      if (Serial.available()>0)  //take bluetooth module reading to open the gate
      {
      Serial.flush();
      voice=Serial.readString();
      Serial.print(voice+'\n');
      }
      if (voice=="open" || voice== "Open")
      {
      //digitalWrite(led,HIGH);
      gate.write(90);                                                            //gate opens 
      flagin=1;
      voice=""; 
      }
      voice="";
    }
     
    if (Outdistance >= 2 && Outdistance < 6 && flagin==1)                       //3da el gate
      flagout=1;                                                                //d5el 3la tani ultrasonic
    
                                                                                //gate opened && d5el 3la tani ultrasonic (ana da5el el garage)
    else if (flagin ==1 && flagout ==1)
    {
      delay (100);
      gate.write(0); //gate closes
      emptyspaces--;
      digitalWrite(led,LOW);
      flagin =0;
      flagout=0;
    }
   }

   //////////////////////////////////////////////////////////////////////////////////

   if (emptyspaces>=0 && emptyspaces<4) //0-3 empty spaces
   {

      if ( Outdistance >= 2 && Outdistance < 6) //car is near the first ultrasonic for out
      {
        if (Serial.available()>0)  //take bluetooth module reading to open the gate
        {
        Serial.flush();
        voice=Serial.readString();
        Serial.print(voice+'\n');
        }
        if (voice=="open" || voice== "Open")
        {
        digitalWrite(led,HIGH);
        gate.write(90);  //gate opens 
        //Serial.print("worked");
        flagin2=1;
        voice=""; 
        }
        voice="";
      }
      
      if (Indistance >= 2 && Indistance < 6 && flagin2==1) //3da el gate 
        flagout2=1; //d5al 3la ultrasonic in
      
      //leaving the garage
      else if (flagin2 ==1 && flagout2 ==1)
      {
        delay (100);
        gate.write(0);
        emptyspaces++;
        digitalWrite(led,LOW);
        flagin2 =0;
        flagout2 =0;
      }

   }
  
if (emptyspaces >=1 && emptyspaces<=4)
{
  lcd.clear();
  lcd.setCursor(4,0);       /* Set cursor to column 0 row 0 */
  lcd.print("Welcome!");        /* Print data on display */
  lcd.setCursor(0,1);  
  lcd.print("Empty Slots: ");
  lcd.print(emptyspaces);
}

else if (emptyspaces == 0)
{
  lcd.clear();
  lcd.setCursor(5,0);   
  lcd.print("Sorry!");
  lcd.setCursor(0,1);
  lcd.print("No Empty Slots!");
}
 
  delay(100);
}
