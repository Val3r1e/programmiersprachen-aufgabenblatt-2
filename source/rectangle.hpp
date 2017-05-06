#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"

class Rectangle 
{
    private:
        Vec2 min_;
        Vec2 max_;
        Color c_;

    public:

        Rectangle (Vec2 min, Vec2 max, Color c);

        Vec2 getMin () const;

        Vec2 getMax () const;

        Color getColor () const;

        float circumference () const;

        void draw (Window const& w);

        void draw (Window const& w, Color const& c);

                               

};
#endif