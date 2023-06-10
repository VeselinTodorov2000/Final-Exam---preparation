#include <iostream>

class Counter {
private:
    static int createdObjects;
public:
    Counter() {
        createdObjects++;
    }

    ~Counter() {
        createdObjects--;
    }

    Counter(const Counter &other) {
        createdObjects++;
    }

    Counter &operator=(const Counter &other) {
        return *this;
    }

    static int GetObjCount() {
        return createdObjects;
    }
};

int main() { // До всеки ред е указано какво ще се изведе
    std::cout << Counter::GetObjCount(); //0
    Counter *p = new Counter[10];
    std::cout << Counter::GetObjCount(); //10
    delete[] p;
    std::cout << Counter::GetObjCount(); //0
    Counter a, b;
    Counter c = a;
    a = b;
    std::cout << Counter::GetObjCount(); //3
    return 0;
}
