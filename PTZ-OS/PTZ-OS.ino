  //PTZ - V2 : control pano with analog joystick OK
  int speed=50; // Cette valeur détermine la vitesse du moteur, 1 = rapide, 100 = lent
  int pano = 12; // signal de l'axe X sur entrée A0
  int tilt = 14; // signal de l'axe Y sur entrée A1
  int BJ = 17; // Bouton-poussoir en broche 7
  int step = 0;
  int PanoC1 = 16;
  int DirPanoC1 = 4;

  void setup() {
      pinMode(DirPanoC1, OUTPUT); // On initialise les broches D4 et D5 en sorties
      pinMode(PanoC1, OUTPUT);
      pinMode (pano, INPUT); // définition de A0 comme une entrée
      pinMode (tilt, INPUT); // définition de A1 comme une entrée
      pinMode (BJ, INPUT); // définition de 7 comme une entrée
      //digitalWrite(BJ, HIGH); // Activation de la résistance de Pull-Up interne de la carte Uno
      Serial.begin (9600);
      //Serial.print(step);
      Serial.println("PTZ CAM - READY");

  }

  void loop() {
      delay(1000);
      float X, Y;
      int B;
      X = analogRead (pano) * (5.0 / 1023.0);
      Y = analogRead (tilt) * (5.0 / 1023.0);
      B = digitalRead(BJ);

      //Serial.print("BJ =");
      //Serial.print (B);
      //Serial.print("\n");
      //Serial.print ("Tilt:");
      //Serial.print (X, 4);
      //Serial.print ("V, ");
      //Serial.print ("Pano:");
      //Serial.print (Y, 4);
      //Serial.print ("V, ");
      

    if(Y<=0){
        step = step+1;
        //Serial.println("Pano go right");
        //Serial.print("\n");
        digitalWrite(DirPanoC1, HIGH);
        digitalWrite(PanoC1, LOW);
        delay(speed); // On envoie 200 impulsions pour faire tourner le moteur de 200 pas dans un sens
        digitalWrite(PanoC1, HIGH); // La valeur de tempo determine le temps entre 2 impulsions en ms
        delay(speed);
    }

    if(Y>=19){
        //Serial.print("Pano go left");
        //Serial.print("\n");
        step = step-1;
        digitalWrite(DirPanoC1, LOW);
        digitalWrite(PanoC1, LOW);
        delay(speed); // On envoie 200 impulsions pour faire tourner le moteur de 200 pas dans un sens
        digitalWrite(PanoC1, HIGH); // La valeur de tempo determine le temps entre 2 impulsions en ms
        delay(speed);
    }

    if(digitalRead(BJ)==HIGH){
        //Serial.print("BJ Press");
        //Serial.print("\n");
        //Serial.print(step);
        //Serial.print("\n");
        if(step<0){ //Si le pano est vers la gauche
          //Serial.println("Pano on the left detect");
          digitalWrite(DirPanoC1,HIGH);
          while (step!=0) { 
            //Serial.println("While L Exe");
            step = step+1;
            digitalWrite(PanoC1, LOW);
            delay(speed);
            digitalWrite(PanoC1, HIGH);
            delay(speed);
          }
        }
        else { //si le pano est sur la droite
          digitalWrite(DirPanoC1,LOW);
          //Serial.println("Pano on the right detect");
          while (step!=0) { 
            //Serial.println("while R exe");
            step = step-1;
            digitalWrite(PanoC1, LOW);
            delay(speed);
            digitalWrite(PanoC1, HIGH);
            delay(speed);
          }
        }
    }

  }