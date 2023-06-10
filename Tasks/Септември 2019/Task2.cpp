class Base {
public:
    Base() { std::cout << "Base::Base\n"; }
    ~Base() { std::cout << "Base::~Base\n"; }
    virtual void f() { std::cout << "Base::f\n"; }
};
class Derived : public Base {
public:
    Derived() { std::cout << "Derived::Derived\n"; }
    ~Derived() { std::cout << "Derived::~Derived\n"; }
    virtual void f() { std::cout << "Derived::f\n"; }
};

int main() {
// 1: Base *p = new Derived();
    Base::Base
    Derived::Derived
// 2: p->f();
    Derived::f
// 3: delete p;
    Derived:~Derived
    Base::~Base
// 4: Derived d;
Base::Base
Derived::Derived
// 5: Base b = d;
nothing
// 6: b.f();
    Base::f
// 7: } // излизане от main
Base::~Base
Derived::~Derived
Base::~Base


//Б)
Base *arr = new Base[3];
Създава се динамичен масив с 3 елемента от тип Base, като всеки елемент се инициализира отделно
и ще се извика 3 пъти конструктора по подразбиране
Base::Base
Base::Base
Base::Base

delete[] arr;
Изтрива се динамичния масив, като всеки елемент вика деструктора
Base::~Base
Base::~Base
Base::~Base

