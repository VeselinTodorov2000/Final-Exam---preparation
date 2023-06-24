#include <iostream>

bool checkFour(char terrain[4][6], int nrow, int ncol, int row, int col) {

    int timesFour = 0;
    for (int i = row - 1; i <= row + 1; ++i) {
        for (int j = col - 1; j < col + 1; ++j) {
            if (i < nrow && j < ncol && terrain[i][j] == '4') {
                timesFour++;
            }
        }
    }
    return (timesFour >= 4);
}

void grow10Years(char terrain[4][6], int row, int col) {
    for (int i = 0; i <= row; i++) {
        for (int j = 0; j < col; ++j) {
            if (terrain[i][j] == '1' || terrain[i][j] == '2' || terrain[i][j] == '3') {
                terrain[i][j]++;
                continue;
            }
            if (terrain[i][j] == '4' && checkFour(terrain, row, col, i, j)) {
                terrain[i][j] = '3';
            }
        }
    }
}

void grow100Years(char terrain[4][6], int row, int col) {
    for(int i = 0; i < 10; i++) {
        grow10Years(terrain, row, col);
    }
}

char terrain[4][6] = {{'R', 'R', '1', '1', '2', '2'},
                      {'1', 'R', 'R', 'R', '1', '2'},
                      {'S', '1', 'R', 'R', '2', '3'},
                      {'4', '4', 'S', 'S', 'R', 'R'}};

void printTerrain(char terrain[4][6], int row, int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            std::cout << terrain[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}
int main() {
    grow100Years(terrain, 4, 6);
    printTerrain(terrain, 4, 6);
}
