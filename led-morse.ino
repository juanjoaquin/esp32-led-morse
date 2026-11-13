const int PIN_LED = 2;

const int PUNTO = 200;            // duración de un punto (ms)
const int RAYA  = PUNTO * 3;      // una raya dura 3 puntos
const int ENTRE_SIMBOLOS = PUNTO; // pausa entre destellos
const int ENTRE_LETRAS   = PUNTO * 3;
const int ENTRE_PALABRAS = PUNTO * 7;

void destello(int duracion) {
  digitalWrite(PIN_LED, HIGH);
  delay(duracion);
  digitalWrite(PIN_LED, LOW);
  delay(ENTRE_SIMBOLOS);
}

void letraS() {
  for (int i = 0; i < 3; i++) destello(PUNTO);
}

void letraO() {
  for (int i = 0; i < 3; i++) destello(RAYA);
}

void setup() {
  Serial.begin(115200);
  pinMode(PIN_LED, OUTPUT);
  Serial.println("\n=== SOS en morse ===");
}

void loop() {
  Serial.println("S");
  letraS();
  delay(ENTRE_LETRAS);

  Serial.println("O");
  letraO();
  delay(ENTRE_LETRAS);

  Serial.println("S");
  letraS();

  Serial.println("--- pausa ---");
  delay(ENTRE_PALABRAS);
}