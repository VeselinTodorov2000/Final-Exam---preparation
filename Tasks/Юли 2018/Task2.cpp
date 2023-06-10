#include <iostream>
#include <cassert>
#include <cmath>

template<typename T>
class Polynom {
private:
    T* coefs;
    int power;

public:
    Polynom(T* coefs, int power) {
        this->coefs = coefs;
        this->power = power;
    }

    Polynom operator+(const Polynom& other) {
        Polynom<T> newPolynom(this);
        for (int i = 0; i <= power; i++) {
            newPolynom.coefs[i] += other.coefs[i];
        }
        return newPolynom;
    }

    Polynom operator-(const Polynom& other) {
        Polynom<T> newPolynom(this);
        for (int i = 0; i <= power; i++) {
            newPolynom.coefs[i] -= other.coefs[i];
        }
        return newPolynom;
    }

    Polynom operator*(T& other) {
        for (int i = 0; i <= power; i++) {
            coefs[i] *= other;
        }
    }

    T& operator[](int i) {
        if(i > power) {
            assert(false);
        }
        return coefs[power-i];
    }

    T operator()(T x) {
        T result = 0;
        for (int i = 0; i < power; ++i) {
            result += coefs[i]*pow(x, power-i);
        }
        return result;
    }
};

int main() {
    int a[5] = {1,2,3,4,5};
    Polynom<int> d(a, 5);
    assert(d[2] == 4);
    assert(d(1) == 15);
}