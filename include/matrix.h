#include <stdbool.h> 
#include <define.h>

void initializeMatrix(int MATRIX[ MATRIX_i][MATRIX_j]) {
    for (int i = 0; i < MATRIX_i; i++) {
        for (int j = 0; j < MATRIX_j; j++) {
            MATRIX[i][j] = false; // Or Dead
        }
    }
}

void liveMatrix(int MATRIX[ MATRIX_i][MATRIX_j]){
    for (int i = 0; i < MATRIX_i; i++){
        for (int j = 0; j < MATRIX_j; j++){
            if ((i >= 1 && j >= 1) && (i < MATRIX_i-1 && j < MATRIX_j-1)){
                MATRIX[i][j] = 1;
            }
            else{
                MATRIX[i][j] = 0;
            }
        }
    }
}

int countAlive(int I, int J, int MATRIX[ MATRIX_i][MATRIX_j]){
    Serial.printf("\n\n");
    int aliveCount = 0;
    int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
    
    for (int k = 0; k < 8; k++) {
        int new_x = J + dx[k];
        int new_y = I + dy[k];
        
        // Boundary check
        if (new_x >= 0 && new_x < MATRIX_j && new_y >= 0 && new_y < MATRIX_i) {
            Serial.printf("Checking neighbor (%d, %d): %d\n", new_y, new_x, MATRIX[new_y][new_x]);
            if (MATRIX[new_y][new_x] == 1) {
                aliveCount++;
            }
        }
    }

    Serial.printf("%d,%d, Ngbh: %d", I, J, aliveCount);
    return aliveCount;
}

int gameRules(int neighbors, bool state){
    //int neighbors = countAlive(matrix, )
    if (state){
        if (neighbors == 2 || neighbors == 3){
            return 1;
        }
        else{
            return 0;
        }
    }
    else {
        if (neighbors == 3){
            return 1;
        }
        else{
            return 0;
        }
    }
    return 0;
}