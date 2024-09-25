/*
- PTZ - V10 : Correction de bug liée a l'éxécution des programe et remise a niveau du protocle de mise hors-tenssion
- Finalisé le 18/09/2024
- Cobe by VLTV & GAB
- Dev by GALEX.CO by GALEXGROUP
- Projet Main by Léo TORRAS and CARL KB
- Projet à déstination du plateau TV de LTPSN
*/

//Def Variables
  //Caméra
    //C1
      //PANO
        int PanoC1 = 16; //Pin moteur Pano Cam 1
        int DirPanoC1 = 4; //Pin direction moteur Pano Cam 1
        int StepPanoC1 = 0; //Variable Step Pano Cam 1
      //TILT
        int TiltC1 = 18; //Pin moteur Tilt Cam 1
        int DirTiltC1 = 5; //Pin direction moteur Tilt Cam 1
        int StepTiltC1 = 0; //Variable Step Tilt Cam 1
    //Fin C1

    //C2
      //PANO
        int PanoC2 = 23; //Pin moteur Pano Cam 2
        int DirPanoC2 = 22; //Pin direction moteur Pano Cam 2
        int StepPanoC2 = 0; //Variable Step Pano Cam 2
      //TILT
        int TiltC2 = 19; //Pin moteur Tilt Cam 2
        int DirTiltC2 = 21; //Pin direction moteur Tilt Cam 2
        int StepTiltC2 = 0; //Variable Step Tilt Cam 2
    //Fin C2

    //C3
      //PANO
        int PanoC3 = 0; //Pin moteur Pano Cam 3
        int DirPanoC3 = 0; //Pin direction moteur Pano Cam 3
        int StepPanoC3 = 0; //Variable Step Pano Cam 3
      //TILT
        int TiltC3 = 0; //Pin moteur Tilt Cam 3
        int DirTiltC3 = 0; //Pin direction moteur Tilt Cam 3
        int StepTiltC3 = 0; //Variable Step Tilt Cam 3
    //Fin C3

    //C4
      //PANO
        int PanoC4 = 0; //Pin moteur Pano Cam 4
        int DirPanoC4 = 0; //Pin direction moteur Pano Cam 4
        int StepPanoC4 = 0; //Variable Step Pano Cam 4
      //TILT
        int TiltC4 = 0; //Pin moteur Tilt Cam 4
        int DirTiltC4 = 0; //Pin direction moteur Tilt Cam 4
        int StepTiltC4 = 0; //Variable Step Tilt Cam 4
    //Fin C4
    //Ready to Off
        //bool CSleOff = true; //Variable de mise hors tension Cam Séléctionné
        bool C1off = false; //Variable de mise hors tension Cam 1
        bool C2off = false; //Variable de mise hors tension Cam 2
        bool C3off = false; //Variable de mise hors tension Cam 3
        bool C4off = false; //Variable de mise hors tension Cam 4
    //Fin Ready to Off
  //Fin Caméra

  //Vitesse
    int speed=200; //Vitesse de déplacement des moteurs + speed est élevé - le moteur va vite
  //Fin Vitesse

  //Joystick
    int pano = 12; //Pin Joystick Pano
    int tilt = 14; //Pin Joystick Tilt
    int BJ = 17; //Pin Joystick Boutton
  //Fin Joystick

  //Boutton
    int Off = 17; //Pin Boutton Off
    int SleC1 = 34; //Pin Boutton Selection Cam 1
    int SleC2 = 35; //Pin Boutton Selection Cam 2
    int SleC3 = 32; //Pin Boutton Selection Cam 3
    int SleC4 = 33; //Pin Boutton Selection Cam 4
    int Set = 15; //Pin Boutton Set Prg
  //Fin Boutton

  //PRG
    //PRG 1
      int SleP1 = 25; //Pin Boutton Selection Prg 1
      int P1Pano; //Variable Mémoire Pano Prg 1
      int P1Tilt; //Variable Mémoire Tilt Prg 1
    //Fin PRG 1

    //PRG 2
      int SleP2 = 26; //Pin Boutton Selection Prg 2
      int P2Pano; //Variable Mémoire Pano Prg 2
      int P2Tilt; //Variable Mémoire Tilt Prg 2
    //Fin PRG 2

    //PRG 3
      int SleP3 = 13; //Pin Boutton Selection Prg 3
      int P3Pano; //Variable Mémoire Pano Prg 3
      int P3Tilt; //Variable Mémoire Tilt Prg 3
    //Fin PRG 3

    //PRG 4
      int SleP4 = 2; //Pin Boutton Selection Prg 4
      int P4Pano; //Variable Mémoire Pano Prg 4
      int P4Tilt; //Variable Mémoire Tilt Prg 4
    //Fin PRG 4
  //Fin PRG

  //Cam control
    int CamSle = 1; //Variable de la caméra séléctionné
    int PanoSle = PanoC1 ; //Variable Pano Cam Séléctionné
    int DirPanoSle = DirPanoC1 ; //Variable Direction Pano Cam Séléctionné
    int TiltSle = TiltC1 ; //Variable Tilt Cam Séléctionné
    int DirTiltSle = DirTiltC1; //Variable Direction Tilt Cam Séléctionné 
    int StepPanoSle = StepPanoC1 ; //Variable Step Pano Cam Séléctionné
    int StepTiltSle = StepTiltC1 ; //Variable Step Tilt Cam Séléctionné
  //Fin Cam control
