#include <LiquidCrystal.h>
LiquidCrystal lcd(8,9,4,5,6,7);
String str1="",str2="";
boolean stringcomp=false;
int cnt=0;


void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Veri bekleniyor");
}
void SerialEvent()
{
  while(Serial.available())
  {
    char inChar=(char)Serial.read();
    cnt++;
    if(inChar=='\n')
      stringcomp=true;

    if(inChar=='*')
    {
      lcd.clear();
      str1="";
      str2="";
      stringcomp=true;
    }

    if(stringcomp==false && cnt<=16)
      str1+=inChar;

    if(stringcomp==false && cnt>16 && cnt<=32)
      str2+=inChar;
    }
  }

void loop() {
  lcd.setCursor(0,0);
  SerialEvent();
  if(stringcomp)
  {
    lcd.clear();
    lcd.print(str1);
    lcd.setCursor(0,1);
    lcd.print(str2);
    stringcomp=false;
    str1="";
    str2="";
    cnt=0;
  }
  delay(50);
  }


