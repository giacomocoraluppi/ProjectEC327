#ifndef POINT2D_H //include guard
#define POINT2D_H //include guard

#include <iostream>
#include <math.h>

#include "Vector2D.h"

using namespace std;

class Point2D
{
    public:
        double x;
        double y;
        
        Point2D();
        Point2D(double, double);
};

double GetDistanceBetween(Point2D p1, Point2D p2);
ostream& operator << (ostream &os, Point2D const &p1);
Point2D operator + (Point2D const &p1, Vector2D const &v1);
Vector2D operator - (Point2D const &p1, Point2D const &p2);

#endif //include guard