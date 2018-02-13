

byte DTMFread;
const int STQ = 3;        // STQ Pin to Arduino Digital Pin 3
const int Q4 = 4;        //  Q4  Pin to Arduino Digital Pin 4
const int Q3 = 5;        //  Q3  Pin to Arduino Digital Pin 5
const int Q2 = 6;        //  Q2  Pin to Arduino Digital Pin 6
const int Q1 = 7;        //  Q1  Pin to Arduino Digital Pin 7

const int RELAY_1 = 8;
const int RELAY_2 = 9;
const int RELAY_3 = 10;
const int RELAY_4 = 11;
const int RELAY_5 = 12;
const int BUZZER = 13;

boolean RELAY_1_STATUS;
boolean RELAY_2_STATUS;
boolean RELAY_3_STATUS;
boolean RELAY_4_STATUS;
boolean RELAY_5_STATUS;
boolean BUZZER_STATUS;

const byte KEY_1 = 0x1; // 1
const byte KEY_2 = 0x2; // 2
const byte KEY_3 = 0x3; // 3
const byte KEY_4 = 0x4; // 4
const byte KEY_5 = 0x5; // 5
const byte KEY_6 = 0x6; // 6
const byte KEY_7 = 0x7; // 7
const byte KEY_8 = 0x8; // 8
const byte KEY_9 = 0x9; // 9
const byte KEY_0 = 0xA; // 0
const byte KEY_X = 0xB; // *
const byte KEY_H = 0xC; // #



