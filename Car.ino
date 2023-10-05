#define motor1_dir1 11
#define motor1_dir2 10
#define motor1_speed 9

#define motor2_dir1 8
#define motor2_dir2 7
#define motor2_speed 6
   
char data;

void forward()
{
  digitalWrite(motor1_dir1,LOW);
  digitalWrite(motor1_dir2,HIGH);
  analogWrite(motor1_speed,150);
  
  digitalWrite(motor2_dir1,HIGH);
  digitalWrite(motor2_dir2,LOW);
  analogWrite(motor2_speed,200);
}

void backward()
{  
  digitalWrite(motor1_dir1,HIGH);
  digitalWrite(motor1_dir2,LOW);
  analogWrite(motor1_speed,150);
  
  digitalWrite(motor2_dir1,LOW);
  digitalWrite(motor2_dir2,HIGH);
  analogWrite(motor2_speed,200);
}
void right()
{
  digitalWrite(motor1_dir1,LOW);
  digitalWrite(motor1_dir2,HIGH);
  analogWrite(motor1_speed,200);
  
  digitalWrite(motor2_dir1,HIGH);
  digitalWrite(motor2_dir2,LOW);
  analogWrite(motor2_speed,100);
  
}
void left()
{
  digitalWrite(motor1_dir1,LOW);
  digitalWrite(motor1_dir2,HIGH);
  analogWrite(motor1_speed,100);
  
  digitalWrite(motor2_dir1,HIGH);
  digitalWrite(motor2_dir2,LOW);
  analogWrite(motor2_speed,220);
}
void stop1()
{
  digitalWrite(motor1_dir1,HIGH);
  digitalWrite(motor1_dir2,HIGH);
  analogWrite(motor1_speed,0);
  
  digitalWrite(motor2_dir1,HIGH);
  digitalWrite(motor2_dir2,HIGH);
  analogWrite(motor2_speed,0);
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(motor1_dir1,OUTPUT);
  pinMode(motor1_dir2,OUTPUT);
  pinMode(motor1_speed,OUTPUT);
  
  pinMode(motor2_dir1,OUTPUT);
  pinMode(motor2_dir2,OUTPUT);
  pinMode(motor2_speed,OUTPUT);

  pinMode(LED_BUILTIN,OUTPUT);
}

void loop() {
//  digitalWrite(motor1_dir1,HIGH);
//  digitalWrite(motor1_dir2,LOW);
//  digitalWrite(motor1_speed,1);
//  
//  digitalWrite(motor2_dir1,LOW);
//  digitalWrite(motor2_dir2,HIGH);
//  digitalWrite(motor2_speed,1);
  
  // put your main code here, to run repeatedly:
  while(Serial.available())
  {
    data=Serial.read();
    switch(data)
    {
      case 'u':
        forward();
        digitalWrite(LED_BUILTIN,HIGH);
        break;
        
       case 'd':
        backward();
        digitalWrite(LED_BUILTIN,LOW);
        break;
        
       case 'r':
         right();
         break;
         
       case 'l':
         left();
         break;
         
        case 's':
         stop1();
         break; 
    }
  }
}
