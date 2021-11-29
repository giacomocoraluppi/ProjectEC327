#ifndef VECTOR2D_H //include guard
#define VECTOR2D_H //include guard

#include <iostream>

using namespace std;

class Vector2D
{
    public:
        double x;
        double y;
        
        Vector2D();
        Vector2D(double, double);
};

ostream& operator << (ostream &os, Vector2D const &v1);
Vector2D operator * (Vector2D const &v1, double const &d1);
Vector2D operator / (Vector2D const &v1, double const &d1);

#endif //include guard