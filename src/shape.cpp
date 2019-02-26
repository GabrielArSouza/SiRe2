#include "shape.h"

Shape::Shape ( Color *color, Color *color_fill)
{
	this->color = color;
	this->color_fill = color_fill;
}

Shape::~Shape (){}

Color* Shape::get_color ()
{ return this->color; }

void Shape::set_color (Color *color)
{ this->color = color; }

Color* Shape::get_color_fill ()
{ return this->color_fill; }

void Shape::set_color_fill (Color *color_fill)
{ this->color_fill = color_fill; }