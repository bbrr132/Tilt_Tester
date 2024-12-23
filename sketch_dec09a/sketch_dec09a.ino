void setup() {
  // put your setup code here, to run once:
  pinMode(2,INPUT);
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(2));
}
