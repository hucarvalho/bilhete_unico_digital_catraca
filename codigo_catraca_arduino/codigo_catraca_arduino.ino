#include <SoftwareSerial.h>
int num = 0;  //Setando Pino A0



SoftwareSerial mySerial(2, 3);  // RX, TX
char i = '0';
char a[15] = { '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' };

int k = 0;
int leu = 0; 

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  Serial.begin(9600);
  while (!Serial)
    ;
  mySerial.begin(9600);

  // digitalWrite(10, HIGH);  // fechando o motor com leitor
  // digitalWrite(11, HIGH);  //fechando o outro motor sem leitor
  // // //delay de 4 segundos
  // delay(4000);
  // // // Serial.println("a");
  // digitalWrite(10, LOW);  //parando os dois motores
  // digitalWrite(11, LOW);

  
  // digitalWrite(7, HIGH);   // fechando o motor com leitor
  // digitalWrite(12, HIGH);  //fechando o outro motor sem leitor
  // //delay de 4 segundos
  // delay(4000);
  // // Serial.println("a");
  // digitalWrite(7, LOW);  //parando os dois motores
  // digitalWrite(12, LOW);
}

void loop() {

  //marcelo alterar aqui
  //11 e 12 coluna com leitor

  //10 e 7 coluna com leitor

  // digitalWrite(10, HIGH); // fechando o motor com leitor
  // digitalWrite(12, HIGH); //fechando o outro motor sem leitor
  // //delay de 4 segundos
  // delay(4000);
  // // Serial.println("a");
  // digitalWrite(10, LOW); //parando os dois motores
  // digitalWrite(12, LOW);
  // delay(6000);
  // //dando um delay de 6 segundos, que seria pra pessoa passar

  // digitalWrite(7,HIGH); //abrindo o motor com leitor
  // digitalWrite(11, HIGH); //abrindo o motor sem leitor
  // delay(2500); // delay de 2 segundos e meio para
  // digitalWrite(7, LOW); //desligando o motor com o leitor
  // digitalWrite(11, LOW); //desligando o motor sem o leitor

  //   digitalWrite(7, HIGH); // fechando o motor com leitor
  // digitalWrite(12, HIGH); //fechando o outro motor sem leitor
  // //delay de 4 segundos
  // delay(4000);
  // // Serial.println("a");
  // digitalWrite(7, LOW); //parando os dois motores
  // digitalWrite(12, LOW);
  // delay(6000);
  // //dando um delay de 6 segundos, que seria pra pessoa passar

  // digitalWrite(10,HIGH); //abrindo o motor com leitor
  // digitalWrite(11, HIGH); //abrindo o motor sem leitor
  // delay(2500); // delay de 2 segundos e meio para
  // digitalWrite(10, LOW); //desligando o motor com o leitor
  // digitalWrite(11, LOW); //desligando o motor sem o leitor

  // digitalWrite(7, HIGH);
  // digitalWrite(11, HIGH);
  // delay(2000);
  // Serial.println("a");
  // digitalWrite(7, LOW);
  // digitalWrite(11, LOW);
  // delay(3000);

  // digitalWrite(10,HIGH);
  // digitalWrite(12, HIGH);
  // delay(2000);
  // digitalWrite(10, LOW);
  // digitalWrite(12, LOW);

  // digitalWrite(7,LOW);
  //  digitalWrite(10, 0);
  //   delay(10000);

  // Serial.println(k);
  if (k < 1) {
    digitalWrite(8, 0);
    delay(2000);
    // delay(100);
    digitalWrite(8, 1);
    // // digitalWrite(0, 0);
    delay(50);
  } else {
    // Serial.println("aa");
  }


  if (mySerial.available()) {

    i = mySerial.read();
    //Serial.print(i);
    a[k] = i;


    k = k + 1;

    if (k == 7) {
      // leu = 1;
      Serial.print(a[0]);
      Serial.print(a[1]);
      Serial.print(a[2]);
      Serial.print(a[3]);
      Serial.println(a[4]);



      k = 20;
      leu = 9;
    }
  }


  if (k == 20) {



    num = Serial.parseInt();  // letra t
                              // Serial.print("Num ");
                              // Serial.println(k);
                              // Serial.println(k);
    // Lento o pino A0, aqui estamos obtendo o valor
    if (num == 1) {
      Serial.println("DIFERENTE");
      Serial.println(num);
      // digitalWrite(LED_BUILTIN, HIGH);
      // delay(1000);
      // digitalWrite(LED_BUILTIN, LOW);
      // delay(1000);
      // digitalWrite(9, HIGH);
      // delay(5000);

digitalWrite(10, HIGH);  // fechando o motor com leitor
  digitalWrite(11, HIGH);  //fechando o outro motor sem leitor
  // //delay de 4 segundos
  delay(3000);
  // // Serial.println("a");
  digitalWrite(10, LOW);  //parando os dois motores
  digitalWrite(11, LOW);

  delay(4000);
  digitalWrite(7, HIGH);   // fechando o motor com leitor
  digitalWrite(12, HIGH);  //fechando o outro motor sem leitor
  //delay de 4 segundos
  delay(3000);
  // Serial.println("a");
  digitalWrite(7, LOW);  //parando os dois motores
  digitalWrite(12, LOW);

      k = 0;
      leu = 7;

    } else if (num == 2) {
      // digitalWrite(8,HIGH);
      delay(3000);
      digitalWrite(8, LOW);
      Serial.println("Foda");
      k = 0;
      leu = 9;
    }
  }
  //  digitalWrite(8,1);
  //  delay(50);
}
