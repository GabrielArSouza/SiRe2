#include "circle.h"

/**
 * Constructors
 */

Circle::Circle(POINT center, int radius) 
    : Shape(Color::BLACK)
{ 
    this->center = center;
    this->radius = radius;
}

Circle::Circle(POINT center, int radius, const Color &color) 
    : Shape(color)
{ 
    this->center = center;
    this->radius = radius;
}

Circle::~Circle(){}

/**
 * Principal methods
 */
#include <iostream>

void Circle::plot_octante_circle (POINT p)
{ 
    this->pixels.push_back(POINT {center.x + p.x, center.y + p.y});
    this->pixels.push_back(POINT {center.x + p.x, center.y - p.y});
    this->pixels.push_back(POINT {center.x - p.x, center.y + p.y});
    this->pixels.push_back(POINT {center.x - p.x, center.y - p.y});
    this->pixels.push_back(POINT {center.x + p.y, center.y + p.x});
    this->pixels.push_back(POINT {center.x - p.y, center.y + p.x});
    this->pixels.push_back(POINT {center.x + p.y, center.y - p.x});
    this->pixels.push_back(POINT {center.x - p.y, center.y - p.x});
}
void Circle::draw()
{
    int x = 0;
    int y = this->radius;
    int d = 1 - radius;

    int dl = 3;
    int dse = (-2) * radius + 5;

    this->plot_octante_circle(POINT{x,y});
    while (y>x)
    {
        if (d < 0)
        {
            d += dl;
            dl += 2;
            dse += 2;

        }else{
            d += dse;
            dl += 2;
            dse += 4;
            y--;
        } 
        x++;
        plot_octante_circle(POINT{x,y});
    }
}

/**
 * Getters and Setters 
 */

int Circle::get_radius ()
{ return this->radius; }

void Circle::set_radius (int radius)
{ this->radius = radius; }

std::string Circle::to_string()
{  return "I'm a circle and my color is " + color.to_string() + "\n"; }