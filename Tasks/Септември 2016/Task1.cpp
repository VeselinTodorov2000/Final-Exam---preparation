#include<iostream>
#include <cstring>

void findBiggestEqualPositions(const char* string) {
    int n = strlen(string);
    int maxPos1 = 0;
    int maxPos2 = 0;
    int maxPosSize = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = n-1; j > i; j--) {
            if(string[i] == string[j] && j - i > maxPosSize) {
                maxPosSize = j - i;
                maxPos1 = i;
                maxPos2 = j;
            }
        }
    }

    std::cout << maxPos1 << " " << maxPos2;
}

int main()
{
    findBiggestEqualPositions("this is just a simple example");
}