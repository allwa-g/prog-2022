#include <Arduino.h>
#include "mastermind.h"
#include <stdlib.h>
#include <stdio.h>
#include "lcd_wrapper.h"
#include <stdbool.h>

//generate code vrati vzgenerovane retazec ktory mame uhadnut
//ak je boo repeat = true potom sa budu opakovat cisla v hladanom kode ked je false, nebudu sa opakovat
// length urcuje dlzku vygenerovaneho kodu
char* generate_code(bool repeat, int length){
  if (length < 1){  // podmieky zo zadania
    return NULL;
  } 

  if (repeat == false){ // podmienky
    if(length > 10){
      return NULL;
    }
  } 
  char* result;
  result = (char*) calloc(length+1, sizeof(char));

  if(repeat == true){ //ak sa mozu cisla opkaovat
    for(int i = 0; i < length; i++){
      result[i] = random(10)+48;

    }
    result[length-1] = '\0';
  }

  if(repeat == false){
    for(int i = 0; i < length; i++){

    }
  }
}
//secret - ciselna kombinacia ktoru hladame
//gues ciselna kokbinacia ktora reprezentuje aktualny hracov ti
//peg_a pocet uhadnutych cisel nachadzajucich sa na spravnej pozicii
//peg_b pocet uhadnutych cislic ktore sa nenachadzaju na spravnej pozicii
void get_score(const char *secret, const char *guess, int *peg_a, int *peg_b)
{
  int a = 0;
  int b = 0;

// ak sa nachadza spravne cislo na spravnej pozicii
  for(int i = 0 ; i < strlen(secret) ; ++i) {
    if(secret[i] == guess[i]) {
      a++;
    }
  }

// ak sa nachadza cislo ale nie na spravnejj pozicii

  for(int i = 0 ; i < strlen(secret) ; i++) {
    for(int j = 0 ; j < strlen(secret) ; j++) {

      if(i != j ){
        if(secret[i] == guess[j]){
          b++;
          continue;
        }
      }
    }
  }
  *peg_a = a;
  *peg_b = b;
}

//ledky budu vypnute
void turn_off_leds(){
    digitalWrite(LED_RED_1, LOW);
    digitalWrite(LED_RED_2, LOW);
    digitalWrite(LED_RED_3, LOW);
    digitalWrite(LED_RED_4, LOW);  
    digitalWrite(LED_BLUE_1, LOW);
    digitalWrite(LED_BLUE_2, LOW);
    digitalWrite(LED_BLUE_3, LOW);
    digitalWrite(LED_BLUE_4, LOW);

}


void render_leds(const int peg_a, const int peg_b){
int pin_a = 7;
int pin_b = 6;

  if ((peg_a != 0) && ((peg_a + peg_b) != 0) ){
    for (int i = 0; i < peg_a; ++i){
      digitalWrite(pin_a,HIGH);
      pin_a = pin_a + 2;
    }
  }

  if ((peg_b != 0) && ((peg_a + peg_b) != 0)){
    for (int i = 0; i < peg_b; ++i){
      digitalWrite(pin_b,HIGH);
      pin_b = pin_b + 2;
    }
  }
 
}

void render_history(char *secret, char **history, const int entry_nr)
{
    int peg_a = 0;
    int peg_b = 0;
    get_score(secret, history[entry_nr], &peg_a, &peg_b);
    render_leds(peg_a, peg_b);
    String reds = String(" A"+String(peg_a));
    String blues = String("B" + String(peg_b));        
    lcd_print_at(0, 0, String(String(entry_nr) + ": " + history[entry_nr]+ (reds + blues)).c_str());
}


void play_game(char *secret){

//memoery allocation
    char **history = malloc(10 * sizeof(char *));
    for (int i = 0; i < 10; i++)
    {
        history[i] = malloc(5 * sizeof(char));
    }

    lcd_init();
    turn_off_leds();
    String scrt = String(secret);
    String guess = String("0000");
    int attempts = 0;
    
    Serial.println("new");
    Serial.println(secret); 
    lcd_clear();
    lcd_print_at(0, 0, String("Welcome to").c_str());
    lcd_print_at(0, 1, String("game").c_str());
    delay(2000);  
    lcd_clear();
    lcd_print_at(0, 0, String("Mastermind").c_str());
    lcd_print_at(0, 1, String("guesss the secret").c_str());

    delay(2000);
    lcd_clear();
    lcd_print_at(0, 0, "Number guessed");
    lcd_print_at(0, 1, String("Your: 0000").c_str());
    
    int peg_a = 0;
    int peg_b = 0;
    while (attempts < 10 && peg_a != 4){
    unsigned long time = 0;
    int cursor = attempts-1;
    
    while (digitalRead(2) == HIGH){
        
        time +=1;
        if (digitalRead(3) == HIGH){
            cursor = cursor - 1;
            if(cursor >= 0){
                turn_off_leds();
                render_history(secret, history, cursor);
            }else{
                cursor = 0;
            }
            delay(300);
        }

        if (digitalRead(4) == HIGH){
            cursor = cursor + 1;
            if(cursor < attempts){
                turn_off_leds();
                render_history(secret, history, cursor);
            }else{
                cursor = attempts-1;
            }
            delay(300);
        }
    }
    
    if (time < 17000 && time > 0){
        guess[0] = guess[0] + 1;
        if (guess[0] > '9'){
          guess[0] = '0';
        } 
    }

    if (digitalRead(3) == HIGH){
        guess[1] = guess[1] + 1;
        if (guess[1] > '9') {
          guess[1] = '0';
        }
    }

    if (digitalRead(4) == HIGH){
        guess[2] = guess[2] + 1;
        if (guess[2] > '9'){
          guess[2] = '0';
        }
    }

    if (digitalRead(5) == HIGH){
        guess[3] = guess[3] + 1;
      if(guess[3] > '9'){
        guess[3] = '0';        
      }        
    }
        lcd_print_at(0, 1, String("Your tip: " + guess).c_str());


        if (digitalRead(A0) == HIGH)
        {
            turn_off_leds();
            peg_a = 0;
            peg_b = 0;
            
            get_score(secret, guess.c_str(), &peg_a, &peg_b);
            render_leds(peg_a, peg_b);

            lcd_clear();
            memcpy(history[attempts], guess.c_str(), 5*sizeof(char));
            String reds = String(" A"+String(peg_a));
            String blues = String("B" + String(peg_b));
            lcd_print_at(0, 0, String(String(attempts) + ": " + history[attempts]+ (reds + blues)).c_str());
            lcd_print_at(0, 1, String("Your tip: " + guess).c_str());
            attempts += 1;    
            delay(100);
        }
        delay(100);
    }
    lcd_clear();
    if(peg_a == 4){
        lcd_print_at(0, 0, "Congrats you won");
    }else{
        lcd_print_at(0, 0, "Sorry you lost");
        lcd_print_at(0, 1, String("Answer:"+ scrt).c_str());
    }

    //delay(2000);

    //vymaze historiu
    int i = 0;
    for (i; i < 10; i++){
        free(history[i]);
    }
    free(history);
}