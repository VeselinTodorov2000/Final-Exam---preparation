a)
int calc(int a[5])
{
    int sum = 8;
    for (int i = 0; a[i]; ++i)
    sum += i;
    return sum;
}

int a[7] = {1, 2, 3};
std::cout << calc(a);

a = {1,2,3,0,0,0,0}

sum = 8 + 1 + 2 + 3 = 13

b)
char text[] = "hello", *p = text;
while (*p) std::cout << ++*p++;

"hello" 
'h' -> ++'h' => 'i', 'j', 'k', ... // "ik"

c)
int *pt; //nullptr
int a[3] = {4, 19, 13};
pt = &a[1]; // *pt = 19
pt += 1; // *pt = 13
std::cout << *pt << std::endl; // 13

d) 
void f(int * arr1, const int * arr2)
{
    int *p1 = arr1;
    const int *p2 = arr2;
        while(*p2 >= 0)
        {
            *p1++ = *p2++;
        }
}
void main()
{
int A[4] = {-1, -2, -3, -4};
int B[4] = {10, 20, 30, -1};
f(A, B);
}

10, 20, 30, -4
10, 20, 30, -1

// 
Дадени са структура Point, описваща точка в декартова координатна система с
координати x и y от тип float, и структура Circle, описваща окръжност с център center от тип Point
и радиус r от тип float.
Да се дефинира функция findRelativePosition, която определя относителната позиция на две
дадени окръжности една спрямо друга. Резултатът от изпълнението на функцията е стойност от изброения тип:
RelativePosition {NO_COMMON_POINTS, TOUCHING,
INTERSECTING, SAME}.
със следния смисъл:
• NO_COMMON_POINTS: без общи точки
• TOUCHING: допиращи се
• INTERSECTING: пресичащи се
• SAME: съвпада

enum RelativePosition {
    NO_COMMON_POINTS,
    TOUCHING,
    INTERSECTING,
    SAME
}

struct Point {
    float x;
    float y;
}

struct Circle {
    Point center;
    float r;
}

RelativePosition findRelativePosition(Circle& c1, Circle& c2) {
    if(c1.center.x == c2.center.x && c1.center.y == c2.center.y && c1.r == c2.r) {
        return RelativePosition.SAME;
    }
    if((c1.center.x + c1.center.r) - (c2.center.x + c2.center.r) > 0 &&
       (c1.center.x + c1.center.r) - (c2.center.x - c2.center.r) > 0 &&
       (c1.center.y + c1.center.r) - (c2.center.y + c2.center.r) > 0 &&
       (c1.center.y + c1.center.r) - (c2.center.y - c2.center.r) > 0) {
        return RelativePosition.NO_COMMON_POINTS;
    }
    if((c1.center.x + c1.center.r) - (c2.center.x + c2.center.r) == 0 ||
       (c1.center.x + c1.center.r) - (c2.center.x - c2.center.r) == 0 ||
       (c1.center.y + c1.center.r) - (c2.center.y + c2.center.r) == 0 ||
       (c1.center.y + c1.center.r) - (c2.center.y - c2.center.r) == 0) {
        return RelativePosition.TOUCHING;
    } 
    return INTERSECTING;
}


