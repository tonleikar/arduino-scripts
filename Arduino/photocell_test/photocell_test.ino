byte noteON = 144;//note on command
byte noteOFF = 128;//128 = 10000000 in binary, note off command
int potPin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  
  int potVal = analogRead(potPin);//read data from potentiometer
  
  //we have to scale the potentiometer data to fit between 0 and 127 (this is the range of MIDI notes)
  byte note = map(potVal, 0, 1023, 0, 127);
  
  MIDImessage(noteON, note, 100);//turn note on
  delay(300);//hold note for 300ms
  MIDImessage(noteOFF, note, 100);//turn note off (note on with velocity 0)
  delay(1);//wait 200ms until triggering next note
}

//send MIDI message
void MIDImessage(byte command, byte data1, byte data2) {
  Serial.write(command);
  Serial.write(data1);
  Serial.write(data2);
}
