void setup() {
    pinMode(9, INPUT);  //Recebe um valor de energia e converta a valor logico
    pinMode(11, INPUT);
    pinMode(10, OUTPUT);
    pinMode(12, OUTPUT);  //Emite energia
}

void loop() {
    //Se o pino 9 estiver com energia fluindo por apertar o botao
    //Ativa o pino 12 do LED
    if (digitalRead(9) == LOW) {
        digitalWrite(10, HIGH);
    } else {
        digitalWrite(10, LOW);
    }

    if (digitalRead(11) == HIGH) {
        digitalWrite(12, HIGH);
    }
    //Se nao estivermos apertando o botao a leitura dara LOW e
    //Apaga o LED ou o Mantem apagado
    else {
        digitalWrite(12, LOW);
    }
}