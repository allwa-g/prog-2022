
//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1


#include "mastermind.h"

 // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
                     // initialize the lcd 
  Serial.begin(9600);
  // Print a message to the LCD.
  
  randomSeed(analogRead(1));

  pinMode(LED_RED_1, OUTPUT);
  pinMode(LED_RED_2, OUTPUT);
  pinMode(LED_RED_3, OUTPUT);
  pinMode(LED_RED_4, OUTPUT);
  pinMode(LED_BLUE_1, OUTPUT);
  pinMode(LED_BLUE_2, OUTPUT);
  pinMode(LED_BLUE_3, OUTPUT);
  pinMode(LED_BLUE_4, OUTPUT);
  pinMode(BTN_1_PIN, INPUT);
  pinMode(BTN_2_PIN, INPUT);
  pinMode(BTN_3_PIN, INPUT);
  pinMode(BTN_4_PIN, INPUT);
  pinMode(BTN_ENTER_PIN, INPUT);

}


void loop()
{
 
    char * str = generate_code(false, 4);
    str = "1234";
    play_game(str);
    Serial.println("out");
    
    free(str);
    delay(500);
}
