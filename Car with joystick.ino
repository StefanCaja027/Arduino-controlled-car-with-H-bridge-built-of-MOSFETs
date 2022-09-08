int VRx = A0;
int VRy = A1;
int SW = 8;
int xPosition = 0;
int yPosition = 0;
int SW_state = 0;
int mapX = 0;
int mapY = 0;

void setup() {

pinMode(6,OUTPUT);
pinMode(5,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(10,LOW);
digitalWrite(11,LOW);



  
  Serial.begin(9600);
   
  
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP); 
  
}

void loop() {
  xPosition = analogRead(VRx);
  yPosition = analogRead(VRy);
  SW_state = digitalRead(SW);
  mapX = map(xPosition, 0, 1023, -255, 255);
  mapY = map(yPosition, 0, 1023, 255, -255);
  
  Serial.print("X: ");
  Serial.print(mapX);
  Serial.print(" | Y: ");
  Serial.print(mapY);
  Serial.print(" | Button: ");
  Serial.println(SW_state);


   if (SW_state == 0){
  analogWrite(6,0);
  analogWrite(11,0);
  analogWrite(10,0);
  analogWrite(5,0);
  
  }
 
if ( mapY > 5 && mapX > -15 && mapX < -7){
  analogWrite(6,mapY);
  analogWrite(11,mapY);
  analogWrite(5,0);
  analogWrite(10,0);
  
}
if ( mapY < 5 && mapX > -15 && mapX < -7){
  analogWrite(5,-mapY);
  analogWrite(10,-mapY);
  analogWrite(6,0);
  analogWrite(11,0);
}

if ( mapY > 4 and mapY < 7 and mapX == 255){
  analogWrite(5,0);
  analogWrite(10,255);
  analogWrite(6,255);
  analogWrite(11,0);
}
if ( mapY > 4 and mapY < 7 and mapX == -255){
  analogWrite(5,255);
  analogWrite(10,0);
  analogWrite(6,0);
  analogWrite(11,255);
}

  if (mapY > 5 && mapX > -7){

  analogWrite(5,0);
  analogWrite(10,0);
  analogWrite(6,mapY);
  analogWrite(11,mapY-mapX/2);
  }
  
  
 
  if (mapY > 5 && mapX < -15) {
  
  analogWrite(5,0);
  analogWrite(10,0);
  analogWrite(6,mapY+mapX/2);
  analogWrite(11,mapY);
  }

  if (mapY < 5 && mapX < -15){
  analogWrite(6,0);
  analogWrite(11,0);
  analogWrite(5,-mapY+mapX/2);
  analogWrite(10,-mapY);

  }
  if (mapY < 5 && mapX > -7) {
    
  analogWrite(6,0);
  analogWrite(11,0);
  analogWrite(10,-mapY-mapX/2);
  analogWrite(5,-mapY);
 
  }
  
  
  //delay(100);
 if(mapY > -10 && mapY < 5) {
  analogWrite(5,0);
  analogWrite(6,0);
  } 
}
