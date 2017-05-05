#include "vec2.hpp"
// Mat2 definition
struct Mat2
{
    float x_;
    float y_;
    float g_;
    float h_;

    Mat2();

    Mat2(float x, float y, float g, float h);

    Mat2(Mat2 const & m);

    Mat2 & operator *= ( Mat2 const & m);

    //Mat2 & operator *= (Vec2 const& w);

    float det () const;

    


};

Mat2 const operator *( Mat2 const & m1 , Mat2 const & m2 );

Vec2 const operator *( Mat2 const & m, Vec2 const & v);

Vec2 const operator *( Vec2 const & v, Mat2 const & m);

Mat2 const inverse ( Mat2 const & m);

Mat2 const transpose ( Mat2 const & m);

Mat2 const make_rotation_mat2 ( float phi );