/*=========================================================================================================
========================================================================================================== */
void setup() {

  Serial.begin(9600);
  
  //Setup the INPUT pins on the Arduino
  pinMode(STQ, INPUT);
  pinMode(Q4, INPUT);
  pinMode(Q3, INPUT);
  pinMode(Q2, INPUT);
  pinMode(Q1, INPUT);

  //Setup the OUTPUT pins on the Arduino
  pinMode(RELAY_1, OUTPUT);
  pinMode(RELAY_2, OUTPUT);
  pinMode(RELAY_3, OUTPUT);
  pinMode(RELAY_4, OUTPUT);
  pinMode(RELAY_5, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  // set all relay to off
  digitalWrite(RELAY_1, LOW);
  digitalWrite(RELAY_2, LOW);
  digitalWrite(RELAY_3, LOW);
  digitalWrite(RELAY_4, LOW);
  digitalWrite(RELAY_5, LOW);
  digitalWrite(BUZZER, LOW);

  // init relay status
  RELAY_1_STATUS = false;
  RELAY_2_STATUS = false;
  RELAY_3_STATUS = false;
  RELAY_4_STATUS = false;
  RELAY_5_STATUS = false;
  BUZZER_STATUS = false;
  
}


void loop() {

  // READ DTMF
  if(digitalRead(STQ)==HIGH){       //When a DTMF tone is detected, STQ will read HIGH for the duration of the tone.
    DTMFread=0;
    
    if(digitalRead(Q1)==HIGH){      //If Q1 reads HIGH, then add 1 to the DTMFread variable
      DTMFread=DTMFread+1;
    }
    
    if(digitalRead(Q2)==HIGH){      //If Q2 reads HIGH, then add 2 to the DTMFread variable
      DTMFread=DTMFread+2;
    }
    
    if(digitalRead(Q3)==HIGH){      //If Q3 reads HIGH, then add 4 to the DTMFread variable
      DTMFread=DTMFread+4;
    }
    
    if(digitalRead(Q4)==HIGH){      //If Q4 reads HIGH, then add 8 to the DTMFread variable
      DTMFread=DTMFread+8;
    }
    
  }

  DTMFToKey(DTMFread);
  
  delay(100);  
  
}


void DTMFToKey(int dtmfValue)
{

  //Serial.println("dtmfValue: "+ dtmfValue);
  switch(dtmfValue)
  {
    case KEY_1:
      Control_RELAY_1(true);
      //Serial.println("KEY_1");
      break;
    case KEY_2:
      Control_RELAY_1(false);
      //Serial.println("KEY_2");
      break;
    case KEY_3:
      Control_RELAY_5(true);
      //Serial.println("KEY_3");
      break;
    case KEY_4:
      Control_RELAY_2(true);
      //Serial.println("KEY_4");
      break;
    case KEY_5:
      Control_RELAY_2(false);
      //Serial.println("KEY_5");
      break;
    case KEY_6:
      Control_RELAY_5(false);
      //Serial.println("KEY_6");
      break;
    case KEY_7:
      Control_RELAY_3(true);
      //Serial.println("KEY_7");
      break;
    case KEY_8:
      Control_RELAY_3(false);
      //Serial.println("KEY_8");
      break;
    case KEY_9:
      //Control_All_RELAY(true);
      //Serial.println("KEY_9");
      break;
    case KEY_0:
      Control_RELAY_4(false);
      //Serial.println("KEY_0");
      break;
    case KEY_X:
      Control_RELAY_4(true);
      //Serial.println("KEY_X");
      break;
    case KEY_H:
      Turn_Off_All_RELAY();
      //Serial.println("KEY_H");
      break;
  }
}

void Control_RELAY_1(boolean isON)
{
  if(isON == true && RELAY_1_STATUS == false)
  {
    digitalWrite(RELAY_1, HIGH);
    RELAY_1_STATUS = true;
    Serial.println("------ RELAY_1: ON");
  }
  else if(isON == false && RELAY_1_STATUS == true)
  {
    digitalWrite(RELAY_1, LOW);
    RELAY_1_STATUS = false;
    Serial.println("------ RELAY_1: OFF");
  }
}

void Control_RELAY_2(boolean isON)
{
  if(isON == true && RELAY_2_STATUS == false)
  {
    digitalWrite(RELAY_2, HIGH);
    RELAY_2_STATUS = true;
    Serial.println("------ RELAY_2: ON");
  }
  else if(isON == false && RELAY_2_STATUS == true)
  {
    digitalWrite(RELAY_2, LOW);
    RELAY_2_STATUS = false;
    Serial.println("------ RELAY_2: OFF");
  }
}

void Control_RELAY_3(boolean isON)
{
  if(isON == true && RELAY_3_STATUS == false)
  {
    digitalWrite(RELAY_3, HIGH);
    RELAY_3_STATUS = true;
    Serial.println("------ RELAY_3: ON");
  }
  else if(isON == false && RELAY_3_STATUS == true)
  {
    digitalWrite(RELAY_3, LOW);
    RELAY_3_STATUS = false;
    Serial.println("------ RELAY_3: OFF");
  }
}

void Control_RELAY_4(boolean isON)
{
  if(isON == true && RELAY_4_STATUS == false)
  {
    digitalWrite(RELAY_4, HIGH);
    RELAY_4_STATUS = true;
    Serial.println("------ RELAY_4: ON");
  }
  else if(isON == false && RELAY_4_STATUS == true)
  {
    digitalWrite(RELAY_4, LOW);
    RELAY_4_STATUS = false;
    Serial.println("------ RELAY_4: OFF");
  }
}

void Control_RELAY_5(boolean isON)
{
  if(isON == true && RELAY_5_STATUS == false)
  {
    digitalWrite(RELAY_5, HIGH);
    RELAY_5_STATUS = true;
    Serial.println("------ RELAY_5: ON");
  }
  else if(isON == false && RELAY_5_STATUS == true)
  {
    digitalWrite(RELAY_5, LOW);
    RELAY_5_STATUS = false;
    Serial.println("------ RELAY_5: OFF");
  }
}

void Turn_Off_All_RELAY()
{
  if(RELAY_1_STATUS || RELAY_2_STATUS || RELAY_3_STATUS || RELAY_4_STATUS || RELAY_5_STATUS)
  {
    Serial.println("###### TURN OFF ALL RELAY ##########");

    Control_RELAY_1(false);
    Control_RELAY_2(false);
    Control_RELAY_3(false);
    Control_RELAY_4(false);
    Control_RELAY_5(false);
  }
}



