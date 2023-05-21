#include <Keypad.h>
#include <Servo.h>

Servo servo;
char* password = "1234D";
int unlockKey = 12;
int lockLed = 13;
int position = 0;
const byte ROWS = 4;
const byte COLS = 4;
char Keys[ROWS][COLS] = 
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {2, 3, 4, 5};
byte colPins[COLS] = {6, 7, 8, 9};

Keypad keypad = Keypad(makeKeymap(Keys), rowPins, colPins, ROWS, COLS); 

void setup()
{
  pinMode (lockLed, OUTPUT);
  pinMode (unlockKey, INPUT);
  servo.attach(11);
  Locked();
}
  
void loop()
{
  char key = keypad.getKey();
  if  (key == '*')
  {
    position = 0;
    Locked();
  }
  if (key == password[position])
  {
    position ++;
  }
  if (position == 5)
  {
    Unlocked();
  }
  if (key == '#')
  {
    Unlocked();
  }
  delay(50);
}
void Locked (void)
{

  digitalWrite(lockLed, HIGH);
  servo.write(0);
}
void Unlocked (void)
{
  digitalWrite(lockLed, LOW);
  servo.write(90);
}
