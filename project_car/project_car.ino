int motor1 = 6;
int motor2 = 7;
int motor3 = 8;
int motor4 = 9;
int ena = 10;
int enb = 11;
int speedy  = 120;
int data;
char data2;
void setup() {
  Serial.begin(9600);
  pinMode(motor1,OUTPUT);
  pinMode(motor2,OUTPUT);
  pinMode(motor3,OUTPUT);
  pinMode(motor4,OUTPUT);
  pinMode(ena,OUTPUT);
  pinMode(enb,OUTPUT);
  analogWrite(ena,speedy);
  analogWrite(enb,speedy);
   

}
void forward(){//RIGHT
    digitalWrite(motor2,HIGH);//RIGHT WHEELS GO BACK
     digitalWrite(motor1,HIGH);//RIGHT WHEELS GO FRONT
    
    //digitalWrite(motor2,LOW);
}

void backward(){
   digitalWrite(motor3,HIGH);//left side goes back
   digitalWrite(motor4,HIGH);//left side goes FRONT
   
}
void front(int speedy){
  Serial.println("Forward"+speedy);
  digitalWrite(motor1,HIGH);
  digitalWrite(motor4,HIGH);
  digitalWrite(motor2,LOW);
  digitalWrite(motor3,LOW);
  analogWrite(ena,speedy);
  analogWrite(enb,speedy);
}


void back(int speedy){
  Serial.println("bckward"+speedy);
  digitalWrite(motor2,HIGH);
  digitalWrite(motor3,HIGH);
  digitalWrite(motor1,LOW);
  digitalWrite(motor4,LOW);
  analogWrite(ena,speedy);
    analogWrite(enb,speedy);
}

void left(){
  digitalWrite(motor1,HIGH);
  digitalWrite(motor3,HIGH);
  digitalWrite(motor2,LOW);
  digitalWrite(motor4,LOW);
  analogWrite(ena,100);
  analogWrite(enb,135); 
}

void right(){
  digitalWrite(motor2,HIGH);
  digitalWrite(motor4,HIGH);
  digitalWrite(motor1,LOW);
  digitalWrite(motor3,LOW);
  analogWrite(ena,135);
  analogWrite(enb,100);
}
void stopped(){
  analogWrite(ena,0);
  analogWrite(enb,0);
}

void loop() {
if(Serial.available()>0){
  data2 = Serial.read();
//  Serial.println(data2);
  //front();
 if(data2=='S'){
  speedy = Serial.parseInt();
 
 }
 if(data2=='F'){
    Serial.println("I am comparing");
    front(speedy);
  }
  else if(data2=='B'){
    back(speedy);
  }
  else if(data2=='R'){
    right();
  }
  else if(data2== 'L'){
    left();
  }
  else if(data2=='X'){
  stopped();
  }
  else{
    
//    Serial.print("Speed is ");
//    Serial.println(speedy);
    
    
  }
}
delay(50);
  //backward();
  //front();
  //back();
 
 

}
