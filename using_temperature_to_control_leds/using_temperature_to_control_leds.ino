//Arduino code to control an LED depending on the temperature value
int TempPin = A0; //Temperature sensor connected to analog pin 0 on the arduino
int RedLedPin = 3; // Red led connected to pin 3 on the arduino
int RedLedPin2 = 4;
int RedLedPin3 = 5;
int RedLedPin4 = 6;
int GreenLedPin = 7; //Gren led connected to pin 7 on the arduino
int GreenLedPin2 = 8;
int GreenLedPin3 = 9;
int BlueLedPin = 10;  //Blue pin connected to pin 10 on the arduino
int BlueLedPin2 = 11;
int WhiteLedPin = 12;
int temp; // initialization of the variable 'temp'
int Celsius;
void setup() {
  pinMode(TempPin,INPUT); //declares the temperature pin is an input
  Serial.begin(9600);  //initializes the serial monitor
  pinMode(RedLedPin,OUTPUT); //declares the red led as an output
  pinMode(RedLedPin2,OUTPUT);
  pinMode(RedLedPin3,OUTPUT);
  pinMode(RedLedPin4,OUTPUT);
  pinMode(GreenLedPin,OUTPUT);
  pinMode(GreenLedPin2,OUTPUT);
  pinMode(GreenLedPin3,OUTPUT);
  pinMode(BlueLedPin,OUTPUT);
  pinMode(BlueLedPin2,OUTPUT);
  pinMode(WhiteLedPin,OUTPUT);

}

void loop() {
  GetTemp(); //function to get the temperature
  LightRedLed(); // function to light up the led
  LightBlueLed();
  LightGreenLed();
  LightWhiteLed();
}
void GetTemp(){
  temp = analogRead(TempPin); // reads the value from the temperature sensor
  Celsius = int(temp-694); // calibrates this particular temperature sensor to degrees celsius
  Serial.println("Degree in Celsius is: ");
  Serial.println(Celsius); // prints the temperature value to the serial monitor
  delay(1000); // delay of 1000 milliseconds
}
void LightRedLed(){
  if (Celsius >= 23){
    digitalWrite(RedLedPin,HIGH); // if the temperature is greater or equal than 23 degrees the red led lights
    digitalWrite(RedLedPin2,HIGH);
    digitalWrite(RedLedPin3,HIGH);
    digitalWrite(RedLedPin4,HIGH);
    delay(1000);
  }
   else
    digitalWrite(RedLedPin,LOW); // otherwise the red led goes off
    digitalWrite(RedLedPin2,LOW);
    digitalWrite(RedLedPin3,LOW);
    digitalWrite(RedLedPin4,LOW);
    delay(1000);
  }
void LightBlueLed(){
  if (5 <= Celsius <= 17){ // if temperature is between 5 and 17 degrees celcius the blue led lights
    digitalWrite(BlueLedPin,HIGH);
    digitalWrite(BlueLedPin2,HIGH);
    delay(1000);
  }
   else
     digitalWrite(BlueLedPin,LOW); // otherwise the blue led goes off
     digitalWrite(BlueLedPin2,LOW);
     delay(1000);
}
void LightGreenLed(){
  if ( 18 <= Celsius <= 22){ // if temperature is between 18 and 22 deegres celsius the green led lights
    digitalWrite(GreenLedPin,HIGH);
    digitalWrite(GreenLedPin2,HIGH);
    digitalWrite(GreenLedPin3,HIGH);
    delay(1000);
  }
  else
    digitalWrite(GreenLedPin,LOW); //otherwise the green led goes off
    digitalWrite(GreenLedPin2,LOW);
    digitalWrite(GreenLedPin3,LOW);
    delay(1000);
}
void LightWhiteLed(){
  if ( -5 <= Celsius <=5){
    digitalWrite(WhiteLedPin,HIGH); // if the temperature is between -5 and 5 degrees celsius the white led lights
    delay(1000);
}
  else
   digitalWrite(WhiteLedPin,LOW); // otherwise the white led goes off
   delay(1000);
}
