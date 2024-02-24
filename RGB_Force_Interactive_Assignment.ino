const int force0InPin = 0;
const int force1InPin = 1;
const int force2InPin = 2;
const int light0InPin = 3;
const int toggle0InPin = 2;
int force0In = 0;
int force1In = 0;
int force2In = 0;
int light0In = 0;
boolean toggle0In = 0;
const int rgbR0OutPin = 3;
const int rgbG0OutPin = 5;
const int rgbB0OutPin = 6;
int rgbR0Out = 0;
int rgbG0Out = 0;
int rgbB0Out = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(toggle0InPin, INPUT);
  pinMode(rgbR0OutPin, OUTPUT);
  pinMode(rgbG0OutPin, OUTPUT);
  pinMode(rgbB0OutPin, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  force0In = analogRead(force0InPin);
  force1In = analogRead(force1InPin);
  force2In = analogRead(force2InPin);
  light0In = analogRead(light0InPin);
  toggle0In = digitalRead(toggle0InPin);
//  if (toggle0In == true) {
    if (light0In == 0) {
      rgbR0Out = 127;
      rgbG0Out = 255;
      rgbB0Out = 255;
    } else {
      rgbR0Out = map(force0In, 0, 1023, 0, 255);
      rgbG0Out = map(force1In, 0, 1023, 0, 255);
      rgbB0Out = map(force2In, 0, 1023, 0, 255);
    }
//  }
  analogWrite(rgbR0OutPin, rgbR0Out);
  analogWrite(rgbG0OutPin, rgbG0Out);
  analogWrite(rgbB0OutPin, rgbB0Out);
  Serial.print("In: Force 0 = ");
  Serial.print(force0In);
  Serial.print(" Force 1 = ");
  Serial.print(force1In);
  Serial.print(" Force 2 = ");
  Serial.print(force2In);
  Serial.print(" Light 0 = ");
  Serial.print(light0In);
  Serial.print(" Toggle 0 = ");
  Serial.print(toggle0In);
  Serial.print(" Out: RGB R = ");
  Serial.print(rgbR0Out);
  Serial.print(" RGB G = ");
  Serial.print(rgbG0Out);
  Serial.print(" RGB B = ");
  Serial.println(rgbB0Out);
  delay(100);
}
