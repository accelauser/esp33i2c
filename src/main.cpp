#include <Arduino.h> 
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <stdlib.h>
#include <stdbool.h>
#include <matrix.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
//bool (*MATRIXPRT)[MATRIX_K] = MATRIX;
//https://stackoverflow.com/questions/1052818/create-a-pointer-to-two-dimensional-array
//bool (*MATRIXPRT)[MATRIX_K];
//MATRIXPRT= (bool(*)[MATRIX_K]) malloc((MATRIX_J*MATRIX_K) * sizeof(bool));

void setup(){
  pinMode(20, OUTPUT);
  digitalWrite(20, LOW);
  Wire.begin(11,10);
  Serial.begin(9600);

  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.printf("Conway's Game of Life");
  display.display();
  delay(500);

  Serial.printf("\nlol\n");

  liveFill(MATRIX);
  printMatrix(MATRIX);
  display.clearDisplay();
  matrixDisplay(MATRIX, display);//Works here not in loop
  display.display();
  checkRules(MATRIX);
  printMatrix(MATRIX);
}


void loop(){
  /*
  checkRules(MATRIX);
  printArray(MATRIX);
  display.clearDisplay();
  for (int X = 0; X < MATRIX_J; X ++){
    for (int Y = 0; Y < MATRIX_K; Y++){
      display.drawPixel(X,Y,MATRIX[X][Y]);
    }
  }
  display.display();
  */
}