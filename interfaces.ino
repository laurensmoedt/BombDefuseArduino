#define SWITCH_PIN 12

const int ledPin = 9;
const int ledPin2 = 11;
const int ledPin3 = 10;

const int buttonPin = 16;
boolean bButtonPressed1 = false;

int val;
int val1;  // the value read from first analog input 
int val2;  // the value read from first analog input 
bool switchPressed = false;  // the value read 




// the setup() method runs once, when the sketch starts
void setup() {
  // initialize the digital pin as an output.
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);

  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(SWITCH_PIN, INPUT_PULLUP);

   if (digitalRead(buttonPin)) { // high, so not pressed
   bButtonPressed1 = false;
 }
 else {
   bButtonPressed1 = true;
 };
 // Initialize monitor
 Serial.begin(115200);
 Keyboard.set_modifier(0);
}

// the loop() methor runs over and over again,
// as long as the board has power
void loop() {

  val = analogRead(A3);  // A0 is PIN_F0, or we could just say "14"
  Serial.print("analog 0 is: ");
  Serial.println(val);
  delay(20);

  if (digitalRead(buttonPin)){
    if (bButtonPressed1) {  // If the last state was different,
      bButtonPressed1 = false;
      digitalWrite(ledPin, LOW);    // set the LED off
    };
  }
  else { // button is pressed  
    if (!bButtonPressed1) {  // If the last state was different,
      bButtonPressed1 = true;
      
      digitalWrite(ledPin, HIGH);   // set the LED on
      delay(1000);                  // wait for a second
      digitalWrite(ledPin, LOW);    // set the LED off
      delay(1000);   

      digitalWrite(ledPin2, HIGH);   // set the LED on
      delay(1000);                  // wait for a second
      digitalWrite(ledPin2, LOW);    // set the LED off
      delay(1000); 

      digitalWrite(ledPin3, HIGH);   // set the LED on
      delay(1000);                  // wait for a second
      digitalWrite(ledPin3, LOW);    // set the LED off
      delay(1000);
    }; // else, we already noticed that the button is pressed.
  };
  delay(50);

  val1 = analogRead(A0);  // A0 is PIN_F0, or we could just say "14"
  val2 = analogRead(A1);  // A0 is PIN_F0, or we could just say "15"

  if (digitalRead(SWITCH_PIN)) {
    switchPressed = false;  // button not pressed
  }
  else {
    switchPressed = true;  // button pressed
  }
  Serial.print("analog 0 (X) is: ");
  Serial.print(val1);

  if (val1 >200 && val1 <900){
    Keyboard.set_key1(0);          // release key
    Keyboard.send_now();
  }    
  
  else{ 
    if (val1 <= 200) {
      Keyboard.set_key1(KEY_D);          // release key
      Keyboard.send_now();  
      Serial.println("Button is no longer pressed.");
    }
    if (val1 >= 900) {
      Keyboard.set_key1(KEY_A);          // release key
      Keyboard.send_now();  
      Serial.println("Button is no longer pressed.");
  }
  }
  Serial.print("\tanalog 1 (Y) is: ");
  Serial.print(val2);
  Serial.print("\tbutton pressed is: ");
  Serial.println(switchPressed);
 delay(20);
}
