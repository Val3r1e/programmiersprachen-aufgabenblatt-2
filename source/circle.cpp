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

void Circle::draw (Window const& w){
    Vec2 middle (m_.x_,m_.y_);
    for(int i = 1; i <= 360; i++){
        w.draw_point(r_*cos(i)+ middle.x_, r_*sin(i)+ middle.y_,0.0f,0.0f,0.0f);
    }
}

void Circle::draw (Window const& w, Color c){
    Vec2 middle (m_.x_,m_.y_);
    for(int i = 1; i <= 360; i++){
        w.draw_point(r_*cos(i)+ middle.x_, r_*sin(i)+ middle.y_,c.r_,c.g_,c.b_);
    }
}

bool Circle::is_inside (Vec2 const& v){
    Vec2 middle (m_.x_,m_.y_);
    for (int i = 1; i <= 360; i++){
        Vec2 t (r_*cos(i)+ middle.x_, r_*sin(i)+ middle.y_);
        if (v.x_ >= middle.x_ && v.x_ < t.x_ && v.y_ >= middle.y_ && v.y_ < t.y_){ //Oben rechts
            return true;
        }
        if (v.x_ <= middle.x_ && v.x_ > t.x_ && v.y_ >= middle.y_ && v.y_ < t.y_){ //Oben links
            return true;
        }
        if (v.x_ >= middle.x_ && v.x_ < t.x_ && v.y_ <= middle.y_ && v.y_ > t.y_){ //Unten rechts
            return true;
        }
        if (v.x_ <= middle.x_ && v.x_ > t.x_ && v.y_ <= middle.y_ && v.y_ > t.y_){ //Unten links
            return true;
        }
    }
    return false;
}