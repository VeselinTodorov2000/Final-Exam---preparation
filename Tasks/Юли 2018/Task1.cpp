#include <iostream>

unsigned revertNumber(unsigned number) {
    unsigned result = 0;
    while (number != 0) {
        result *= 10;
        result += number % 10;
        number /= 10;
    }
    return result;
}

bool compareNumbers(unsigned a, unsigned b) {
    if(a < 10 || b < 10) {
        return a%10 < b%10;
    }
    if(b % 10 < a % 10) {
        return false;
    }
    else if(b % 10 == a % 10) {
        return compareNumbers(a/10, b/10);
    } else {
        return true;
    }
}

void sortLex(unsigned a[], int n) {
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n - i + 1; ++j) {
            if(!compareNumbers(revertNumber(a[j]), revertNumber(a[j+1]))) {
                std::cout << "swapping " << a[j] << " " << a[j+1] << std::endl;
                unsigned temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int main() {
    unsigned arr[6] = {13, 14, 7, 2018, 9, 0};
    sortLex(arr, 6);

    for (int i = 0; i < 6; ++i) {
        std::cout << arr[i] << " ";
    }
}
