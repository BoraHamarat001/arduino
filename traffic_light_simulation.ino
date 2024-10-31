//Simulate a traffic light system
//1 resistor and 3 LEDS pinned to 11,12,13
int redPin=13;
int yellowPin=12;
int greenPin=11;
int pins []={redPin,yellowPin,greenPin};
bool stopCalled = false;
bool goingCalled= false;
void setup()
{
  for(int i=0;i<sizeof(pins);i++){
    pinMode(pins[i],OUTPUT);
  }
  switchHigh(redPin,2000);
}
void switchHigh(int ledPin, int delayValue)
{
  digitalWrite(ledPin, HIGH);
  delay(delayValue); 
}
void switchLow(int ledPin, int delayValue)
{
  digitalWrite(ledPin, LOW);
  delay(delayValue);
}
void stop()
{
  switchLow(greenPin,400);
  switchHigh(yellowPin,1000);
  switchHigh(redPin,0);
  switchLow(yellowPin,0);
}
void going()
{
  switchHigh(yellowPin,2000);
  switchLow(redPin,0);
  switchLow(yellowPin,0);
  switchHigh(greenPin,0);
}
void loop()
{
  if (!goingCalled) {
    going();
    goingCalled = true;
    stopCalled = false;
    delay(5000);
  }
  if (!stopCalled) {
    stop();
    stopCalled = true;
    goingCalled = false;
    delay(5000);
  }
}