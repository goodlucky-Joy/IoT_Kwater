void setup() {
  //pinMode(D4, OUTPUT);
  Serial.begin(9600);
}

byte count = 0;

void loop() {
  Serial.print("This is Phi board v1.0 : ");
  Serial.println(count++);
  delay(1000);                       
}
