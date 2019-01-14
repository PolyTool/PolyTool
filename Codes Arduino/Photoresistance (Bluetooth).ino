// Code Arduino pour le fonctionnement de la photorésistance avec l'ajout du Bluetooth

#define RX 11
#define TX 12
SoftwareSerial BlueT(RX,TX);

// Variables
int capteur = A0;
String prefixe_son = "*S";
String prefixe_texte = "*L";

String c1 = "Endroit peu éclairé : pensez à allumer une lampe si cela continue";
String c2 = "Endroit sombre : veuillez allumer une lampe pour votre sécurité";

void setup() {
  Serial.begin(9600);
  BlueT.begin(9600); 
}

void loop() {
  int luminosite = analogRead(capteur);
  Serial.println(luminosite);
  if (luminosite>120 && luminosite<=350) {
    Serial.println(c2);
    BlueT.print(prefixe_texte + c1); // Ecriture sur l'appareil connecté en Bluetooth
  }
  if (luminosite>350) {
    Serial.println(c2);
    BlueT.print(prefixe_texte + c2); // Ecriture sur l'appareil connecté en Bluetooth
    if () { // Lorsqu'on est trop longtemps dans cette condition, on alerte l'utilisateur
      BlueT.print("*S");
    }    
  }
  delay(200);
}
