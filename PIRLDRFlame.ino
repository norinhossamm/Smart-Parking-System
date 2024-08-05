//Using PIR in the morning only and lighting the garage at night
int inputPin = 2;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status

int buzzer = 5;

int LED = 6; //flame sensor LED

int LED1= 8; //LDR,PIR leds 
int LED2 = 9;
int LED3 = 10;
int LED4 = 11;

int flame_sensor = A4;

int flame_detected;
 
void setup() {
  pinMode(LED, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare sensor as input

  pinMode(buzzer, OUTPUT);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

  pinMode(flame_sensor, INPUT);
 
  Serial.begin(9600);
}
 
void loop(){
  int SensorValue= analogRead(A5);
  Serial.println(SensorValue);
  delay(1000);
  if (SensorValue<100)
  {
    Serial.println("Its not dark");
      digitalWrite(LED1, LOW);  // turn LED OFF
      digitalWrite(LED2, LOW); 
      digitalWrite(LED3, LOW); 
      digitalWrite(LED4, LOW); 
    val = digitalRead(inputPin);  // read input value
    if (val == HIGH) {            // check if the input is HIGH
      digitalWrite(LED1, HIGH);  // turn LED ON
      digitalWrite(LED2, HIGH); 
      digitalWrite(LED3, HIGH); 
      digitalWrite(LED4, HIGH); 

      delay(4000);  // delay to keep the lamp on for some time?
      //if (pirState == LOW) {
        // we have just turned on
       // Serial.println("Motion detected!");
        // We only want to print on the output change, not state
       // pirState = HIGH;
     // }
    }
    else {
      digitalWrite(LED1, LOW);  // turn LED OFF if no motion detected and it's light
      digitalWrite(LED2, LOW); 
      digitalWrite(LED3, LOW); 
      digitalWrite(LED4, LOW); 
      //if (pirState == HIGH){
        // we have just turned of
       // Serial.println("Motion ended!");
        // We only want to print on the output change, not state
       // pirState = LOW;
      //}
    }
  }
  else
  {
    Serial.println("Its dark");//for ldr if it's dark
      digitalWrite(LED1, HIGH);  // turn LED ON
      digitalWrite(LED2, HIGH); 
      digitalWrite(LED3, HIGH); 
      digitalWrite(LED4, HIGH); 
  }


  flame_detected = analogRead(flame_sensor);

  Serial.println(flame_detected);

  if (flame_detected < 1010)

  {

    Serial.println("Flame detected...! take action immediately.");

    digitalWrite(buzzer, HIGH);

    digitalWrite(LED, HIGH);

  }

  else 

  {
    Serial.println("No flame detected. stay cool");

    digitalWrite(buzzer, LOW);

    digitalWrite(LED, LOW);
  }


}
