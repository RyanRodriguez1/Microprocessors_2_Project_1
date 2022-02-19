/* Group:Ryan Rodriguez, Michael Bautista, Tenzin Lhundup
 * EECE.4520 Project 1: Traffic Light Controller
 * 
 * This code creates a waiting loop where is blinks the red ligt on and off (1 second on, 1 second off)
 * until the button is pressed. At that point it will finish the current pass in the waiting
 * loop and then proceeed into the trafick light loop. Here is will run through 4 states,
 * red - green - yellow 1 - yellow 2,  before looping back. It will continue until the power
 * is disconnected. 
 * 
 */

//does it work on git
int red = 22;   // pin #s for LEDS, button, and active buzzer
int yellow = 24;
int green = 26;
int button = 28;
int buzzer = 8;

int flag = 0;  //flag variable to determine if the light should switch from blinking red to street light
int i = 0; //loop variable

void setup() {
  // put your setup code here, to run once:
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(button, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

 while (flag == 0)  //runs until the button is pressed. once pressed, the on-off will finish and then switch to the street light 
 {
    for (i = 0;i <= 1000; i++)
    {
      digitalWrite(red, HIGH);
      if (digitalRead(button) == HIGH)
      {
        flag = 1;
      }
      delay(1);
    }
    for (i = 0;i <= 1000; i++)
    {
      digitalWrite(red, LOW);
      if (digitalRead(button) == HIGH)
      {
        flag = 1;
      }
      delay(1);
    }
 }
 if (flag == 1) //if button is pressed
 {
  lightSwitch();
 }
}

void lightSwitch(){


 digitalWrite(yellow, LOW);
 digitalWrite(red, HIGH);  //Turns off yellow from previous pass through, Turns on RED
 delay(17000);  //waits 17 seconds
 tone(buzzer, 1000,3000); //Turn on buzzer for 3 seconds
 delay (3000); // wait 3 seconds

 digitalWrite(red, LOW);  //Turn off red, Turn on green, repeat waiting + buzzer process
 digitalWrite(green, HIGH);
 delay(17000);
 tone(buzzer, 1000,3000);
 delay (3000);
 

 digitalWrite(green, LOW);  // green off, yellow on for 3 seconds
 digitalWrite(yellow, HIGH);
 delay(3000);
 tone(buzzer, 1000,3000); // buzzer turns on for 3 seconds
 for (i = 0; i <7; i++) //yellow blinks on and off for 3 seconds, @ 200 ms per on-off
 {
 digitalWrite(yellow, LOW);
 delay(200);
 digitalWrite(yellow, HIGH);
 delay(200);
 }
 digitalWrite(yellow, HIGH);
 delay(200);
 
}
