// Pines
#define PULSADOR 10

// Array multidimensional para mostrar los números
byte numero[10][8] =
{   
  { 1, 1, 1, 1, 1, 1, 1, 0 }, // 0
  { 0, 0, 0, 0, 1, 1, 1, 0 }, // 1
  { 1, 1, 0, 1, 1, 0, 1, 1 }, // 2
  { 1, 0, 0, 1, 1, 1, 0, 1 }, // 3
  { 0, 0, 1, 0, 1, 1, 0, 1 }, // 4
  { 1, 0, 1, 1, 0, 1, 1, 1 }, // 5
  { 1, 1, 1, 1, 0, 1, 1, 1 }, // 6
  { 0, 0, 0, 1, 1, 1, 0, 0 }, // 7
  { 1, 1, 1, 1, 1, 1, 0, 1 }, // 8
  { 0, 0, 1, 1, 1, 1, 0, 1 } // 9
};

void setup (){
  //Monitor serie
  Serial.begin(9600);

  // Pines modo salida
  for (int i=2;i<10;i++){
    pinMode (i,OUTPUT);
  }

  //Pin PULSADOR modo entrada
  pinMode (PULSADOR,INPUT);

  //Establecemos la semilla en un pin analogico. Es para que no se repita siempre la misma secuencia de números ramdom.
  randomSeed(analogRead(A0));
}

void loop() {
  // Leemos el valor del pulsador
  int valor = digitalRead(PULSADOR);

  // Si está pulsado
  if (valor == HIGH){
        //Genera un numero aleatorio entre 1 y 9
    int randomNumber = random(1,9);

    // Ponemos los pines en estado correcto para mostrar el número randomNumber
    for (int e = 0; e < 8; e++)
    {
      digitalWrite(e+2, numero[randomNumber][e]);
    }

    delay(100);
  }

  }
