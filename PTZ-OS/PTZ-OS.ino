//PTZ - V8 : Code Final Simulation
//Finalisé le 18/09/2024
//Cobe by VLTV & GAB
//Dev by GALEX.CO by GALEXGROUP
//Projet Main by Léo TORRAS and CARL KB
//Projet à déstination du plateau TV de LTPSN

//Def Variables
  //Caméra
    //C1
      //PANO
int PanoC1 = 16;
int DirPanoC1 = 4;
int StepPanoC1 = 0;
      //TILT
int TiltC1 = 18;
int DirTiltC1 = 5;
int StepTiltC1 = 0;

    //C2
      //PANO
int PanoC2 = 23;
int DirPanoC2 = 22;
int StepPanoC2 = 0;
      //TILT
int TiltC2 = 19;
int DirTiltC2 = 21;
int StepTiltC2 = 0;

    //C3
      //PANO
int PanoC3 = 0;
int DirPanoC3 = 0;
int StepPanoC3 = 0;
      //TILT
int TiltC3 = 0;
int DirTiltC3 = 0;
int StepTiltC3 = 0;

    //C4
      //PANO
int PanoC4 = 0;
int DirPanoC4 = 0;
int StepPanoC4 = 0;
      //TILT
int TiltC4 = 0;
int DirTiltC4 = 0;
int StepTiltC4 = 0;

  //Vitesse
int speed=50;

  //Joystick
int pano = 12; 
int tilt = 14; 
int BJ = 17; 

  //Boutton
int Off = 17;
int SleC1 = 34;
int SleC2 = 35;
int SleC3 = 32;
int SleC4 = 33;
int Set = 0;
  //PRG
int SleP1 = 25;
int P1Pano;
int P1Tilt;

int SleP2 = 26;
int P2Pano;
int P2Tilt;

int SleP3 = 13;
int P3Pano;
int P3Tilt;

int SleP4 = 2;
int P4Pano;
int P4Tilt;

  //Cam control
int CamSle = 1;
int PanoSle = PanoC1 ;
int DirPanoSle = DirPanoC1 ;
int TiltSle = TiltC1 ;
int DirTiltSle = DirTiltC1;
int StepPanoSle = StepPanoC1 ;
int StepTiltSle = StepTiltC1 ;


void setup() {
    //Caméra
      //Moteur
        //Pano
    pinMode(DirPanoC1, OUTPUT); 
    pinMode(PanoC1, OUTPUT);
      //Tilt
    pinMode(DirTiltC1, OUTPUT);
    pinMode(TiltC1, OUTPUT);
      //Moteur
        //Pano
    pinMode(DirPanoC2, OUTPUT); 
    pinMode(PanoC2, OUTPUT);
      //Tilt
    pinMode(DirTiltC2, OUTPUT);
    pinMode(TiltC2, OUTPUT);
      //SLE
        //Pano
    pinMode(DirPanoSle, OUTPUT); 
    pinMode(PanoSle, OUTPUT);
      //Tilt
    pinMode(DirTiltSle, OUTPUT);
    pinMode(TiltSle, OUTPUT);

    //Joystick
    pinMode (pano, INPUT); 
    pinMode (tilt, INPUT); 
    pinMode (BJ, INPUT); 
    
    //Serial
    Serial.begin (9600);
    Serial.println("PTZ CAM - READY");

    //Select Cam
    pinMode (SleC1, INPUT);
    pinMode (SleC2, INPUT);
    pinMode (SleC3, INPUT);
    pinMode (SleC4, INPUT);
}

