int analogPin;

void setup() {
  char instr[3];
  int pinNo = 0;
  
  Serial.begin(9600);
  Serial.write("Initializing voltmeter sketch. Input analog pin number to read\n"
  "from and terminate with '\\n': ");
  Serial.readBytesUntil('\n', instr, 3);
  
  for (char c : instr) {
    if (c >= '0' && c <= '9') {
      pinNo = pinNo * 10 + c - '0';
    }
  }
  
  analogPin = pinNo;
  
  pinMode(analogPin, INPUT);
}

void loop() {
  int v = analogRead(analogPin);
  Serial.write("level = ");
  Serial.print(v);
  Serial.write("/1024, V = ");
  Serial.print(v * 5.0 / 1024.0 , 3);
  delay(300);
}