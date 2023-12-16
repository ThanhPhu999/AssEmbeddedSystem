#include <Arduino.h>
// Timer variables
hw_timer_t *timer = NULL;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;
#define TIMER_INTERVAL_US 10000

uint8_t timerCounter0 = 0;
bool timer0Flag = false;
void setTimer0(uint8_t counter){
  timer0Flag = false;
  timerCounter0 = counter;
}

uint8_t timerCounter1 = 0;
bool timer1Flag = false;
void setTimer1(uint8_t counter){
  timer1Flag = false;
  timerCounter1 = counter;
}

uint8_t timerCounter2 = 0;
bool timer2Flag = false;
void setTimer2(uint8_t counter){
  timer2Flag = false;
  timerCounter2 = counter;
}

uint8_t timerCounter3 = 0;
bool timer3Flag = false;
void setTimer3(uint8_t counter){
  timer3Flag = false;
  timerCounter3 = counter;
}

uint8_t timerCounter4 = 0;
bool timer4Flag = false;
void setTimer4(uint8_t counter){
  timer4Flag = false;
  timerCounter4 = counter;
}

uint8_t timerCounter5 = 0;
bool timer5Flag = false;
void setTimer5(uint8_t counter){
  timer5Flag = false;
  timerCounter5 = counter;
}

void timerRun(){
  timerCounter0--;
  if(timerCounter0 == 0){
    timer0Flag = true;
  }

  timerCounter1--;
  if(timerCounter1 == 0){
    timer1Flag = true;
  }

  timerCounter2--;
  if(timerCounter2 == 0){
    timer2Flag = true;
  }

  timerCounter3--;
  if(timerCounter3 == 0){
    timer3Flag = true;
  }
  
  timerCounter4--;
  if(timerCounter4 == 0){
    timer4Flag = true;
  }

  timerCounter5--;
  if(timerCounter5 == 0){
    timer5Flag = true;
  }
}

void IRAM_ATTR onTimer() {
 timerRun();
}

#define MANUAL  41
#define AUTO  42
#define INIT 43

uint8_t MODE = MANUAL;

void setup() {
  Serial.begin(9600);

  // Set up the timer interrupt
  timer = timerBegin(0, 80, true); // Timer 0, 80 prescaler (1 us tick)
  timerAttachInterrupt(timer, &onTimer, true);
  timerAlarmWrite(timer, TIMER_INTERVAL_US, true);
  timerAlarmEnable(timer);

}

void loop() {
  switch(MODE){
    case INIT:
      setTimer0(500);
      setTimer3(300);
      MODE = MANUAL;
      break;
    case MANUAL:
      if(timer0Flag){

      }
    break;
    case AUTO:
    break;
    default:
    break;
  }

}
