#include "DS3231.h"
#include "LiquidCrystal.h"
 
DS3231 rtc;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

bool switched_on = false;
bool last_state;

int relay_port = 8;
int pushbutton_pin = 7;
int lcd_light_pin = 9;

String get_date_and_time () {

  //get current date and time
  RTCDateTime date_and_time = rtc.getDateTime();

  //variable only to manipulate time the way I need
  String current_time;

  if (date_and_time.hour < 10) {
    current_time = "0";
    current_time = current_time + date_and_time.hour;
  } else {
    current_time = date_and_time.hour;
  }

  current_time = current_time + ":";

  if (date_and_time.minute < 10) {
    current_time = current_time + "0";
    current_time = current_time + date_and_time.minute;
  } else {
    current_time = current_time + date_and_time.minute;
  }

  current_time = current_time + ":";

  if (date_and_time.second < 10) {
    current_time = current_time + "0";
    current_time = current_time + date_and_time.second;
  } else {
    current_time = current_time + date_and_time.second;
  }

  return current_time;

}

void lcd_printing(String current_time, String msg) {

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(current_time);
  lcd.setCursor(13, 0);
  lcd.print(msg);

}

void setup() {
  
  Serial.begin(9600);
  
  rtc.begin();
  rtc.setDateTime(__DATE__, __TIME__);

  lcd.begin(16, 2);
  
  pinMode(relay_port, OUTPUT);
  pinMode(lcd_light_pin, OUTPUT);

  digitalWrite(lcd_light_pin, LOW);
  
}
 
void loop() {

  switched_on = digitalRead(pushbutton_pin);

  if (!switched_on) {

    last_state = !last_state;
    while (!digitalRead(pushbutton_pin)) {} //aguarda soltar botão
    delay(50);
    
  }
  
  if (last_state == HIGH) {

    digitalWrite(lcd_light_pin, HIGH);
    lcd.display();

  } else {

    digitalWrite(lcd_light_pin, LOW);

  }

  String current_time = get_date_and_time();
    
  lcd_printing(current_time, "OK!");
  
  digitalWrite(relay_port, HIGH);
  
  /*
    here we set the time we want the lamp to be switched on and then swtiched off;
    or we can only choose a time to be switched on, e.g.: current_time >= "19:26"
  */
  if (current_time >= "19:26" && current_time <= "19:27") {
    digitalWrite(relay_port, LOW);
  }
  
 
  delay(1000);
  
}
