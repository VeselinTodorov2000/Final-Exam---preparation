#include <iostream>
using std::cout;
class test {
    public:
    int var;
    test() { cout << "test()\n"; var = 0; }
    test &operator=(const test &other) {
        if (this != &other) {
            cout << "copy\n";
            var = other.var;
        } else {
            cout << "self-assignment\n";
        }
        return *this;
    }
    static test &instance() {
    static test obj;
    return obj;
}

test &self() { return *this; }
    void _oncreate() { cout << "_oncreate()\n"; }
    void _oncopy() { cout << "_oncopy()\n"; }
};

int main() {
    test &r1 = test::instance(); // 1
    test &r2 = test::instance(); // 2
    r1.var = 10; //3
    cout << r2.var << "\n"; // 4
    r1.self() = r2; // 5
    new test[3]; // 6
}