#include "window.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>
#include "vec2.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

int main(int argc, char* argv[]){
    Window win{std::make_pair(800,800)};
    while (!win.should_close()) {
        if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            win.close();
        }

        Circle c1 {Vec2{400.0f,400.0f}, 300.0f,Color{0.0}};

        c1.draw(win);

        auto t = win.get_time();


        Vec2 middle (c1.getMiddle().x_,c1.getMiddle().y_);

        win.draw_line(400.0f,400.0f,-(c1.getRadius()-10)*cos(t*0.001f)+ middle.x_, -(c1.getRadius()-10)*sin(t*0.001f)+ middle.y_,0.0,0.0,0.0);
            
        win.draw_line(400.0f,400.0f,-(c1.getRadius()-100.0f)*cos(t*0.1f)+ middle.x_, -(c1.getRadius()-90.0f)*sin(t*0.1f)+ middle.y_,0.0,0.0,0.0);

        win.draw_line(400.0f,400.0f,-(c1.getRadius()-400.0f)*cos(t*6.0f)+ middle.x_, -(c1.getRadius()-400.0f)*sin(t*6.0f)+ middle.y_,0.0,0.0,0.0);


        
        win.update();

    }

    return 0;
}