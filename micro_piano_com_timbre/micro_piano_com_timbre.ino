const int pinoPotenciometro = A0;  // pino onde o potenciometro está conectado
int leitura = 0;                   // variável para armazenar o valor lido pelo ADC
float tensao = 0.0;                // variável para armazenar a tensão
int frequencia = 0;
int botao1 = 9;
int botao2 = 10;
int botao3 = 11;
int botao4 = 12;
int buzzer = 13;
float D = 18.35;
float E = 20.60;
float G = 24.50;
float A = 27.50;

void setup() {
    // Inicia e configura a Serial
    Serial.begin(9600);  // 9600 bps

    // configura o pino com potenciometro como entrada
    pinMode(pinoPotenciometro, INPUT);  // pino A0
    pinMode(botao1, INPUT_PULLUP);
    pinMode(botao2, INPUT_PULLUP);
    pinMode(botao3, INPUT_PULLUP);
    pinMode(botao4, INPUT_PULLUP);
    pinMode(buzzer, OUTPUT);
}

void loop() {
    // le o valor de tensão no pino do potenciometro
    leitura = analogRead(pinoPotenciometro);

    // converte e imprime o valor em tensão elétrica
    tensao = leitura * 8.0 / 1024.0;

    // imprime valor no plotter serial
    Serial.println(ceil(tensao));
    Serial.println("inicio: "+ frequencia);

    if (ceil(tensao) < 1) {
        if (digitalRead(botao1) == LOW) {
            frequencia += D;
        }
        if (digitalRead(botao2) == LOW) {
            frequencia += E;
        }
        if (digitalRead(botao3) == LOW) {
            frequencia += G;
        }
        if (digitalRead(botao4) == LOW) {
            frequencia += A;
        }
    } else if (ceil(tensao) >= 1) {
        if (digitalRead(botao1) == LOW) {
            frequencia += D * ceil(tensao);
        }
        if (digitalRead(botao2) == LOW) {
            frequencia += E * ceil(tensao);
        }
        if (digitalRead(botao3) == LOW) {
            frequencia += G * ceil(tensao);
        }
        if (digitalRead(botao4) == LOW) {
            frequencia += A * ceil(tensao);
        }
    }
    tone(buzzer, frequencia);
    frequencia = 0;
    delayMicroseconds(200);
    // aguarda 100 milissegundos para uma nova leitura
    //Re Mi Sol la
    //D, E, G, A
}
