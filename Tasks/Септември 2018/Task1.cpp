#include <iostream>
#include <cstring>

void printBook(char string[100]) {
    int numberOfSymbols = strlen(string);
    int currentWordSize = 0;
    for (int i = 0; i < numberOfSymbols; ++i) {
        if(string[i] == ' ') {
            std::cout << currentWordSize << ' ';
            currentWordSize = 0;
        } else {
            currentWordSize++;
        }
    }
    std::cout << currentWordSize << ' ';
}

bool isRowSorted(char (*a)[3][100], int rowNumber, int numberOfBooks) {
    for (int i = 0; i < numberOfBooks - 1; i++) {
        if (strcmp(a[rowNumber][i], a[rowNumber][i + 1]) > 0) {
            return false;
        }
    }
    return true;
}

void revealPassword(char (*a)[3][100], int m, int n) {
    for (int i = 0; i < m; i++) {
        if (isRowSorted(a, i, n)) { //проверка дали книгите на реда са подредени по азбучен ред
            printBook(a[i][n/2]);
        }
    }
}

int main() {
    char library[3][3][100] = {{"Algebra",  "Analitic geometry", "DIS"},
               {"C",        "A",                 "B"},
               {"Database", "Intelligence",      "Reactive programming"}};

    revealPassword(library, 3, 3);
}
