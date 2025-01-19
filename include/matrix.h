#include <stdbool.h> 
#include <define.h>

bool MATRIX[MATRIX_i][MATRIX_j];


void povoateMatrix(){
    for (int i = 1; i < MATRIX_i-1; i++){
        for (int j = 1; j < MATRIX_j-1; j++){
            MATRIX[i][j] = Alive;
        }
    }
}

int countAlive( int I, int J ){
    int aliveCount = 0;
    int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
    
    for (int k = 0; k < 8; k++) {
        int new_x = J + dx[k];
        int new_y = I + dy[k];
        if (MATRIX[new_y][new_x]){
            aliveCount ++;
        }
    }
    Serial.printf("\n%d,%d, Ngbh: %d", I, J, aliveCount);
    return aliveCount;
}

int gameRules(int neighbors, bool state){
    //int neighbors = countAlive(matrix, )
    switch (state)
    {
    case 0 :
        if (neighbors == 3){
            return 1;
        }
        break;
    
    case 1:
        if (neighbors < 2){
            return 0;
        }
        else if (neighbors == 2 || neighbors == 3){
            return 1;
        }
        else if (neighbors > 3 ){
            return 0;
        } 
        break;
    }
    return 0;
}


