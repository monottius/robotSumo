//Declaración de pines a usar

// Pines para controlar la velocidad de los Motores */
int ENA = 5;
int ENB = 6;

/*IN1 E IN2 SON EL LADO DERECHO, IN1 HACIA ATRAS E IN2 HACIA ADELANTE
  IN3 E IN4 SON EL LADO IZQUIERDO, IN3 HACIA ATRAS E IN4 HACIA ADELANTE*/
int IN1 = 7;
int IN2 = 8;
int IN3 = 9;
int IN4 = 10;

// ----------------------------------
int SCentro = 15; // Seguidor de Líneas
int Valor = 0; // Variable global

// Sensor Ultrasonido
const int Echo = 12;
const int Trigger = 13;
long t;
long d;

void setup() {
  // Se prepara la comunicación serial
  Serial.begin(9600);
  //Configurar los pines de entrada y salida
  //Entradas
  pinMode(Echo, INPUT);
  pinMode(SCentro, INPUT);
  //Salidas
  pinMode(Trigger, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

}

void loop()
{
 SensorUltrasonido();
  Valor = analogRead(SCentro);
  if (Valor >= 700) {
    retroceder();
    delay(250);
  }
  if (d < 15) {
    avanzar();
  }

  if (d >= 15 && d < 25) {
    Frenar();
    delay(100);
    Doblar_DER();
    delay(400);
    avanzar();
    delay(200);
  }

  if (d >= 25) {
    Doblar_IZQ();
  }

}



void avanzar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
}
void retroceder()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
}
void Doblar_DER()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 220);
  analogWrite(ENB, 220);
}
void Doblar_IZQ()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 190);
  analogWrite(ENB, 170);
}
void Frenar()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
}
void SensorUltrasonido()
{
  digitalWrite(Trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger, LOW);
  t = pulseIn(Echo, HIGH);
  d = t / 59;
  Serial.print(d);
  Serial.println(" cm");
  delay(200);
}
