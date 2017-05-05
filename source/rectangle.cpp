#include "rectangle.hpp"
#include "vec2.hpp"
#include <cmath>

Rectangle::Rectangle (Vec2 min, Vec2 max, Color c):
    min_(min),
    max_(max),
    c_(c) {}

Vec2 Rectangle::getMin () const{
    return this -> min_;
}

Vec2 Rectangle::getMax () const{
    return this -> max_;
}

Color Rectangle::getColor () const{
    return this -> c_;
}

float Rectangle::circumference () const{
    float a = max_.x_ - min_.x_;                //Länge
    float b = max_.y_ - min_.y_;                //Breite
    return 2*a+2*b;
}


