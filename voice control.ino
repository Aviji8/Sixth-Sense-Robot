String readvoice;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //begin serial communication with baud rate 9600
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);


}
void moveRobot(String motion)
{
  if(motion == "Forward"){
    digitalWrite(8,HIGH);
    digitalWrite(9,LOW);
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    Serial.println("Forward");
    } 

     if(motion == "Backward"){
    digitalWrite(8,LOW);
    digitalWrite(9,HIGH);
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
    Serial.println("Backward");
    } 

     if(motion == "Left"){
    digitalWrite(8,HIGH);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
    Serial.println("Left");
    } 

     if(motion == "Right"){
    digitalWrite(8,LOW);
    digitalWrite(9,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    Serial.println("Right");
    } 

     if(motion == "Stop"){
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    Serial.println("Stop");
    } 
 
}
void loop() {
   if(Serial.available()){
  readvoice=Serial.readString(); 
  if(readvoice=="go"){
     moveRobot("Forward");
  }
  else if(readvoice=="back"){
moveRobot("Backward");
    
  }
  else if(readvoice=="left" || readvoice=="lip"){
    moveRobot("Left");
    delay(1000);
     moveRobot("Forward");
  }
  else if(readvoice=="right" || readvoice=="alright"){
    moveRobot("Right");
    delay(1000);
    moveRobot("Forward");
  }
  else if("stop"){
    moveRobot("Stop");
  }
//  else if(readvoice=="*show me Garba#" ||(readvoice=="show" ){
//    moveRobot("show me Garba");
//  }
  else{
    Serial.println(readvoice);
  }
//// moveRobot("Backward");
//// delay(3000);
 //moveRobot("Left");
//delay(5000);  
  
//  moveRobot("Forward");
//  delay(1000);
 //moveRobot("Right");
//  delay(50);
//  moveRobot("Stop");
//  delay(1000);

}
}
