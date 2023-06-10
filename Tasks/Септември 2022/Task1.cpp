/*
1) Нека е дефиниран масивът
int arr[] = { 1, 2, 3 };
Срещу всеки от изразите да се посочи каква ще
бъде неговата оценка.
a)arr[1] == *(arr+2) _________________
b)arr == &arr[0] _________________
c)(arr+1) == &arr[1] _________________
d)*arr == arr[0] _________________ */

int arr[] = {1, 2, 3};

arr[1] == *(arr+2); // arr[1] = 2   *(arr+2) = 3 => 2 == 3 => false
arr == &arr[0] // arr = &arr[0] => true
(arr+1) == &arr[1] // arr+1 => &arr[1] => true
*arr == arr[0] // *(&arr[0]) => arr[0] => true

/*
2) void mystery(const char* str)
{
    while (*str && *(str+1)) {
    std::cout << *str;
    str += 2;
    }
}

mystery("abcdef")
*/

while(*str && *(str+1)) //str[0] != 0 && str[1] != 0
//'a' != 0 && 'b' != 0
'a'
//'c' != 0 && 'd' != 0
'c'
//'e' != 0 && 'f' != 0
'e'
//0 != 0 && ...
"ace"


/*
3) Нека са дадени следните дефиниции:
char s1[] = "Hello";
char s2[] = "world!";
char result[80];
Да се довърши програмният фрагмент, така че
след изпълнението му в result да се съхрани
коректното представяне на низа "Hello world!".
На празните места трябва да се попълнят именaта на подходящи стандартни функции за работа
с низове.
__________________(result, s1);
__________________(result, " ");
__________________(result, s2);
*/
"Hello" "World" => "Hello World" <- result //празна
strcpy(result, s1) //result = "Hello"
strcat(result, " ") //result = "Hello "
strcat(result, s2) //result = "Hello World"

/*
4) Да се довърши кодът на рекурсивните функции, така че f да проверява дали символният низ,
сочен от word, се съдържа като подниз в text. За
определеност считаме, че празният низ се съдържа във всеки друг

bool g(const char* text, const char* word)
{
if (!*word) return true;
if (!*text) return false;
if (*word != *text) return false;
return g(text+1, word+1);
}

bool f(const char* text, const char* word)
{
if (!*word) return true;
if (!*text) return false;
return g(text, word) ||
f(text+1, word);
}
*/


// char arr[3][3] = { ’a’, ’b’, ’c’,
//                    ’d’, ’e’, ’f’,
//                    ’g’, ’h’, ’i’ };
// for (int i = 0; i < 3; ++i)
// std::cout << arr[2-i][i];

arr[2-0][0] => arr[2][0] => 'g'
arr[2-1][1] => arr[1][1] => 'e'
arr[2-2][2] => arr[0][2] => 'c'
"gec"

// double var = 5 / 2;
// std::cout << var;
5 / 2 => (int) 2.5 => 2
double var = 2
2, 2.0  


