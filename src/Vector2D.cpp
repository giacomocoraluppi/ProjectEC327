#include "Vector2D.h"

Vector2D::Vector2D(){ //default constructor
    x = 0;
    y = 0;
}
Vector2D::Vector2D(double in_x, double in_y){ //constructor with parameters
    x = in_x;
    y = in_y;
}

ostream& operator << (ostream &os, Vector2D const &v1){ //overloaded << operator
    os << "<" << v1.x << ", " << v1.y << ">";
    return os;
}

Vector2D operator * (Vector2D const &v1, double const &d1){ //overloaded * operator
    Vector2D doubledVec;
    
    doubledVec.x = v1.x * d1;
    doubledVec.y = v1.y * d1;

    return doubledVec;
}

Vector2D operator / (Vector2D const &v1, double const &d1){ //overloaded / operator
    Vector2D halfVec;
    
    if (d1 != 0){
        halfVec.x = v1.x / d1;
        halfVec.y = v1.y / d1;
    }
    else{
        halfVec.x = v1.x;
        halfVec.y = v1.y;
    }

    return halfVec;
}