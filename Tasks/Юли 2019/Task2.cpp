#include <iostream>

class Base {
public:
    static Base &getInstance() {
        static Base instance;
        return instance;
    }

private:
    Base() {}

    Base(const Base &);

    Base &operator=(const Base &);
};

//няма да можем да създаваме инстанция тъй като няма public конструктор
class Derived : public Base
{
};


int main() {
    Base &b1 = Base::getInstance();
    Base &b2 = Base::getInstance();
    // prints 1
    std::cout << (&b1 == &b2);
    return 0;
}
