// class foo {
// public:
// virtual void f() {};
// void g() {};
// };

// Срещу всеки от редовете, които извикват f или
// g, да се запише “статично” или “динамично” според вида свързване, който ще се използва за тях.
// foo obj;
// foo& ref = obj;
// obj.f(); статично
// obj.g(); статично
// ref.f(); динамично
// ref.g(); статично

// 3) Нека са дадени следните дефиниции:
// class base {
// public: int a;
// private: int b;
// };
// class derived : protected base { };
// Да се посочи каква ще бъде видимостта на променливите a и b в класа derived – public,
// protected или private.

// : public -> public: public, protected: protected, private: private
// : protected -> public: protected, protected: protected, private: private
// : private -> public: private, protected: private, private: private

// Видимост на а -> protected
// Видимост на b -> private

/*
5) Нека е дадена следната дефиниция:
struct s {
public:
static int var;
s() { var = 5; }
};

int s::var = 0;

Да се посочи какво ще изведе следният фрагмент:
std::cout << ’(’ << s::var << ’)’;
s obj1;
obj1.var = 10;
s obj2;
std::cout << ’-’ << s::var << ’-’;
*/
"(0)"
//s obj1 => s() -> var = 5
// var = 10
//s obj2 => s() -> var = 5
"-5-" 
=> "(0)-5-"