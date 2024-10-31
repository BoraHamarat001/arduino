//Control LEDS based on temperature value
const sensorPin=A0
const int greenPin=9;
const int redPin=10;
float temperature;
void setup()
{
  pinMode(greenPin,OUTPUT);
  pinMode(redPin,OUTPUT);
  Serial.begin(9600);  
}
void loop()
{
  int sensorValue = analogRead(sensorPin);
  float voltage = sensorValue * (5.0 / 1023.0);
  temperature = (voltage - 0.5) * 100;
  //Analog value -> voltage -> temperature 
  Serial.println(temperature);
  if (temperature < 30) {
    digitalWrite(greenPin, HIGH);  
    digitalWrite(redPin, LOW);     
  } else {
    digitalWrite(greenPin, LOW);  
    digitalWrite(redPin, HIGH);    
  }
  delay(1000);
}