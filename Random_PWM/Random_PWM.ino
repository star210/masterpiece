
const int muscle_num = 5; // amount of muscles in the array
int muscles[muscle_num] = {3, 5, 6, 7, 9 }; // An array of pin numbers // pins 3,5,6, 9, 10, 11 can be configured for PWM output.
int timeoff = 6000; //  time in ms for wire to cool down 
#define fadetimeseconds 6 // time in seconds for wire to geat up to max length
#define MAX_PWM 150  // maximum value the pwm will climb 
int fadetime = (fadetimeseconds *1000) / MAX_PWM;  // do not edit


void setup() {

  int i;
  for (i = 0; i < muscle_num - 1; i++) // The array elements are numbered from 0  to num pins - 1 (6)
    pinMode(muscles[muscle_num], OUTPUT); // Set each pin as an output
}

void loop()

{
  int randmuscle = random(muscle_num);

  switch (randmuscle)
  {
    case 0 :

      for (int heat = 0; heat < MAX_PWM; heat++) { // Same FOR LOOP for Fade out effect.
        analogWrite(muscles[0], heat);
        delay(fadetime);
      }

      analogWrite(muscles[0], 0);
      delay(timeoff);

      break;

    case 1 :
      for (int heat = 0; heat < MAX_PWM; heat++) { // Same FOR LOOP for Fade out effect.
        analogWrite(muscles[1], heat);
        delay(fadetime);
      }
      analogWrite(muscles[1], 0);
      delay(timeoff);
      break;
    case 2 :
      for (int heat = 0; heat < MAX_PWM; heat++) { // Same FOR LOOP for Fade out effect.
        analogWrite(muscles[2], heat);
        delay(fadetime);
      }
      analogWrite(muscles[2], 0);
      delay(timeoff);
      break;
    case 3 :
      for (int heat = 0; heat < MAX_PWM; heat++) { // Same FOR LOOP for Fade out effect.
        analogWrite(muscles[3], heat);
        delay(fadetime);
      }
      analogWrite(muscles[3], 0);
      delay(timeoff);
      break;
    case 4 :
      for (int heat = 0; heat < MAX_PWM; heat++) { // Same FOR LOOP for Fade out effect.
        analogWrite(muscles[4], heat);
        delay(fadetime);
      }
      analogWrite(muscles[4], 0);
      delay(timeoff);
      break;
    case 5 :
      for (int heat = 0; heat < MAX_PWM; heat++) { // Same FOR LOOP for Fade out effect.
        analogWrite(muscles[5], heat);
        delay(fadetime);
      }
      analogWrite(muscles[5], 0);
      delay(timeoff);
      break;
    case 6 :
      for (int heat = 0; heat < MAX_PWM; heat++) { // Same FOR LOOP for Fade out effect.
        analogWrite(muscles[6], heat);
        delay(fadetime);
      }
      analogWrite(muscles[6], 0);
      delay(timeoff);
      break;

  }

}



