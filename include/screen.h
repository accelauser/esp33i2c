#include <stdbool.h>
#include <Adafruit_SSD1306.h>
#include <define.h>

// Dumps the core, shit 
void displayMatrix(int matrix[MATRIX_i][MATRIX_j], Adafruit_SSD1306 display){
    display.clearDisplay();
    for (int i = 1; i < MATRIX_i-1; i++){
        for (int j = 1; j < MATRIX_j-1; j++){
            display.drawPixel(j,i, matrix[i][j]);
        }   
    }
    display.display();
}

void printMatrix(int MATRIX[ MATRIX_i][MATRIX_j]){
    Serial.printf("\n");
    for (int i = 0; i < MATRIX_i; i++){
        for (int j = 0; j < MATRIX_j; j++){
            Serial.printf("%d", MATRIX[i][j]);
       }
        Serial.printf("\n");
    }
}

void printArray(bool* ARR, int arrSize){
    for (int i = 0;i < arrSize; i++ ){
        Serial.printf("%d" , ARR[i]);
    }
}