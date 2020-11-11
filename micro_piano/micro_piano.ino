int frequencia = 0;
int botao1 = 9;
int botao2 = 10;
int botao3 = 11;
int buzzer = 12;
float B = 123.74;
float C = 130.81;
float G = 98.00;

void setup() {
    pinMode(botao1, INPUT_PULLUP);
    pinMode(botao2, INPUT_PULLUP);
    pinMode(botao3, INPUT_PULLUP);
    pinMode(buzzer, OUTPUT);
}

void loop() {
    if (digitalRead(botao1) == LOW) {
        frequencia += B;
    }
    if (digitalRead(botao2) == LOW) {
        frequencia += C;
    }
    if (digitalRead(botao3) == LOW) {
        frequencia += G;
    }
    tone(buzzer, frequencia, 500);

    frequencia = 0;
}