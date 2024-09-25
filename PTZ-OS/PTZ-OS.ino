  //PTZ - V5 : Ajout sélecteur cam
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
  
    //Vitesse
  int speed=50;

    //Joystick
  int pano = 12; 
  int tilt = 14; 
  int BJ = 27; 

    //Boutton
  int Off = 17;
  int SleC1 = 34;
  int SleC2 = 35;
  int SleC3 = 32;
  int SleC4 = 33;

    //Cam control
  string CamSle = "Cam1";
  int PanoSle = PanoC1 ;
  int DirPanoSle = DirPanoC1 ;
  int TiltSle = TiltC1 ;
  int DirTiltSle = TiltC1;
  

  void setup() {
      //Caméra
        //Moteur
          //Pano
      pinMode(DirPanoC1, OUTPUT); 
      pinMode(PanoC1, OUTPUT);
        //Tilt
      pinMode(DirTiltC1, OUTPUT);
      pinMode(TiltC1, OUTPUT);

      //Joystick
      pinMode (pano, INPUT); 
      pinMode (tilt, INPUT); 
      pinMode (BJ, INPUT); 
      
      //Serial
      Serial.begin (9600);
      //Serial.print(step);
      Serial.println("PTZ CAM - READY");

  }

  void loop() {
      //Initialisation Variable
      delay(1000);
      float X, Y;
      int B;
      X = analogRead (pano) * (5.0 / 1023.0);
      Y = analogRead (tilt) * (5.0 / 1023.0);
      B = digitalRead(BJ);

      //Indication Serial Print Verif Var
      //Serial.print("BJ =");
      //Serial.print (B);
      //Serial.print("\n");
      //Serial.print ("Tilt:");
      //Serial.print (X, 4);
      //Serial.print ("V, ");
      //Serial.print ("Pano:");
      //Serial.print (Y, 4);
      //Serial.print ("V, ");
      
    //Mouvement Pano C1
      //Droite
    if(Y<=0){
        StepPanoC1 = StepPanoC1+1;
        //Serial.println("Pano go right");
        //Serial.print("\n");
        digitalWrite(DirPanoC1, HIGH);
        digitalWrite(PanoC1, LOW);
        delay(speed); // On envoie 200 impulsions pour faire tourner le moteur de 200 pas dans un sens
        digitalWrite(PanoC1, HIGH); // La valeur de tempo determine le temps entre 2 impulsions en ms
        delay(speed);
    }

      //Gauche
    if(Y>=19){
        //Serial.print("Pano go left");
        //Serial.print("\n");
        StepPanoC1 = StepPanoC1-1;
        digitalWrite(DirPanoC1, LOW);
        digitalWrite(PanoC1, LOW);
        delay(speed); // On envoie 200 impulsions pour faire tourner le moteur de 200 pas dans un sens
        digitalWrite(PanoC1, HIGH); // La valeur de tempo determine le temps entre 2 impulsions en ms
        delay(speed);
    }

    //Mouvement Tilt C1
      //Haut
    if(X<=0){
        StepTiltC1 = StepTiltC1+1;
        //Serial.println("Pano go right");
        //Serial.print("\n");
        digitalWrite(DirTiltC1, HIGH);
        digitalWrite(TiltC1, LOW);
        delay(speed); // On envoie 200 impulsions pour faire tourner le moteur de 200 pas dans un sens
        digitalWrite(TiltC1, HIGH); // La valeur de tempo determine le temps entre 2 impulsions en ms
        delay(speed);
    }

      //Bas
    if(X>=19){
        //Serial.print("Pano go left");
        //Serial.print("\n");
        StepTiltC1 = StepTiltC1-1;
        digitalWrite(DirTiltC1, LOW);
        digitalWrite(TiltC1, LOW);
        delay(speed); // On envoie 200 impulsions pour faire tourner le moteur de 200 pas dans un sens
        digitalWrite(TiltC1, HIGH); // La valeur de tempo determine le temps entre 2 impulsions en ms
        delay(speed);
    }

    //Retour à Zéro
    if(digitalRead(BJ)==LOW){
        //Serial.print("BJ Press");
        //Serial.print("\n");
        //Serial.print(step);
        //Serial.print("\n");

        //Retour à zéro du Pano
            //Détéction Pano Droite/Gauche
        if(StepPanoC1<0){ //Si le pano est vers la gauche
          //Serial.println("Pano on the left detect");
          digitalWrite(DirPanoC1,HIGH);
          while (StepPanoC1!=0) { 
            //Serial.println("While L Exe");
            StepPanoC1 = StepPanoC1+1;
            digitalWrite(PanoC1, LOW);
            delay(speed);
            digitalWrite(PanoC1, HIGH);
            delay(speed);
          }
        }
        else { //si le pano est sur la droite
          digitalWrite(DirPanoC1,LOW);
          //Serial.println("Pano on the right detect");
          while (StepPanoC1!=0) { 
            //Serial.println("while R exe");
            StepPanoC1 = StepPanoC1-1;
            digitalWrite(PanoC1, LOW);
            delay(speed);
            digitalWrite(PanoC1, HIGH);
            delay(speed);
          }
        }

        //Retour à zéro du tilt
            //Détéction tilt Haut/Bas
        if(StepTiltC1<0){ //Si le tilt est vers le bas
          //Serial.println("Tilt on bottom detect");
          digitalWrite(DirTiltC1,HIGH);
          while (StepTiltC1!=0) { 
            //Serial.println("While B Exe");
            StepTiltC1 = StepTiltC1+1;
            digitalWrite(TiltC1, LOW);
            delay(speed);
            digitalWrite(TiltC1, HIGH);
            delay(speed);
          }
        }
        else { //si le tilt est vers le haut
          digitalWrite(DirTiltC1,LOW);
          //Serial.println("Tilt on the top detect");
          while (StepTiltC1!=0) { 
            //Serial.println("while T exe");
            StepTiltC1 = StepTiltC1-1;
            digitalWrite(TiltC1, LOW);
            delay(speed);
            digitalWrite(TiltC1, HIGH);
            delay(speed);
          }
        }

    }

  }