int frequencia = 2000;      //frequencia inicial
const int pinoBuzzer = 10;  // Numero do Pino do Buzzer
const int pinoBotao1 = 9;   // Numero do Pino do Botao 1
const int pinoBotao2 = 11;  // Numero do Pino do Botao 2

void setup() {
    pinMode(pinoBuzzer, OUTPUT);        //Setta o pino do buzzer como saida
    pinMode(pinoBotao1, INPUT_PULLUP);  // Setta o pino do botao 1 como entrada
    pinMode(pinoBotao2, INPUT_PULLUP);  //Setta o pino do botao 2 como entrada
}

void loop() {
    //Se pessionar o botao o que causa a falta de sinal acrescenta 100 a frequencia
    if (digitalRead(pinoBotao1) == LOW) {
        frequencia = frequencia + 100;
    }
    //Subtrai 100 da frequencia quando pressionado
    if (digitalRead(pinoBotao2) == LOW) {
        frequencia = frequencia - 100;
    }

    tone(pinoBuzzer, frequencia);  //Gera uma frequencia no pino 10 do valor da variavel
    delay(1000);
    noTone(pinoBuzzer);  //Para a frequencia.
    delay(1000);
}