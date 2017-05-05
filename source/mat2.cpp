#include "mat2.hpp"
#include "vec2.hpp"
#include <cmath>

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

Mat2 const operator *( Mat2 const & m1 , Mat2 const & m2 ){
    return Mat2(m1) *= m2;
}

Vec2 const operator *( Mat2 const & m, Vec2 const & v){
    float tx = m.x_ * v.x_ + m.y_ * v.y_;
    float ty = m.g_ * v.x_ + m.h_ * v.y_;
    return Vec2(tx,ty);
}

Vec2 const operator *( Vec2 const & v, Mat2 const & m){
    float tx = m.x_ * v.x_ + m.y_ * v.y_;
    float ty = m.g_ * v.x_ + m.h_ * v.y_;
    return Vec2(tx,ty);
}

float Mat2:: det () const{
    float d = x_ * h_ - (g_ * y_);
    return d;
}

Mat2 const inverse ( Mat2 const & m){
    float con = (1/(m.x_*m.h_-(m.y_*m.g_)));
    float tx = m.h_ * con;
    float ty = -(m.y_) * con;
    float tg = -(m.g_) * con;
    float th = m.x_ * con;
    return Mat2(tx,ty,tg,th);
}

Mat2 const transpose ( Mat2 const & m){
    float tx = m.x_;
    float ty = m.g_;
    float tg = m.y_;
    float th = m.h_;
    return Mat2(tx,ty,tg,th);
}

Mat2 const make_rotation_mat2 ( float phi ){
    float tx = cos(phi);
    float ty = -sin(phi);
    float tg = sin(phi);
    float th = cos(phi);
    return Mat2(tx,ty,tg,th);
}