//Fin Def Variables

void setup() {
  //Setup
    //Caméra
      //Moteur C1
        //Pano
          pinMode(DirPanoC1, OUTPUT); //Direction moteur Pano Cam 1 pin mode
          pinMode(PanoC1, OUTPUT); //Moteur Pano Cam 1 pin mode
        //Fin Pano

        //Tilt
          pinMode(DirTiltC1, OUTPUT); //Direction moteur Tilt Cam 1 pin mode
          pinMode(TiltC1, OUTPUT); //Moteur Tilt Cam 1 pin mode
        //Fin Tilt
      //Fin Moteur C1

      //Moteur C2
        //Pano
          pinMode(DirPanoC2, OUTPUT); 
          pinMode(PanoC2, OUTPUT);
        //Fin Pano
        //Tilt
          pinMode(DirTiltC2, OUTPUT);
          pinMode(TiltC2, OUTPUT);
        //Fin Tilt
      //Fin Moteur C2

      //Selecteur Cam
        //Variable Selection 
          //Pano
            pinMode(DirPanoSle, OUTPUT); 
            pinMode(PanoSle, OUTPUT);
          //Fin Pano
          //Tilt
            pinMode(DirTiltSle, OUTPUT);
            pinMode(TiltSle, OUTPUT);
          //Fin Tilt
        //Fin Variable Selection

        //Button Selection
          pinMode (SleC1, INPUT);
          pinMode (SleC2, INPUT);
          pinMode (SleC3, INPUT);
          pinMode (SleC4, INPUT);
        //Fin Button Selection
    
      //Fin Selecteur Cam
    //Fin Caméra

    //Joystick
      pinMode (pano, INPUT); 
      pinMode (tilt, INPUT); 
      pinMode (BJ, INPUT); 
    //Fin Joystick
    
    //Serial
      Serial.begin (9600);
      Serial.println("PTZ CAM - V10");
      Serial.println("DEV BY GALEX.CO by GALEXGROUP");
      Serial.println("PROJET MAIN BY LEO TORRAS AND CARL KB");
      Serial.println("PTZ CAM - READY");
    //Fin Serial

    //Preset
      pinMode(Set, INPUT);
      pinMode(SleP1, INPUT);
      pinMode(SleP2, INPUT);
      pinMode(SleP3, INPUT);
      pinMode(SleP4, INPUT);
    //Fin Preset
  //Fin Setup
}

