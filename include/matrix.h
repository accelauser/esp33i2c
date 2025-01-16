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
            Serial.printf("   COORDS: %d, %d ;NEIB: %d\n", Y, X, NEIGHBORS);
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
    int ADJACENT_NUM = 0;
    // Long ass line
    int ADJACENT_LIST[9] = {ARR[INDEX_Y-1][INDEX_X-1], ARR[INDEX_Y-1][INDEX_X], ARR[INDEX_Y-1][INDEX_X+1], 
                            ARR[INDEX_Y][INDEX_X-1],            0             , ARR[INDEX_Y][INDEX_X+1],
                            ARR[INDEX_Y+1][INDEX_X-1], ARR[INDEX_Y+1][INDEX_X], ARR[INDEX_Y+1][INDEX_X+1]}; 
    
    for (int NUM = 0; NUM < 9; NUM++){          
        if (ADJACENT_LIST[NUM]){
            ADJACENT_NUM++;
        }
    }
    printArray(ADJACENT_LIST,9);
    return ADJACENT_NUM;
}

// Working function
void povoateMatrix (bool MATRIX[MATRIX_J][MATRIX_K]){
    for (int Y = 1; Y < MATRIX_K-1; Y ++){
        for (int X = 1; X < MATRIX_J-1; X++){
           MATRIX[Y][X] = rand() & 1;// random bool
        }   
    }
}

void makePattern( bool ARR[MATRIX_J][MATRIX_K]){
    int INDEX_X = MATRIX_J /2;
    int INDEX_Y = MATRIX_K /2; 
    ARR[INDEX_Y][INDEX_X-1] = true;
    ARR[INDEX_Y][INDEX_X] = true;
    ARR[INDEX_Y][INDEX_X+1] = true;
}

void liveFill(bool ARR[MATRIX_J][MATRIX_K]){
    for (int Y = 0; Y < MATRIX_K; Y ++){
        for (int X = 0; X < MATRIX_J; X++){
            if ((X == 0 || X == MATRIX_J-1) || (Y == 0 || Y == MATRIX_K-1)){
                MATRIX[Y][X] = false;
            }
            //else if (Y % 2 == 0 && X % 2 == 0){
            else{
                MATRIX[Y][X] = true;
            }
            //}
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