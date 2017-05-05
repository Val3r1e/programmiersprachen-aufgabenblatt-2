#include "mat2.hpp"
#include "vec2.hpp"

Mat2::Mat2 (): 
    x_(1.0f), y_(0.0f), 
    g_(0.0f), h_(1.0f) {}

Mat2::Mat2 (float x, float y, float g, float h): 
    x_(x), y_(y), 
    g_(g), h_(h) {}

Mat2::Mat2 (Mat2 const & m):
    x_ (m.x_),
    y_ (m.y_),
    g_ (m.g_),
    h_ (m.h_) {}


Mat2 & Mat2::operator *=( Mat2 const & m){
    float tx = x_ * m.x_ + y_ * m.g_;
    float ty = x_ * m.y_ + y_ * m.h_;
    float tg = g_ * m.x_ + h_ * m.g_;
    float th = g_ * m.y_ + h_ * m.h_;
    this -> x_ = tx;
    this -> y_ = ty;
    this -> g_ = tg;
    this -> h_ = th;
    return *this;
}

float Mat2:: det () const{
    float d = x_ * h_ - (g_ * y_);
    return d;
}

/*Mat2 & Mat2::operator *=(Vec2 const& w){
    this -> x_ = x_ * w.x_;
    this -> y_ = y_ * w.y_;
    this -> g_ = g_ * w.x_;
    this -> h_ = h_ * w.y_;
    return *this;
}*/

Mat2 const operator *( Mat2 const & m1 , Mat2 const & m2 ){
    return Mat2(m1) *= m2;
}

/*Vec2 const operator *( Mat2 const & m, Vec2 const & v){
    return Mat2(m) *= v;
}*/

