#include "Factories.hpp"
#include <iostream>

using namespace std;

dot* BlinkingDotFactory::createDot(float _x, float _y, float _r){
	return new BlinkingDot(_x,_y,_r);
}

/** Create a blinking dot with generated color */
BlinkingDot::BlinkingDot(float _x, float _y, float _r) : 
	r{(rand()%16)+240}, g{(rand()%16)+240}, b{(rand()%16)+240}, 
	dot(_x, _y, _r, fl_rgb_color(r,g,b))
{
	cout << "rand: " << fl_rgb_color(255,255,255) << endl;
}