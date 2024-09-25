  //PTZ - V6 : Ajout du sélecteur de Caméra
  //Cobe by VLTV & GAB
  //Dev by GALEX.CO by GALEXGROUP
  //Projet Main by Léo TORRAS and CARL KB

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
  int PanoC2 = 0;
  int DirPanoC2 = 0;
  int StepPanoC2 = 0;
        //TILT
  int TiltC2 = 0;
  int DirTiltC2 = 0;
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
        //Serial.print("\n");
        digitalWrite(DirPanoSle, HIGH);
        digitalWrite(PanoSle, LOW);
        delay(speed); // On envoie 200 impulsions pour faire tourner le moteur de 200 pas dans un sens
        digitalWrite(PanoSle, HIGH); // La valeur de tempo determine le temps entre 2 impulsions en ms
        delay(speed);
    }

      //Gauche
    if(Y>=19){
        //Serial.print("Pano go left");
        //Serial.print("\n");
        StepPanoSle = StepPanoSle-1;
        digitalWrite(DirPanoSle, LOW);
        digitalWrite(PanoSle, LOW);
        delay(speed); // On envoie 200 impulsions pour faire tourner le moteur de 200 pas dans un sens
        digitalWrite(PanoSle, HIGH); // La valeur de tempo determine le temps entre 2 impulsions en ms
        delay(speed);
    }

    //Mouvement Tilt
      //Haut
    if(X<=0){
        StepTiltSle = StepTiltSle+1;
        //Serial.println("Pano go right");
        //Serial.print("\n");
        digitalWrite(DirTiltSle, HIGH);
        digitalWrite(TiltSle, LOW);
        delay(speed); // On envoie 200 impulsions pour faire tourner le moteur de 200 pas dans un sens
        digitalWrite(TiltSle, HIGH); // La valeur de tempo determine le temps entre 2 impulsions en ms
        delay(speed);
    }

      //Bas
    if(X>=19){
        //Serial.print("Pano go left");
        //Serial.print("\n");
        StepTiltSle = StepTiltSle-1;
        digitalWrite(DirTiltSle, LOW);
        digitalWrite(TiltSle, LOW);
        delay(speed); // On envoie 200 impulsions pour faire tourner le moteur de 200 pas dans un sens
        digitalWrite(TiltSle, HIGH); // La valeur de tempo determine le temps entre 2 impulsions en ms
        delay(speed);
    }

    //Retour à Zéro
    if(digitalRead(BJ)==HIGH){
        Serial.print("BJ Press");
        Serial.print("\n");
        //Serial.print(step);
        //Serial.print("\n");

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