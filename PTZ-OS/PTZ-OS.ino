//PTZ CAM V1 - motor mouvement teste + initialize joystick
int tempo=1; // Cette valeur détermine la vitesse du moteur, 1 = rapide, 100 = lent
int axeX = 12; // signal de l'axe X sur entrée A0
int axeY = 14; // signal de l'axe Y sur entrée A1
int BP7 = 27; // Bouton-poussoir en broche 7


void setup() {
    pinMode(4, OUTPUT); // On initialise les broches D4 et D5 en sorties
    pinMode(16, OUTPUT);
    pinMode (axeX, INPUT); // définition de A0 comme une entrée
    pinMode (axeY, INPUT); // définition de A1 comme une entrée
    pinMode (BJ, INPUT); // définition de 7 comme une entrée
    digitalWrite(BJ, HIGH); // Activation de la résistance de Pull-Up interne de la carte Uno
    Serial.begin (9600);

}

void loop() {
    delay(1000);

    digitalWrite(4, HIGH); // On met la broche DIR à l'état haut
    for (int i=0; i <= 200; i++){
        digitalWrite(16, LOW);
        delay(tempo); // On envoie 200 impulsions pour faire tourner le moteur de 200 pas dans un sens
        digitalWrite(16, HIGH); // La valeur de tempo determine le temps entre 2 impulsions en ms
        delay(tempo);
    }

    delay(1000);

    digitalWrite(4, LOW); // On met la broche DIR à l'état bas pour changer de sens
    for (int i=0; i <= 200; i++){
        digitalWrite(16, LOW);
        delay(tempo); // On envoie 200 impulsions pour faire tourner le moteur dans l'autre sens
        digitalWrite(16, HIGH); // La valeur de tempo determine le temps entre 2 impulsions en ms
        delay(tempo);
    }

}