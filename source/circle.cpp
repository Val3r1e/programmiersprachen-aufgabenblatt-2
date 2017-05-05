#include "circle.hpp"
#include "vec2.hpp"
#include <cmath>

Circle::Circle (Vec2 m, float r, Color c): 
    m_(m),
    r_(r),
    c_(c) {}

Vec2 Circle::getMiddle () const {
    return this -> m_;
}

float Circle::getRadius () const{
    return this -> r_;
}

Color Circle::getColor () const{
    return this -> c_;
}

float Circle::circumference () const{
    return 2*M_PI*r_; 
}