void loop() {
//Initialisation Variable
  delay(1000);
  float X, Y;
  int B;
  X = analogRead (pano) * (5.0 / 1023.0);
  Y = analogRead (tilt) * (5.0 / 1023.0);
  B = digitalRead(BJ);

//Selecteur
  if (digitalRead(SleC1) == HIGH){
    switch(CamSle){
      case 2:
        Serial.println("Case 2");
        StepPanoC2 = StepPanoSle;
        StepTiltC2 = StepTiltSle;
        break;
      case 3:
        Serial.println("Case 3");
        StepPanoC3 = StepPanoSle;
        StepTiltC3 = StepTiltSle;
        break;
      case 4:
        Serial.println("Case 4");
        StepPanoC4 = StepPanoSle;
        StepTiltC4 = StepTiltSle;
        break;
    }
    CamSle = 1;
    Serial.print("Control Cam : ");
    Serial.println(CamSle);
    PanoSle = PanoC1 ;
    DirPanoSle = DirPanoC1 ;
    TiltSle = TiltC1 ;
    DirTiltSle = DirTiltC1;
    StepPanoSle = StepPanoC1 ;
    StepTiltSle = StepTiltC1 ;
  }

  if (digitalRead(SleC2) == HIGH){
    switch(CamSle){
      case 1:
        Serial.println("Case 1");
        StepPanoC1 = StepPanoSle;
        StepTiltC1 = StepTiltSle;
        break;
      case 3:
        Serial.println("Case 3");
        StepPanoC3 = StepPanoSle;
        StepTiltC3 = StepTiltSle;
        break;
      case 4:
        Serial.println("Case 4");
        StepPanoC4 = StepPanoSle;
        StepTiltC4 = StepTiltSle;
        break;
    }
    CamSle = 2;
    Serial.print("Control Cam : ");
    Serial.println(CamSle);
    PanoSle = PanoC2 ;
    DirPanoSle = DirPanoC2 ;
    TiltSle = TiltC2 ;
    DirTiltSle = DirTiltC2;
    StepPanoSle = StepPanoC2 ;
    StepTiltSle = StepTiltC2 ;
  }

  if (digitalRead(SleC3) == HIGH){
    switch(CamSle){
      case 1:
        Serial.println("Case 1");
        StepPanoC1 = StepPanoSle;
        StepTiltC1 = StepTiltSle;
        break;
      case 2:
        Serial.println("Case 2");
        StepPanoC2 = StepPanoSle;
        StepTiltC2 = StepTiltSle;
        break;
      case 4:
        Serial.println("Case 4");
        StepPanoC4 = StepPanoSle;
        StepTiltC4 = StepTiltSle;
        break;
    }
    CamSle = 3;
    Serial.print("Control Cam : ");
    Serial.println(CamSle);
    PanoSle = PanoC1 ;
    DirPanoSle = DirPanoC1 ;
    TiltSle = TiltC1 ;
    DirTiltSle = DirTiltC1;
    StepPanoSle = StepPanoC1 ;
    StepTiltSle = StepTiltC1 ;
  }

  if (digitalRead(SleC4) == HIGH){
    switch(CamSle){
      case 1:
        Serial.println("Case 1");
        StepPanoC1 = StepPanoSle;
        StepTiltC1 = StepTiltSle;
        break;
      case 2:
        Serial.println("Case 2");
        StepPanoC2 = StepPanoSle;
        StepTiltC2 = StepTiltSle;
        break;
      case 3:
        Serial.println("Case 3");
        StepPanoC3 = StepPanoSle;
        StepTiltC3 = StepTiltSle;
        break;
    }
    CamSle = 4;
    Serial.print("Control Cam : ");
    Serial.println(CamSle);
    PanoSle = PanoC1 ;
    DirPanoSle = DirPanoC1 ;
    TiltSle = TiltC1 ;
    DirTiltSle = DirTiltC1;
    StepPanoSle = StepPanoC1 ;
    StepTiltSle = StepTiltC1 ;
  }
  
//Mouvement Pano
    //Droite
  if(Y<=0){
    StepPanoSle = StepPanoSle+1;
    //Serial.println("Pano go right");
    digitalWrite(DirPanoSle, HIGH);
    digitalWrite(PanoSle, LOW);
    delay(speed); 
    digitalWrite(PanoSle, HIGH);
    delay(speed);
  }
    //Gauche
  if(Y>=19){
    //Serial.println("Pano go left");
    StepPanoSle = StepPanoSle-1;
    digitalWrite(DirPanoSle, LOW);
    digitalWrite(PanoSle, LOW);
    delay(speed); 
    digitalWrite(PanoSle, HIGH); 
    delay(speed);
  }

//Mouvement Tilt
    //Haut
  if(X<=0){
    StepTiltSle = StepTiltSle+1;
    //Serial.println("Tilt go right");
    digitalWrite(DirTiltSle, HIGH);
    digitalWrite(TiltSle, LOW);
    delay(speed); 
    digitalWrite(TiltSle, HIGH);
    delay(speed);
  }

    //Bas
  if(X>=19){
      //Serial.println("Tilt go left");
      StepTiltSle = StepTiltSle-1;
      digitalWrite(DirTiltSle, LOW);
      digitalWrite(TiltSle, LOW);
      delay(speed); 
      digitalWrite(TiltSle, HIGH);
      delay(speed);
  }
//Set Prg
  if(digitalRead(SleP1)==HIGH && digitalRead(Set)==HIGH){
    P1Pano = StepPanoSle;
    P1Tilt = StepTiltSle;
  }
  if(digitalRead(SleP2)==HIGH && digitalRead(Set)==HIGH){
    P2Pano = StepPanoSle;
    P2Tilt = StepTiltSle;
  }
  if(digitalRead(SleP3)==HIGH && digitalRead(Set)==HIGH){
    P3Pano = StepPanoSle;
    P3Tilt = StepTiltSle;
  }
  if(digitalRead(SleP4)==HIGH && digitalRead(Set)==HIGH){
    P4Pano = StepPanoSle;
    P4Tilt = StepTiltSle;
  }

//Exe Prg
    //Prg1
    if(digitalRead(SleP1)==HIGH){
        Serial.println("SleP1 Press");
        //Pano
            //Détéction Pano Droite/Gauche
        if(StepPanoSle>P1Pano){ //Si le pano est vers la gauche
          //Serial.println("Pano on the left detect");
          digitalWrite(DirPanoSle, HIGH);
          while (StepPanoSle==P1Pano) { 
            digitalWrite(PanoSle, LOW);
            delay(speed);
            digitalWrite(PanoSle, HIGH);
            delay(speed);
          }
        }
        else { //si le pano est sur la droite
          digitalWrite(DirPanoSle,LOW);
          //Serial.println("Pano on the right detect");
          while (StepPanoSle==P1Pano) { 
            digitalWrite(PanoSle, LOW);
            delay(speed);
            digitalWrite(PanoSle, HIGH);
            delay(speed);
          }
        }
        if(StepTiltSle<P1Tilt){ //Si le tilt est vers le bas
          //Serial.println("Tilt on bottom detect");
          digitalWrite(DirTiltSle,HIGH);
          while (StepTiltSle==P1Tilt) { 
            digitalWrite(TiltSle, LOW);
            delay(speed);
            digitalWrite(TiltSle, HIGH);
            delay(speed);
          }
        }
        else { //si le tilt est vers le haut
          digitalWrite(DirTiltSle,LOW);
          //Serial.println("Tilt on the top detect");
          while (StepTiltSle==P1Tilt) { 
            digitalWrite(TiltSle, LOW);
            delay(speed);
            digitalWrite(TiltSle, HIGH);
            delay(speed);
          }
        }
    }

    //Prg2
    if(digitalRead(SleP2)==HIGH){
        Serial.println("SleP2 Press");
        //Pano
            //Détéction Pano Droite/Gauche
        if(StepPanoSle>P2Pano){ //Si le pano est vers la gauche
          //Serial.println("Pano on the left detect");
          digitalWrite(DirPanoSle, HIGH);
          while (StepPanoSle==P2Pano) { 
            digitalWrite(PanoSle, LOW);
            delay(speed);
            digitalWrite(PanoSle, HIGH);
            delay(speed);
          }
        }
        else { //si le pano est sur la droite
          digitalWrite(DirPanoSle,LOW);
          //Serial.println("Pano on the right detect");
          while (StepPanoSle==P2Pano) { 
            digitalWrite(PanoSle, LOW);
            delay(speed);
            digitalWrite(PanoSle, HIGH);
            delay(speed);
          }
        }
        if(StepTiltSle<P1Tilt){ //Si le tilt est vers le bas
          //Serial.println("Tilt on bottom detect");
          digitalWrite(DirTiltSle,HIGH);
          while (StepTiltSle==P2Tilt) { 
            digitalWrite(TiltSle, LOW);
            delay(speed);
            digitalWrite(TiltSle, HIGH);
            delay(speed);
          }
        }
        else { //si le tilt est vers le haut
          digitalWrite(DirTiltSle,LOW);
          //Serial.println("Tilt on the top detect");
          while (StepTiltSle==P2Tilt) { 
            digitalWrite(TiltSle, LOW);
            delay(speed);
            digitalWrite(TiltSle, HIGH);
            delay(speed);
          }
        }
    }

    //Prg3
    if(digitalRead(SleP3)==HIGH){
        Serial.println("SleP3 Press");
        //Pano
            //Détéction Pano Droite/Gauche
        if(StepPanoSle>P3Pano){ //Si le pano est vers la gauche
          //Serial.println("Pano on the left detect");
          digitalWrite(DirPanoSle, HIGH);
          while (StepPanoSle==P3Pano) { 
            digitalWrite(PanoSle, LOW);
            delay(speed);
            digitalWrite(PanoSle, HIGH);
            delay(speed);
          }
        }
        else { //si le pano est sur la droite
          digitalWrite(DirPanoSle,LOW);
          //Serial.println("Pano on the right detect");
          while (StepPanoSle==P3Pano) { 
            digitalWrite(PanoSle, LOW);
            delay(speed);
            digitalWrite(PanoSle, HIGH);
            delay(speed);
          }
        }
        if(StepTiltSle<P3Tilt){ //Si le tilt est vers le bas
          //Serial.println("Tilt on bottom detect");
          digitalWrite(DirTiltSle,HIGH);
          while (StepTiltSle==P3Tilt) { 
            digitalWrite(TiltSle, LOW);
            delay(speed);
            digitalWrite(TiltSle, HIGH);
            delay(speed);
          }
        }
        else { //si le tilt est vers le haut
          digitalWrite(DirTiltSle,LOW);
          //Serial.println("Tilt on the top detect");
          while (StepTiltSle==P3Tilt) { 
            digitalWrite(TiltSle, LOW);
            delay(speed);
            digitalWrite(TiltSle, HIGH);
            delay(speed);
          }
        }
    }

    //Prg4
    if(digitalRead(SleP4)==HIGH){
        Serial.println("SleP4 Press");
        //Pano
            //Détéction Pano Droite/Gauche
        if(StepPanoSle>P4Pano){ //Si le pano est vers la gauche
          //Serial.println("Pano on the left detect");
          digitalWrite(DirPanoSle, HIGH);
          while (StepPanoSle==P4Pano) { 
            digitalWrite(PanoSle, LOW);
            delay(speed);
            digitalWrite(PanoSle, HIGH);
            delay(speed);
          }
        }
        else { //si le pano est sur la droite
          digitalWrite(DirPanoSle,LOW);
          //Serial.println("Pano on the right detect");
          while (StepPanoSle==P4Pano) { 
            digitalWrite(PanoSle, LOW);
            delay(speed);
            digitalWrite(PanoSle, HIGH);
            delay(speed);
          }
        }
        if(StepTiltSle<P4Tilt){ //Si le tilt est vers le bas
          //Serial.println("Tilt on bottom detect");
          digitalWrite(DirTiltSle,HIGH);
          while (StepTiltSle==P4Tilt) { 
            digitalWrite(TiltSle, LOW);
            delay(speed);
            digitalWrite(TiltSle, HIGH);
            delay(speed);
          }
        }
        else { //si le tilt est vers le haut
          digitalWrite(DirTiltSle,LOW);
          //Serial.println("Tilt on the top detect");
          while (StepTiltSle==P4Tilt) { 
            digitalWrite(TiltSle, LOW);
            delay(speed);
            digitalWrite(TiltSle, HIGH);
            delay(speed);
          }
        }
    }

//Retour à Zéro
  if(digitalRead(Off)==HIGH){
      Serial.println("BJ Press");
      //Serial.println(step);

      //Retour à zéro du Pano
          //Détéction Pano Droite/Gauche
      if(StepPanoSle<0){ //Si le pano est vers la gauche
        //Serial.println("Pano on the left detect");
        digitalWrite(DirPanoSle, HIGH);
        while (StepPanoSle!=0) { 
          //Serial.println("While L Exe");
          StepPanoSle = StepPanoSle+1;
          digitalWrite(PanoSle, LOW);
          delay(speed);
          digitalWrite(PanoSle, HIGH);
          delay(speed);
        }
      }
      else { //si le pano est sur la droite
        digitalWrite(DirPanoSle,LOW);
        //Serial.println("Pano on the right detect");
        while (StepPanoSle!=0) { 
          //Serial.println("while R exe");
          StepPanoSle = StepPanoSle-1;
          digitalWrite(PanoSle, LOW);
          delay(speed);
          digitalWrite(PanoSle, HIGH);
          delay(speed);
        }
      }

      //Retour à zéro du tilt
          //Détéction tilt Haut/Bas
      if(StepTiltSle<0){ //Si le tilt est vers le bas
        //Serial.println("Tilt on bottom detect");
        digitalWrite(DirTiltSle,HIGH);
        while (StepTiltSle!=0) { 
          //Serial.println("While B Exe");
          StepTiltSle = StepTiltSle+1;
          digitalWrite(TiltSle, LOW);
          delay(speed);
          digitalWrite(TiltSle, HIGH);
          delay(speed);
        }
      }
      else { //si le tilt est vers le haut
        digitalWrite(DirTiltSle,LOW);
        //Serial.println("Tilt on the top detect");
        while (StepTiltSle!=0) { 
          //Serial.println("while T exe");
          StepTiltSle = StepTiltSle-1;
          digitalWrite(TiltSle, LOW);
          delay(speed);
          digitalWrite(TiltSle, HIGH);
          delay(speed);
        }
      }
  }
}