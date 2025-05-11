#include <Servo.h> // add servo library
Servo myServo; // create servo object to control a servo
int pos = 0; // start servo at 0 deg --?
int potPin = A0;  // analog pin 9 used to connect the potentiometer
int user = 0; // variable for the user decision

void setup() {
  // put your setup code here, to run once:
  myServo.attach(3); // Attach servo to pin 3!!
 
  myServo.write(pos); // Start with initial servo at 0 deg --?
  Serial.begin(9600); // Begin serial communication for debugging
  delay(2000);
}
//define breathing exercise function
void breathingExercise() {
  Serial.println("Breathe in...");
  for (pos = 0; pos <= 155; pos += 1) {
    myServo.write(pos);
    delay(20); // Total ~4 seconds over 156 steps
  }

  Serial.println("Hold...");
  delay(7000); // Hold breath for 7 seconds

  Serial.println("Breathe out...");
  for (pos = 155; pos >= 0; pos -= 1) {
    myServo.write(pos);
    delay(45); // Total ~8 seconds over 156 steps
  }
}

// defining reflection activity function
void reflectionActivity() {
  int potValnew = 0;
  int maxVal = 0;
  int result = 0;

  // Question 1
  Serial.println("How restless are you feeling?");
  delay(8000);
  potValnew = analogRead(potPin);
  maxVal = potValnew;
  result = 1;

  // Question 2
  Serial.println("How nervous are you feeling?");
  delay(8000);
  potValnew = analogRead(potPin);
  if (potValnew > maxVal) {
    maxVal = potValnew;
    result = 4;
  }

  // Question 3
  Serial.println("How worried are you feeling?");
  delay(8000);
  potValnew = analogRead(potPin);
  if (potValnew > maxVal) {
    maxVal = potValnew;
    result = 3;
  }

  // Question 4
  Serial.println("How much is your current environment impacting your stress?");
  delay(8000);
  potValnew = analogRead(potPin);
  if (potValnew > maxVal) {
    maxVal = potValnew;
    result = 1;
  }

  // Question 5
  Serial.println("How much is your present activity impacting your stress?");
  delay(8000);
  potValnew = analogRead(potPin);
  if (potValnew > maxVal) {
    maxVal = potValnew;
    result = 3;
  }

  // Question 6
  Serial.println("How difficult is it to breathe?");
  delay(8000);
  potValnew = analogRead(potPin);
  if (potValnew > maxVal) {
    maxVal = potValnew;
    result = 5;
  }

Serial.println(result);
  // Question 7
  Serial.println("How much are you fidgeting?");
  delay(8000);
  potValnew = analogRead(potPin);
  if (potValnew > maxVal) {
    maxVal = potValnew;
    result = 2;
  }

delay(5000);
  // Suggest activity based on result
  switch(result) {
    case 1:
      Serial.println("Go for a 10 minute walk outside");
      break;
    case 2:
      Serial.println("Do 5 minutes of yoga");
      break;
    case 3:
      Serial.println("Write down the next 5 steps of the day");
      break;
    case 4:
      Serial.println("Do 5 minutes of meditation");
      break;
    case 5:
      Serial.println("Wash your hands and face with cold water");
      break;
    default:
      Serial.println("Unable to determine suggestion.");
      break;
    
  }
delay(5000);
}


// actually running code
void loop() {
  Serial.println("Choose an activity:");
  Serial.println("1 - Breathing Exercise");
  Serial.println("2 - Reflection Activity");

  // Wait until user sends input
  while (Serial.available() == 0) {
    // do nothing, just wait
  }

  user = Serial.read() - '0'; // Convert ASCII char to integer

  if (user == 1) {
    breathingExercise();
    breathingExercise();
    breathingExercise();
  } else if (user == 2) {
    reflectionActivity();
  }
 

  // Small delay and reset user input
  delay(800);
  user = 0;
}
