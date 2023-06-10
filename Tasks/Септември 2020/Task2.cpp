

#include<iostream>
#include<vector>

/*
Задача 2. а) Да се проектират и разработят класове Point2D и PointSet2D. Point2D да описва точка
в евклидовата равнина. Координатите на точката да се представят с числа с плаваща запетая (от тип
double). PointSet2D да описва множество от точки в равнината и да предоставя следните възможности:
    1. Добавяне на произволен брой точки към множеството. Да не се допускат повторения на елементи
    на множеството. Добавянето на точки да може да се извършва чрез операциите + и +=.
    2. Операции + и += за обединение на две множества от точки.
    3. Възможност за обхождане на точките от множеството.
б) Да се дефинира булева функция within, която проверява дали всички точки на дадено множество
лежат в кръг с даден център и радиус.
При проектирането на класовете да се спазят следните изисквания:
• Да се спази принципът на капсулацията.
• Да се реализират подходящи конструктори, деструктори, операции за присвояване и др., които
са подходящи за класовете.
• Операциите + и += да са с коректно подбрана мутираща или немутираща (константна) форма, да
имат подходящ тип на резултата и да връщат подходящи резултати.*/

struct Point2D {
    double x;
    double y;

    public:
};

class PointSet2D {
    private:
    std::vector<Point2D*> points; 

    public:
    PointSet2D operator+(Point2D& point2D) {
        PointSet2D newPointSet;
        for(int i = 0; i < points.size(); i++) {
            newPointSet += *points[i];
        }
        newPointSet += (point2D);
        return newPointSet;
    }

    PointSet2D& operator+=(Point2D& point2D) {
        for (int i = 0; i < points.size(); ++i) {
            if(points[i] == &point2D) {
                return *this;
            }
        }
        points.push_back(&point2D);
        return *this;
    }

    PointSet2D operator+(PointSet2D& point2D) {
        PointSet2D newPointsSet;
        for (int i = 0; i < points.size(); ++i) {
            newPointsSet += *points[i];
        }
        for (int i = 0; i < point2D.points.size(); ++i) {
            newPointsSet += *point2D.points[i];
        }
        return *this;
    }

    PointSet2D& operator+=(PointSet2D& point2D) {
        for (int i = 0; i < point2D.points.size(); ++i) {
            *this += *point2D.points[i];
        }
        return *this;
    }

    Point2D& operator[](int i) {
        return *points[i];
    }

    size_t size() {
        return points.size();
    }
};

bool checkPoint(Point2D pointToCheck, Point2D center, double r) {
    return (pointToCheck.x <= center.x + r || pointToCheck.x >= center.x - r) &&
            (pointToCheck.y <= center.y + r || pointToCheck.y >= center.y - r);
}

bool within(PointSet2D pointSet2D, Point2D center, double r) {
    for (int i = 0; i < pointSet2D.size(); ++i) {
        if(!checkPoint(pointSet2D[i], center, r)) {
            return false;
        }
    }
    return true;
}

int main() {

}