//Turn the LED on or off based on the state of the button.
//LED to pin 13
//pin 7 to h10 in board
//button as terminal 1a to e8 in board
//registor as terminal 1 is to d10
//5V -> b8 , GND -> c14
int button=7;
int led=13;
void setup()
{
  pinMode(led,OUTPUT);
  pinMode(button,INPUT);
  Serial.begin(9600);
}
void loop()
{
  if(digitalRead(button)==HIGH && digitalRead(led)==HIGH){
    digitalWrite(led,LOW);
  }
  else if(digitalRead(button)==HIGH && digitalRead(led)==LOW){
    digitalWrite(led,HIGH);
  }
}