#include <stdbool.h>
#include <Arduino.h>

// +2 to dodge boundaries limits 
#define MATRIX_J (3 +2)
#define MATRIX_K (3 +2)

bool MATRIX[MATRIX_K][MATRIX_J];

// Func prototypes
int checkAdjacent (bool ARR[MATRIX_J][MATRIX_K],int INDEX_X, int INDEX_Y);
void povoateMatrix (bool MATRIX[MATRIX_J][MATRIX_K]);
void printArray( int* ARRAY, int ARRAY_LEN);

void checkRules (bool ARR[MATRIX_J][MATRIX_K]){
    for (int Y = 1; Y < MATRIX_K-1; Y ++){
        for (int X = 1; X < MATRIX_J-1; X++){
            int NEIGHBORS = checkAdjacent(ARR, X, Y);
            Serial.printf("COORDS: %d, %d  NEIB: %d\n", Y, X, NEIGHBORS);
            switch (NEIGHBORS){
            // Underpopulation
            case 0:
                ARR[Y][X] = false;
                break;
            case 1:
                ARR[Y][X] = false;
                break;
            // Good amount 
            case 2:
                ARR[Y][X] = true;
                break;
            case 3:
                ARR[Y][X] = true;
                break;
            // Overpopulation   
            default:
                ARR[Y][X] = false;
                break;
            }
        }
        Serial.printf("\n");
    }
    Serial.printf("---------------------\n");
}

// Try https://pastebin.com/A8h8D6eE
int checkAdjacent (bool ARR[MATRIX_J][MATRIX_K],int INDEX_X, int INDEX_Y){
    int trueCount = 0;

    // Iterate through the 3x3 grid centered on (INDEX_X, INDEX_Y)
    for (int offsetY = -1; offsetY <= 1; offsetY++) {
        for (int offsetX = -1; offsetX <= 1; offsetX++) {
            // Skip the center cell itself
            if (offsetX == 0 && offsetY == 0) {
                continue;
            }

            // Count the neighbor
            trueCount += ARR[INDEX_Y + offsetY][INDEX_X + offsetX];
        }
    }
    return trueCount;
}

//Povoate the matrix with random booleans 
void povoateMatrix (bool MATRIX[MATRIX_J][MATRIX_K]){
    for (int Y = 1; Y < MATRIX_K-1; Y ++){
        for (int X = 1; X < MATRIX_J-1; X++){
           MATRIX[Y][X] = rand() & 1;// random bool
        }   
    }
}

//Fills the matrix with live cells 
void liveFill(bool ARR[MATRIX_J][MATRIX_K]){
    for (int Y = 0; Y < MATRIX_K; Y ++){
        for (int X = 0; X < MATRIX_J; X++){
            //Checks if coordinate is outside of usable array
            if ((X == 0 || X == MATRIX_J-1) || (Y == 0 || Y == MATRIX_K-1)){
                MATRIX[Y][X] = 0;
            }
            else{
                MATRIX[Y][X] = 1;
            }
        }
    }
}


// Fuction not working, loop works outside function
void matrixDisplay( bool MATRIX[MATRIX_J][MATRIX_K],Adafruit_SSD1306 i2cDisplay){
    for (int Y = 1; Y < MATRIX_K-1; Y ++){
        for (int X = 1; X < MATRIX_J-1; X++){
      i2cDisplay.drawPixel(X,Y,MATRIX[Y][X]); 
    }
  }
}

// Debugging 
void printArray( int* ARRAY, int ARRAY_LEN){
    for (int X = 0; X < ARRAY_LEN; X ++){
        Serial.printf("%d", ARRAY[X]);
    //Serial.printf("\n-----------------------\n");
    }
}

// Debugging 
void printMatrix (bool MATRIX[MATRIX_J][MATRIX_K]){
    for (int Y = 1; Y < MATRIX_K-1; Y ++){
        for (int X = 1; X < MATRIX_J-1; X++){
            Serial.printf("%d", MATRIX[Y][X]);
            }
        Serial.printf("\n");
        }
    Serial.printf("-----------------------\n");  
}