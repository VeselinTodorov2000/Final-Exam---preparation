#include <iostream> 
#include <cstring>

const char* findManager(const char* employee, const char* leaders[][2], size_t n) {
    if(strcmp(leaders[0][0],employee) == 0) {
        return leaders[0][1];
    }
    return findManager(employee, leaders+1, n-1);
}

bool is_subordinate (const char* employee, const char* manager, const char* leaders[][2], size_t n) {
    if(!manager) {
        return true;
    } 
    if(findManager(employee, leaders, n) == nullptr) {
        return false;
    }
    if(strcmp(findManager(employee, leaders, n),manager)==0) {
        return true;
    }
    return is_subordinate(findManager(employee, leaders, n), manager, leaders, n);
}

int main() {
    const char* leaders[][2] = {{"A", "B"}, {"B", "C"}, {"C", "D"}, {"D", nullptr}};
    std::cout << is_subordinate("C", "B", leaders, 4);
}