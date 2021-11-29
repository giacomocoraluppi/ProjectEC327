#include "Point2D.h"

Point2D::Point2D(){ //dafult constructor
    x = 0;
    y = 0;
}

Point2D::Point2D(double in_x, double in_y){ //constructor with parameters
    x = in_x;
    y = in_y;
}

double GetDistanceBetween(Point2D p1, Point2D p2){ //distance function
    double distance;

    distance = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));

    return distance;
}

ostream& operator << (ostream &os, Point2D const &p1){ //overloaded << operator
    os << "(" << p1.x << ", " << p1.y << ")";
    return os;
}

Point2D operator + (Point2D const &p1, Vector2D const &v1){ //overloaded + operator
    Point2D newPoint;

    newPoint.x = p1.x + v1.x;
    newPoint.y = p1.y + v1.y;

    return newPoint;
}

Vector2D operator - (Point2D const &p1, Point2D const &p2){ //overloaded - operator
    Vector2D newVector;

    newVector.x = p1.x - p2.x;
    newVector.y = p1.y - p2.y;

    return newVector;
}