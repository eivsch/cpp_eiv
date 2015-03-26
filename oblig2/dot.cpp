#include "dot.hpp"
#include <FL/fl_draw.H>  // drawing

using namespace std;

void dot::draw(){
	fl_color(color());
	fl_pie(x(),y(),r,r,0,360);
}
dot::dot(float _x, float _y, float _r) : is_vector(_x, _y), r{_r}, has_color(true) { // initialize dot with random colors
}
dot::dot(float _x, float _y, float _r, Color c) : 
	is_vector(_x,_y), r{_r}, has_color(c)
{
}
dot::~dot(){
}
void dot::clear(){
}
void dot::operator++(){
	increment_position();
	draw();
}
void dot::reset(){}