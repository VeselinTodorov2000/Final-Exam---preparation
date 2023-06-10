class A {
public:
    A() { cout << "A()\n"; }
    A(A&) { cout << "A(A&)\n"; }
    virtual ~A() { cout << "~A()\n"; }
    A& operator=(A&) {
    cout << "op=(A&)\n";
    return *this;
    }
};

class B : public A {
public:
    B() { cout << "B()\n"; }
    B(B&) { cout << "B(B&)\n"; }
    virtual ~B() { cout << "~B()\n"; }
    B& operator=(B&) {
    cout << "op=(B&)\n";
    return *this;
    }
};

void f(A b) { cout << "f(A)\n"; }

// Evaluate
a) 
B d;
=>
A() 
B()

b)
B copy = d;
A()
B(B&)

c)
A b = d;
A(A&)

d)
A& ref = d;
няма да изведе нищо

f)
B arr[2];
A() 
B()
A() 
B()

g)
f(d);
A(A&)
f(A)
~A()

h)
A* p = new B(d);
A()
B(B&)

i)
delete p;
~B()
~A()

j)
d = d;
oper=(B&)

k)
ref = d;
няма да изведе нищо