void loop() {

  //Initialisation Variable
    delay(speed);
    float X, Y;
    int B;
    X = analogRead (pano) * (5.0 / 1023.0);
    Y = analogRead (tilt) * (5.0 / 1023.0);
    B = digitalRead(BJ);
  //Fin Initialisation Variable

  //Selecteur
    //Select Cam 1
      if (digitalRead(SleC1) == HIGH){
        switch(CamSle){
          case 2:
            Serial.println("Cam 2 Saved");
            StepPanoC2 = StepPanoSle;
            StepTiltC2 = StepTiltSle;
            break;
          case 3:
            Serial.println("Cam 3 Saved");
            StepPanoC3 = StepPanoSle;
            StepTiltC3 = StepTiltSle;
            break;
          case 4:
            Serial.println("Cam 4 Saved");
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
    //Fin Select Cam 1

    //Select Cam 2
      if (digitalRead(SleC2) == HIGH){
        switch(CamSle){
          case 1:
            Serial.println("Cam 1 Saved");
            StepPanoC1 = StepPanoSle;
            StepTiltC1 = StepTiltSle;
            break;
          case 3:
            Serial.println("Cam 3 Saved");
            StepPanoC3 = StepPanoSle;
            StepTiltC3 = StepTiltSle;
            break;
          case 4:
            Serial.println("Cam 4 Saved");
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
    //Fin Select Cam 2

    //Select Cam 3
      /*if (digitalRead(SleC3) == HIGH){
        switch(CamSle){
          case 1:
            Serial.println("Cam 1 Saved");
            StepPanoC1 = StepPanoSle;
            StepTiltC1 = StepTiltSle;
            break;
          case 2:
            Serial.println("Cam 2 Saved");
            StepPanoC2 = StepPanoSle;
            StepTiltC2 = StepTiltSle;
            break;
          case 4:
            Serial.println("Cam 4 Saved");
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
      }*/
    //Fin Select Cam 3

    //Select Cam 4
      if (digitalRead(SleC4) == HIGH){
        switch(CamSle){
          case 1:
            Serial.println("Cam 1 Saved");
            StepPanoC1 = StepPanoSle;
            StepTiltC1 = StepTiltSle;
            break;
          case 2:
            Serial.println("Cam 2 Saved");
            StepPanoC2 = StepPanoSle;
            StepTiltC2 = StepTiltSle;
            break;
          case 3:
            Serial.println("Cam 3 Saved");
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
    //Fin Select Cam 4
  //Fin Selecteur
  
  //Mouvement Caméra
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
        //Fin Droite

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
        //Fin Gauche
    //Fin Mouvement Pano

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
        //Fin Haut

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
        //Fin Bas
    //Fin Mouvement Tilt
  //Fin Mouvement Caméra

  //Set Prg
    //Set Prg1
        if(digitalRead(Set)==HIGH){
        Serial.println("Preset 1 Save");
        P1Pano = 0;
        P1Tilt = 0;
        P1Pano = StepPanoSle;
        P1Tilt = StepTiltSle;
        Serial.println(P1Pano);
        Serial.println(P1Tilt);
        }
    //Fin Set Prg1

    //Set Prg2
        if(digitalRead(SleP2)==HIGH && digitalRead(Set)==HIGH){
        Serial.println("Preset 2 Save");
        P2Pano = 0;
        P2Tilt = 0;
        P2Pano = StepPanoSle;
        P2Tilt = StepTiltSle;
        }
    //Fin Set Prg2

    //Set Prg3
        if(digitalRead(SleP3)==HIGH && digitalRead(Set)==HIGH){
        Serial.println("Preset 3 Save");
        P3Pano = 0;
        P3Tilt = 0;
        P3Pano = StepPanoSle;
        P3Tilt = StepTiltSle;
        }
    //Fin Set Prg3

    //Set Prg4
        if(digitalRead(SleP4)==HIGH && digitalRead(Set)==HIGH){
        Serial.println("Preset 4 Save");
        P4Pano = 0;
        P4Tilt = 0;
        P4Pano = StepPanoSle;
        P4Tilt = StepTiltSle;
        }
    //Fin Set Prg4
  //Fin Set Prg

  //Exe Prg
        //Prg1
            if(digitalRead(SleP1)==HIGH){ //Si le boutton Prg 1 est pressé
                Serial.println("SleP1 Press"); //Affichage dans le moniteur série
                Serial.print("P1 Pano = ");
                Serial.println(P1Pano);
                Serial.print("P1 Tilt = ");
                Serial.println(P1Tilt);

            //Vérif Cam Pos Prg
                if(StepPanoSle==P1Pano && StepTiltSle==P1Tilt){ //Si la caméra est déjà sur la position du Prg 
                    Serial.print("Cam ");
                    Serial.print(CamSle);
                    Serial.println(" is allready on the position of Prg 1.");
                }
                else { //Si la caméra n'est pas sur la position du Prg 
                    if(StepPanoSle==P1Pano){ //On vérifie si le Pano de la caméra n'est pas déjà sur la position du programe
                        Serial.print("Pano Cam ");
                        Serial.print(CamSle);
                        Serial.println(" is allready on the position of Prg 1.");
                    }
                    else{
                        if(StepTiltSle==P1Tilt){ //On vérifie si le Tilt de la caméra n'est pas déjà sur la position du programe
                            Serial.print("Tilt Cam ");
                            Serial.print(CamSle);
                            Serial.println(" is allready on the position of Prg 1.");
                        }
            //Fin Vérif Cam Pos Prg

                        else { //La caméra n'est pas sur la position du programe donc on met la caméra en position
                            //Pano
                                //Détéction Pano Droite/Gauche
                                if(StepPanoSle<P1Pano){ //Si le pano est vers la gauche
                                    Serial.println("Pano on the left detect");
                                    digitalWrite(DirPanoSle, HIGH);
                                    while (StepPanoSle!=P1Pano) { //On règle le pano sur la position du programe
                                    StepPanoSle = StepPanoSle+1;
                                    digitalWrite(PanoSle, LOW);
                                    delay(speed);
                                    digitalWrite(PanoSle, HIGH);
                                    delay(speed);
                                    }
                                }
                                else { //si le pano est sur la droite
                                    digitalWrite(DirPanoSle,LOW);
                                    Serial.println("Pano on the right detect");
                                    while (StepPanoSle!=P1Pano) { //On règle le pano sur la position du programe
                                    StepPanoSle = StepPanoSle-1;
                                    digitalWrite(PanoSle, LOW);
                                    delay(speed);
                                    digitalWrite(PanoSle, HIGH);
                                    delay(speed);
                                    }
                                }
                            //Fin Pano
                            //Tilt
                                if(StepTiltSle<P1Tilt){ //Si le tilt est vers le bas
                                    Serial.println("Tilt on bottom detect");
                                    digitalWrite(DirTiltSle,HIGH);
                                    while (StepTiltSle!=P1Tilt) { //On règle le tilt sur la position du programe
                                    StepTiltSle = StepTiltSle+1;
                                    digitalWrite(TiltSle, LOW);
                                    delay(speed);
                                    digitalWrite(TiltSle, HIGH);
                                    delay(speed);
                                    }
                                }
                                else { //si le tilt est vers le haut
                                    digitalWrite(DirTiltSle,LOW);
                                    Serial.println("Tilt on the top detect");
                                    while (StepTiltSle!=P1Tilt) {  //On règle le tilt sur la position du programe
                                    StepTiltSle = StepTiltSle-1;
                                    digitalWrite(TiltSle, LOW);
                                    delay(speed);
                                    digitalWrite(TiltSle, HIGH);
                                    delay(speed);
                                    }
                                }
                            //Fin Tilt
                        }
                    
                    }
                }
            }
        //Fin Prg1

        //Prg2
            if(digitalRead(SleP2)==HIGH){ //Si le boutton Prg 2 est pressé
                Serial.println("SleP2 Press"); //Affichage dans le moniteur série
                Serial.print("P2 Pano = ");
                Serial.println(P2Pano);
                Serial.print("P2 Tilt = ");
                Serial.println(P2Tilt);

            //Vérif Cam Pos Prg
                if(StepPanoSle==P2Pano && StepTiltSle==P2Tilt){ //Si la caméra est déjà sur la position du Prg 
                    Serial.print("Cam ");
                    Serial.print(CamSle);
                    Serial.println(" is allready on the position of Prg 2.");
                }
                else { //Si la caméra n'est pas sur la position du Prg 
                    if(StepPanoSle==P2Pano){ //On vérifie si le Pano de la caméra n'est pas déjà sur la position du programe
                        Serial.print("Pano Cam ");
                        Serial.print(CamSle);
                        Serial.println(" is allready on the position of Prg 2.");
                    }
                    else{
                        if(StepTiltSle==P2Tilt){ //On vérifie si le Tilt de la caméra n'est pas déjà sur la position du programe
                            Serial.print("Tilt Cam ");
                            Serial.print(CamSle);
                            Serial.println(" is allready on the position of Prg 2.");
                        }
            //Fin Vérif Cam Pos Prg

                        else { //La caméra n'est pas sur la position du programe donc on met la caméra en position
                            //Pano
                                //Détéction Pano Droite/Gauche
                                if(StepPanoSle<P2Pano){ //Si le pano est vers la gauche
                                    Serial.println("Pano on the left detect");
                                    digitalWrite(DirPanoSle, HIGH);
                                    while (StepPanoSle==P2Pano) { //On règle le pano sur la position du programe
                                      StepPanoSle = StepPanoSle+1;
                                      digitalWrite(PanoSle, LOW);
                                      delay(speed);
                                      digitalWrite(PanoSle, HIGH);
                                      delay(speed);
                                    }
                                }
                                else { //si le pano est sur la droite
                                    digitalWrite(DirPanoSle,LOW);
                                    Serial.println("Pano on the right detect");
                                    while (StepPanoSle==P2Pano) { //On règle le pano sur la position du programe
                                    StepPanoSle = StepPanoSle-1;
                                    digitalWrite(PanoSle, LOW);
                                    delay(speed);
                                    digitalWrite(PanoSle, HIGH);
                                    delay(speed);
                                    }
                                }
                            //Fin Pano
                            //Tilt
                                if(StepTiltSle<P2Tilt){ //Si le tilt est vers le bas
                                    Serial.println("Tilt on bottom detect");
                                    digitalWrite(DirTiltSle,HIGH);
                                    while (StepTiltSle==P2Tilt) { //On règle le tilt sur la position du programe
                                      StepTiltSle = StepTiltSle+1;
                                      digitalWrite(TiltSle, LOW);
                                      delay(speed);
                                      digitalWrite(TiltSle, HIGH);
                                      delay(speed);
                                    }
                                }
                                else { //si le tilt est vers le haut
                                    digitalWrite(DirTiltSle,LOW);
                                    Serial.println("Tilt on the top detect");
                                    while (StepTiltSle==P2Tilt) {  //On règle le tilt sur la position du programe
                                      StepTiltSle = StepTiltSle-1;
                                      digitalWrite(TiltSle, LOW);
                                      delay(speed);
                                      digitalWrite(TiltSle, HIGH);
                                      delay(speed);
                                    }
                                }
                            //Fin Tilt
                        }
                    }
                }
            }
        //Fin Prg2

       //Prg3
            if(digitalRead(SleP3)==HIGH){ //Si le boutton Prg 3 est pressé
                Serial.println("SleP3 Press"); //Affichage dans le moniteur série
                Serial.print("P3 Pano = ");
                Serial.println(P3Pano);
                Serial.print("P3 Tilt = ");
                Serial.println(P3Tilt);

            //Vérif Cam Pos Prg
                if(StepPanoSle==P3Pano && StepTiltSle==P3Tilt){ //Si la caméra est déjà sur la position du Prg 
                    Serial.print("Cam ");
                    Serial.print(CamSle);
                    Serial.println(" is allready on the position of Prg 3.");
                }
                else { //Si la caméra n'est pas sur la position du Prg 
                    if(StepPanoSle==P3Pano){ //On vérifie si le Pano de la caméra n'est pas déjà sur la position du programe
                        Serial.print("Pano Cam ");
                        Serial.print(CamSle);
                        Serial.println(" is allready on the position of Prg 3.");
                    }
                    else{
                        if(StepTiltSle==P3Tilt){ //On vérifie si le Tilt de la caméra n'est pas déjà sur la position du programe
                            Serial.print("Tilt Cam ");
                            Serial.print(CamSle);
                            Serial.println(" is allready on the position of Prg 2.");
                        }
            //Fin Vérif Cam Pos Prg

                        else { //La caméra n'est pas sur la position du programe donc on met la caméra en position
                            //Pano
                                //Détéction Pano Droite/Gauche
                                if(StepPanoSle<P3Pano){ //Si le pano est vers la gauche
                                    Serial.println("Pano on the left detect");
                                    digitalWrite(DirPanoSle, HIGH);
                                    while (StepPanoSle==P3Pano) { //On règle le pano sur la position du programe
                                    StepPanoSle = StepPanoSle+1;
                                    digitalWrite(PanoSle, LOW);
                                    delay(speed);
                                    digitalWrite(PanoSle, HIGH);
                                    delay(speed);
                                    }
                                }
                                else { //si le pano est sur la droite
                                    digitalWrite(DirPanoSle,LOW);
                                    Serial.println("Pano on the right detect");
                                    while (StepPanoSle==P3Pano) { //On règle le pano sur la position du programe
                                    StepPanoSle = StepPanoSle-1;
                                    digitalWrite(PanoSle, LOW);
                                    delay(speed);
                                    digitalWrite(PanoSle, HIGH);
                                    delay(speed);
                                    }
                                }
                            //Fin Pano
                            //Tilt
                                if(StepTiltSle<P3Tilt){ //Si le tilt est vers le bas
                                    Serial.println("Tilt on bottom detect");
                                    digitalWrite(DirTiltSle,HIGH);
                                    while (StepTiltSle==P3Tilt) { //On règle le tilt sur la position du programe
                                      StepTiltSle = StepTiltSle+1;
                                      digitalWrite(TiltSle, LOW);
                                      delay(speed);
                                      digitalWrite(TiltSle, HIGH);
                                      delay(speed);
                                    }
                                }
                                else { //si le tilt est vers le haut
                                    digitalWrite(DirTiltSle,LOW);
                                    Serial.println("Tilt on the top detect");
                                    while (StepTiltSle==P3Tilt) {  //On règle le tilt sur la position du programe
                                      StepTiltSle = StepTiltSle-1;
                                      digitalWrite(TiltSle, LOW);
                                      delay(speed);
                                      digitalWrite(TiltSle, HIGH);
                                      delay(speed);
                                    }
                                }
                            //Fin Tilt
                        }
                    
                    }
                }
            }
        //Fin Prg3
        
       //Prg4
            if(digitalRead(SleP4)==HIGH){ //Si le boutton Prg 4 est pressé
                Serial.println("SleP4 Press"); //Affichage dans le moniteur série
                Serial.print("P4 Pano = ");
                Serial.println(P4Pano);
                Serial.print("P4 Tilt = ");
                Serial.println(P4Tilt);

            //Vérif Cam Pos Prg
                if(StepPanoSle==P4Pano && StepTiltSle==P4Tilt){ //Si la caméra est déjà sur la position du Prg 
                    Serial.print("Cam ");
                    Serial.print(CamSle);
                    Serial.println(" is allready on the position of Prg 4.");
                }
                else { //Si la caméra n'est pas sur la position du Prg 
                    if(StepPanoSle==P4Pano){ //On vérifie si le Pano de la caméra n'est pas déjà sur la position du programe
                        Serial.print("Pano Cam ");
                        Serial.print(CamSle);
                        Serial.println(" is allready on the position of Prg 4.");
                    }
                    else{
                        if(StepTiltSle==P4Tilt){ //On vérifie si le Tilt de la caméra n'est pas déjà sur la position du programe
                            Serial.print("Tilt Cam ");
                            Serial.print(CamSle);
                            Serial.println(" is allready on the position of Prg 4.");
                        }
            //Fin Vérif Cam Pos Prg

                        else { //La caméra n'est pas sur la position du programe donc on met la caméra en position
                            //Pano
                                //Détéction Pano Droite/Gauche
                                if(StepPanoSle<P4Pano){ //Si le pano est vers la gauche
                                    Serial.println("Pano on the left detect");
                                    digitalWrite(DirPanoSle, HIGH);
                                    while (StepPanoSle==P4Pano) { //On règle le pano sur la position du programe
                                      StepPanoSle = StepPanoSle+1;
                                      digitalWrite(PanoSle, LOW);
                                      delay(speed);
                                      digitalWrite(PanoSle, HIGH);
                                      delay(speed);
                                    }
                                }
                                else { //si le pano est sur la droite
                                    digitalWrite(DirPanoSle,LOW);
                                    Serial.println("Pano on the right detect");
                                    while (StepPanoSle==P4Pano) { //On règle le pano sur la position du programe
                                      StepPanoSle = StepPanoSle-1;
                                      digitalWrite(PanoSle, LOW);
                                      delay(speed);
                                      digitalWrite(PanoSle, HIGH);
                                      delay(speed);
                                    }
                                }
                            //Fin Pano
                            //Tilt
                                if(StepTiltSle<P4Tilt){ //Si le tilt est vers le bas
                                    Serial.println("Tilt on bottom detect");
                                    digitalWrite(DirTiltSle,HIGH);
                                    while (StepTiltSle==P4Tilt) { //On règle le tilt sur la position du programe
                                      StepTiltSle = StepTiltSle+1;
                                      digitalWrite(TiltSle, LOW);
                                      delay(speed);
                                      digitalWrite(TiltSle, HIGH);
                                      delay(speed);
                                    }
                                }
                                else { //si le tilt est vers le haut
                                    digitalWrite(DirTiltSle,LOW);
                                    Serial.println("Tilt on the top detect");
                                    while (StepTiltSle==P4Tilt) {  //On règle le tilt sur la position du programe
                                      StepTiltSle = StepTiltSle-1;
                                      digitalWrite(TiltSle, LOW);
                                      delay(speed);
                                      digitalWrite(TiltSle, HIGH);
                                      delay(speed);
                                    }
                                }
                            //Fin Tilt
                        }
                    
                    }
                }
            }
        //Fin Prg4


  //Fin Exe Prg

  //Protocole de Mise Hors Tension
        if(digitalRead(Off)==HIGH){ //Si le boutton Off est pressé
            C1off = false;
            C2off = false;
            C3off = false;
            C4off = false;
            Serial.print("C1off = ");
            Serial.println(C1off);
            Serial.print("C2off = ");
            Serial.println(C2off);
            Serial.print("C3off = ");
            Serial.println(C3off);
            Serial.print("C4off = ");
            Serial.println(C4off);
            Serial.println("Off Press"); //Affichage dans le moniteur série
            Serial.println("Protocol de Mise Hors-Tension Lancée");

            switch(CamSle){ //Sauvegarde des positions des caméras
              case 1:
                Serial.println("Cam 1 Saved");
                StepPanoC1 = StepPanoSle;
                StepTiltC1 = StepTiltSle;
                break;
              case 2:
                  Serial.println("Cam 2 Saved");
                  StepPanoC2 = StepPanoSle;
                  StepTiltC2 = StepTiltSle;
                  break;
              case 3:
                  Serial.println("Cam 3 Saved");
                  StepPanoC3 = StepPanoSle;
                  StepTiltC3 = StepTiltSle;
                  break;
              case 4:
                  Serial.println("Cam 4 Saved");
                  StepPanoC4 = StepPanoSle;
                  StepTiltC4 = StepTiltSle;
                  break;
            }

            do {
                Serial.println("While Exe");
                //CSleOff = false;
                if (C1off==false){
                    switch(CamSle){
                        case 2:
                            Serial.println("Cam 2 Saved");
                            StepPanoC2 = StepPanoSle;
                            StepTiltC2 = StepTiltSle;
                            break;
                        case 3:
                            Serial.println("Cam 3 Saved");
                            StepPanoC3 = StepPanoSle;
                            StepTiltC3 = StepTiltSle;
                            break;
                        case 4:
                            Serial.println("Cam 4 Saved");
                            StepPanoC4 = StepPanoSle;
                            StepTiltC4 = StepTiltSle;
                            break;
                    }
                    //Cam 1
                        CamSle = 1;
                        //CSleOff = C1off;
                        C1off = true;
                        Serial.print("Cam : ");
                        Serial.print(CamSle);
                        Serial.println(" select");
                        PanoSle = PanoC1 ;
                        DirPanoSle = DirPanoC1 ;
                        TiltSle = TiltC1 ;
                        DirTiltSle = DirTiltC1;
                        StepPanoSle = StepPanoC1 ;
                        StepTiltSle = StepTiltC1 ;
                        delay(1000);
                    //Fin Cam 1
                }
                else{
                    Serial.println("Cam 1 ready to off");
                    Serial.println("ELSE EXE");
                    if (C2off==false){
                        switch(CamSle){
                            case 1:
                                Serial.println("Cam 1 Saved");
                                StepPanoC1 = StepPanoSle;
                                StepTiltC1 = StepTiltSle;
                                break;
                            case 3:
                                Serial.println("Cam 3 Saved");
                                StepPanoC3 = StepPanoSle;
                                StepTiltC3 = StepTiltSle;
                                break;
                            case 4:
                                Serial.println("Cam 4 Saved");
                                StepPanoC4 = StepPanoSle;
                                StepTiltC4 = StepTiltSle;
                                break;
                        }
                        //Cam 2
                            CamSle = 2;
                            //CSleOff = C2off;
                            C2off = true;
                            Serial.print("Cam : ");
                            Serial.print(CamSle);
                            Serial.println(" select");
                            PanoSle = PanoC2 ;
                            DirPanoSle = DirPanoC2 ;
                            TiltSle = TiltC2 ;
                            DirTiltSle = DirTiltC2;
                            StepPanoSle = StepPanoC2 ;
                            StepTiltSle = StepTiltC2 ;
                            delay(1000);
                        //Fin Cam 2
                    }
                    else{
                        Serial.println("Cam 2 ready to off");
                        if (C3off==false){
                            switch(CamSle){
                                case 1:
                                    Serial.println("Cam 1 Saved");
                                    StepPanoC1 = StepPanoSle;
                                    StepTiltC1 = StepTiltSle;
                                    break;
                                case 2:
                                    Serial.println("Cam 2 Saved");
                                    StepPanoC2 = StepPanoSle;
                                    StepTiltC2 = StepTiltSle;
                                    break;
                                case 4:
                                    Serial.println("Cam 4 Saved");
                                    StepPanoC4 = StepPanoSle;
                                    StepTiltC4 = StepTiltSle;
                                    break;
                            }
                            //Cam 3
                                CamSle = 3;
                                //CSleOff = C3off;
                                C3off = true;
                                Serial.print("Cam : ");
                                Serial.print(CamSle);
                                Serial.println(" select");
                                PanoSle = PanoC3 ;
                                DirPanoSle = DirPanoC3 ;
                                TiltSle = TiltC3 ;
                                DirTiltSle = DirTiltC3;
                                StepPanoSle = StepPanoC3 ;
                                StepTiltSle = StepTiltC3 ;
                                delay(1000);
                            //Fin Cam 3
                        }
                        else {
                            Serial.println("Cam 3 ready to off");
                            if (C4off==false){
                                switch(CamSle){
                                    case 1:
                                        Serial.println("Cam 1 Saved");
                                        StepPanoC1 = StepPanoSle;
                                        StepTiltC1 = StepTiltSle;
                                        break;
                                    case 2:
                                        Serial.println("Cam 2 Saved");
                                        StepPanoC2 = StepPanoSle;
                                        StepTiltC2 = StepTiltSle;
                                        break;
                                    case 3:
                                        Serial.println("Cam 3 Saved");
                                        StepPanoC3 = StepPanoSle;
                                        StepTiltC3 = StepTiltSle;
                                        break;
                                }
                                //Cam 4
                                    CamSle = 4;
                                    //CSleOff = C4off;
                                    C4off = true;
                                    Serial.print("Cam : ");
                                    Serial.print(CamSle);   
                                    Serial.println(" select");
                                    PanoSle = PanoC4 ;
                                    DirPanoSle = DirPanoC4 ;
                                    TiltSle = TiltC4 ;
                                    DirTiltSle = DirTiltC4;
                                    StepPanoSle = StepPanoC4 ;
                                    StepTiltSle = StepTiltC4 ;
                                    delay(1000);
                                //Fin Cam 4      
                            }
                        }                              
                    }
                }

                //Vérif Cam Pos off
                    if(StepPanoSle==0 && StepTiltSle==0){ //Si la caméra est déjà sur la position off
                        Serial.print("Cam ");
                        Serial.print(CamSle);
                        Serial.println(" on 0 pos");
                        //CSleOff = true;
                    }
                    else { //Si la caméra n'est pas sur la position Off 
                        if(StepPanoSle==0){ //On vérifie si le Pano de la caméra n'est pas déjà sur la position off
                            Serial.print("Pano Cam ");
                            Serial.print(CamSle);
                            Serial.println(" is allready on the position off.");
                        }
                        else{
                            if(StepTiltSle==0){ //On vérifie si le Tilt de la caméra n'est pas déjà sur la position off
                                Serial.print("Tilt Cam 1 is allready on the position off.");
                            }
                //Fin Vérif Cam Pos off

                            else { //La caméra n'est pas sur la position off donc on met la caméra en position
                                Serial.println("Launch 0 pos");
                                //Pano
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
                                //Fin Pano
                                //Tilt
                                    if(StepTiltSle<0){ //Si le tilt est vers le bas
                                        //Serial.println("Tilt on bottom detect");
                                        digitalWrite(DirTiltSle,HIGH);
                                        while (StepTiltSle!=0) { 
                                          //Serial.println("While H Exe");
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
                                          //Serial.println("while B exe");
                                          StepTiltSle = StepTiltSle-1;
                                          digitalWrite(TiltSle, LOW);
                                          delay(speed);
                                          digitalWrite(TiltSle, HIGH);
                                          delay(speed);
                                        }
                                    }
                                //Fin Tilt
                            }
                        
                        }
                    }
                //CSleOff = true;
                Serial.print("Cam ");
                Serial.print(CamSle);
                Serial.println(" ready to be off.");
                Serial.print("C1off = ");
                Serial.println(C1off);
                Serial.print("C2off = ");
                Serial.println(C2off);
                Serial.print("C3off = ");
                Serial.println(C3off);
                Serial.print("C4off = ");
                Serial.println(C4off);
            } while(C1off==0 || C2off==0 || C3off==0 || C4off==0); //Fin While
            Serial.println("Protocol de Mise Hors-Tension Terminée");
            //Cam control
              CamSle = 1; //Variable de la caméra séléctionné
              PanoSle = PanoC1 ; //Variable Pano Cam Séléctionné
              DirPanoSle = DirPanoC1 ; //Variable Direction Pano Cam Séléctionné
              TiltSle = TiltC1 ; //Variable Tilt Cam Séléctionné
              DirTiltSle = DirTiltC1; //Variable Direction Tilt Cam Séléctionné 
              StepPanoSle = StepPanoC1 ; //Variable Step Pano Cam Séléctionné
              StepTiltSle = StepTiltC1 ; //Variable Step Tilt Cam Séléctionné
              Serial.println("Cam 1 select");
            //Fin Cam control
            }
    //Fin Protocole de Mise Hors Tension

} //Fin Loop
