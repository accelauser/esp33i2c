#include <stdbool.h>

#define MATRIX_J 32
#define MATRIX_K 32

int MATRIX[MATRIX_J][MATRIX_K];
//bool MATRIX[MATRIX_J][MATRIX_K];

int checkAdjacent (int ARR[MATRIX_J][MATRIX_K],int INDEX_X, int INDEX_Y);
void povoateMatrix (int MATRIX[MATRIX_J][MATRIX_K]);

int checkRules (int ARR[MATRIX_J][MATRIX_K]){
    for (int X = 0; X < MATRIX_J; X ++){
        for (int Y = 0; Y < MATRIX_K; Y++){
            int NEIGHBORS = checkAdjacent(ARR, X, Y);
            //Serial.printf("%d", NEIGHBORS);
            switch (NEIGHBORS){
            // Underpopulation
            case 0:
                ARR[X][Y] = 0;
                break;
            case 1:
                ARR[X][Y] = 0;
                break;
            // Good amount 
            case 2:
                ARR[X][Y] = 1;
                break;
            case 3:
                ARR[X][Y] = 1;
                break;
            // Overpopulation
            default:
                ARR[X][Y] = 0;
                break;
            }
        }
    }
    //Serial.printf("---------------------\n");
    return 0;
}

// Working funcion
int checkAdjacent (int ARR[MATRIX_J][MATRIX_K],int INDEX_X, int INDEX_Y){
    int ADJACENT_NUM = 0;
    // Long ass line
    int ADJACENT_LIST[9] = {ARR[INDEX_X-1][INDEX_Y-1], ARR[INDEX_X][INDEX_Y-1], ARR[INDEX_X+1][INDEX_Y-1], 
                            ARR[INDEX_X-1][INDEX_Y],            0             , ARR[INDEX_X+1][INDEX_Y],
                            ARR[INDEX_X-1][INDEX_Y+1], ARR[INDEX_X][INDEX_Y+1], ARR[INDEX_X+1][INDEX_Y+1]}; 
    for (int NUM = 0; NUM < 9; NUM++){
        /*if (ADJACENT_LIST[NUM]){
            ADJACENT_NUM++;
        }*/
        ADJACENT_NUM += ADJACENT_LIST[NUM];
    }
    return ADJACENT_NUM;
}

// Working function
void povoateMatrix (int MATRIX[MATRIX_J][MATRIX_K]){
    for (int X = 0; X < MATRIX_J; X ++){
        for (int Y = 0; Y < MATRIX_K; Y++){
           MATRIX[X][Y] = rand() & 1;
        }   
    }
}

void makePattern( int ARR[MATRIX_J][MATRIX_K]){
    int INDEX_X = MATRIX_J /2;
    int INDEX_Y = MATRIX_K /2; 
    int PATTERN[9] = {
    ARR[INDEX_X-1][INDEX_Y-1], ARR[INDEX_X][INDEX_Y-1], ARR[INDEX_X+1][INDEX_Y-1], 
    ARR[INDEX_X-1][INDEX_Y],            0             , ARR[INDEX_X+1][INDEX_Y],
    ARR[INDEX_X-1][INDEX_Y+1], ARR[INDEX_X][INDEX_Y+1], ARR[INDEX_X+1][INDEX_Y+1]
    };
    ARR[INDEX_X][INDEX_Y-1] = 1;
    ARR[INDEX_X][INDEX_Y] = 1;
    ARR[INDEX_X][INDEX_Y+1] = 1;
}

// Fuction not working, loop works outside function
void matrixDisplay( int MATRIX[MATRIX_J][MATRIX_K],Adafruit_SSD1306 i2cDisplay){
  for (int X = 0; X < MATRIX_J; X ++){
    for (int Y = 0; Y < MATRIX_K; Y++){
      i2cDisplay.drawPixel(X,Y,MATRIX[X][Y]);
    }
  }
}

int printArray (int MATRIX[MATRIX_J][MATRIX_K]){
    for (int X = 0; X < MATRIX_J; X ++){
        for (int Y = 0; Y < MATRIX_K; Y++){
            Serial.printf("%d", MATRIX[X][Y]);
        }
        Serial.printf("\n");
    }
    Serial.printf("-----------------------\n");
    return 0;
}   

