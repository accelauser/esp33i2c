#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include <screen.h> 
#include <matrix.h> 
#include <define.h>


//Creates display instance 
Adafruit_SSD1306 display(DISPLAY_WIDTH, DISPLAY_HEIGHT, &Wire, -1);

int displaySetup(){
  Wire.begin(11,10);
  display.begin(SSD1306_SWITCHCAPVCC, DISPLAY_ADRESS);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.printf("Hello World!"); 
  display.display();
  return 1; 
}

void setup(){
  pinMode(20, OUTPUT);
  digitalWrite(20, LOW);
  Serial.begin(9600);
  displaySetup();
  povoateMatrix();
  printMatrix(MATRIX);
  displayMatrix(MATRIX,display);
  for (int i = 1; i < MATRIX_i-1; i++){
    for (int j = 1; j < MATRIX_j-1; j++){
      //MATRIX[i][j] = gameRules(countAlive(i,j), MATRIX[i][j]);
      bool cell = MATRIX[i][j];
      int neighbors = countAlive(i,j);
      MATRIX[i][j] = gameRules(neighbors, cell); 
    }
  }
  printMatrix(MATRIX);
  //displayMatrix(MATRIX, display);
}


void loop(){
  //displayMatrix(MATRIX, display);
}