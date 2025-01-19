#include <stdbool.h>
#include <Adafruit_SSD1306.h>
#include <define.h>

int displayMatrix(bool matrix[MATRIX_i][MATRIX_j], Adafruit_SSD1306 display){
    display.clearDisplay();
    for (int i = 1; i < MATRIX_i-1; i++){
        for (int j = 1; j < MATRIX_j-1; j++){
            display.drawPixel(j,i, matrix[i][j]);
        }   
    }
    display.display();
    return 1;
}

void printMatrix(bool MATRIX[ MATRIX_i][MATRIX_j]){
    Serial.printf("\n");
    for (int i = 1; i < MATRIX_i-1; i++){
        for (int j = 1; j < MATRIX_j-1; j++){
            Serial.printf("%d", MATRIX[i][j]);
       }
        Serial.printf("\n");
    }
}