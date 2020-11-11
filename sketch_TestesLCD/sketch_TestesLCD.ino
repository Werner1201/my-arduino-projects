/*******************************************************************************
* Kit Avançado para Arduino v4 - Liquid Crystal Display LCD
* Primeiros passos com um display LCD 16x2.
*******************************************************************************/

#include <LiquidCrystal.h> // inclui a biblioteca para uso do Display LCD
// inicializa um objeto nos pinos para acesso as funções do LCD
const int RS = 13, EN = 12, D4 = 11, D5 = 10, D6 = 9, D7 = 8;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);
int Contrast=0; //Configura o Contraste sem Potenciometro
unsigned int frequencia = 0;
int botao1 = 7;
int botao2 = 6;
int botao3 = 5;
int botao4 = 4;
int buzzer = 3;

float D = 18.35;
float E = 20.60;
float G = 24.50;
float A = 27.50;

void setup(){  
  // Configura o LCD com os número de colunas e linhas
  lcd.begin(16, 2); // 16 colunas e 2 linhas
  
  // Limpa o LCD
  lcd.clear();
  
  // posiciona o cursor do LCD
  lcd.setCursor(0, 0); // (coluna 0, linha 0)
  lcd.print("Nota Pressionada: "); // Imprime mensagem

   pinMode(botao1, INPUT_PULLUP);
   pinMode(botao2, INPUT_PULLUP);
   pinMode(botao3, INPUT_PULLUP);
   pinMode(botao4, INPUT_PULLUP);
   pinMode(buzzer, OUTPUT);
}

void loop(){
  lcd.setCursor(0, 0); // (coluna 0, linha 0)
  lcd.print("Nota Pressionada: ");
   lcd.setCursor(0, 1); 
   if (digitalRead(botao1) == LOW) {
        frequencia += D;
        lcd.print("D(Re) ");
    }
    if (digitalRead(botao2) == LOW) {
        frequencia += E;
        lcd.print("E(Mi) ");
    }
    if (digitalRead(botao3) == LOW) {
        frequencia += G;
        lcd.print("G(Sol) ");
    }
    if (digitalRead(botao4) == LOW) {
        frequencia += A;
        lcd.print("A(La) ");
    }
    lcd.print("               ");
    //lcd.setCursor(0, 1); // (coluna 0, linha 1)
    tone(buzzer, frequencia, 500);
    frequencia = 0;
    delayMicroseconds(200);
   
}
