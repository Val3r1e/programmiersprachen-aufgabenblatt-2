#include "color.hpp"

Color::Color (): 
    r_(0.0),
    g_(0.0),
    b_(0.0) {} 

Color::Color (float r, float g, float b):
    r_(r),
    g_(g),
    b_(b) {}

Color::Color (float c):
    r_(c),
    g_(c),
    b_(c) {}



