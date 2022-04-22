int tg1 = 4, ech1 = 3; // trigger and echo pin - 1
int tg2 = 9, ech2 = 8; // trigger and echo pin - 2

int c = 0; // counter 

void setup()
{
  pinMode(tg1, OUTPUT);
  pinMode(tg2, OUTPUT);
  pinMode(ech1, INPUT);
  pinMode(ech2, INPUT);
  Serial.begin(9600);
}

void loop()
{
  float ur1, ur2;
  float dit1, dit2;
  float gate = 150;
  
  //to clear out the trigger pins
  digitalWrite(tg1, LOW);
  delayMicroseconds(2);
  digitalWrite(tg2, LOW);
  delayMicroseconds(2); 
  
  // entering sheep
  digitalWrite(tg1, HIGH);
  delayMicroseconds(10);
  digitalWrite(tg1, LOW);  
  ur1 = pulseIn(ech1, HIGH);  
  dit1 = 0.034*(ur1/2);
  
  // exiting sheep
  digitalWrite(tg2, HIGH);
  delayMicroseconds(10);
  digitalWrite(tg2, LOW);  
  ur2 = pulseIn(ech2, HIGH);  
  dit2 = 0.034*(ur2/2);
  
  if(dit1<gate)
  {
    c++;
    delay(700); //lets assume that this is the avg time it takes for a sheep to pass the gate 
  }
  
  if(dit2<gate)
  {
    if(c>0){
      c--;
      delay(700);
    }  	
  }
  
  Serial.print("\nThe Number of Sheeps Inside = ");
  Serial.println(c);
  delay(500);
}
