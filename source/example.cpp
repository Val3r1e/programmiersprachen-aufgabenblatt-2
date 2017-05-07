#include "window.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>
#include "vec2.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include <vector>

int main(int argc, char* argv[])
{

  Window win{std::make_pair(800,800)};

  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }

    bool left_pressed = win.get_mouse_button(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;

    /*auto t = win.get_time();

    float x1{400 + 380 * std::sin(t)};
    float y1{400 + 380 * std::cos(t)};

    float x2{400 + 380 * std::sin(2.0f*t)};
    float y2{400 + 380 * std::cos(2.0f*t)};

    float x3{400 + 380 * std::sin(t-10.f)};
    float y3{400 + 380 * std::cos(t-10.f)};*/

    //Objekte erstellen

    Rectangle r1 {Vec2{200.0f,450.0f},Vec2{350.0f,600.0f},Color{0.0}};

    Rectangle r2 {Vec2{100.0f,250.0f},Vec2{400.0f,400.0f},Color{0.0}};
  
    Circle c1 {Vec2{600.0f,350.0f}, 100.0f,Color{0.0}};

    Circle c2 {Vec2{700.0f,500.0f}, 50.0f, Color{0.0}};

    //Objekte zeichnen

    r1.draw(win, Color{1.0,1.0,1.0});

    r2.draw(win);

    c1.draw(win);

    c2.draw(win,Color{1.0,1.0,1.0});

    //Vektor erstellen

    std::vector<Circle> vc;

    std::vector<Rectangle> vr;

    //Objekte in Vektor

    vc.push_back(c1);
    vc.push_back(c2);

    vr.push_back(r1);
    vr.push_back(r2);

    //Blau Funktion

    Vec2 n {(float)win.mouse_position().first,(float)win.mouse_position().second};

    Color clr {0.0f,0.0f,1.0f};

    for(int i = 0; i < vr.size(); i++){       //Rechteck blau
      if(vr[i].is_inside(n) == true){
        vr[i].draw(win,clr);
      }
    }

    for(int i = 0; i < vc.size(); i++){        //Kreis blau
      if(vc[i].is_inside(n) == true){
        vc[i].draw(win,clr);
      }
    }

    /*win.draw_point(x1, y1,
        1.0f, 0.0f, 0.0f);
    win.draw_point(x2, y2, 0.0f, 1.0f, 0.0f);
    win.draw_point(x3, y3, 0.0f, 0.0f, 1.0f);*/

    auto m = win.mouse_position();
    if (left_pressed) {
      win.draw_line(30, 30, // from
          m.first, m.second, // to
          1.0,0.0,0.0);
    }

    win.draw_line(0, m.second, 10, m.second, 0.0, 0.0, 0.0);
    win.draw_line(win.window_size().second - 10, m.second, win.window_size().second, m.second, 0.0, 0.0, 0.0);

    win.draw_line(m.first, 0, m.first, 10, 0.0, 0.0, 0.0);
    win.draw_line(m.first, win.window_size().second - 10, m.first, win.window_size().second, 0.0, 0.0, 0.0);

    std::string text = "mouse position: (" + std::to_string(m.first) + ", " + std::to_string(m.second) + ")";
    win.draw_text(10, 5, 35.0f, text);

  

    win.update();
  }

  return 0;
}
