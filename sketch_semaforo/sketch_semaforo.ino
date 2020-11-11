/*
Projeto Semaforo
*/

void setup() {
    pinMode(9, OUTPUT);   //Verde Pedestre
    pinMode(10, OUTPUT);  //Vermelho Pedestre
    pinMode(11, OUTPUT);  //Vermelho Carros
    pinMode(12, OUTPUT);  //Amarelo Carros
    pinMode(13, OUTPUT);  //Verde Carros
}

void loop() {
    //Aqui vai rodar o seguinte

    //Aqui abre o sinal
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    //Fecha pro Pedestre
    digitalWrite(10, HIGH);
    digitalWrite(9, LOW);
    delay(3000);

    //Aqui fica em Atencao
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    delay(2000);

    //Aqui fecha o sinal
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
    //abre pro Pedestre
    digitalWrite(10, LOW);
    digitalWrite(9, HIGH);
    delay(5000);
    digitalWrite(9, LOW);
    for (size_t i = 0; i < 5; i++) {
        digitalWrite(10, HIGH);
        delay(500);
        digitalWrite(10, LOW);
        delay(500);
    }
}
