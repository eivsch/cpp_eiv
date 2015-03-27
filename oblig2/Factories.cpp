#include "Factories.hpp"
#include <iostream>

using namespace std;

/** Blinking Dots */

// Generate color for the dot and create
dot* BlinkingDotFactory::createDot(float _x, float _y, float _r){
	return new BlinkingDot(_x, _y, _r);
}

BlinkingDot::BlinkingDot(float _x, float _y, float _r) : blinker{0}, 
	dot(_x, _y, _r, fl_rgb_color((rand()%56)+200,(rand()%56)+200,(rand()%56)+100))		// White
{
}

// Alternate between draw() and clear() within a reasonable intervall
void BlinkingDot::operator++(){
	if(blinker<3)
		draw();
	else if(blinker<4)
		clear();
	else
		blinker=-1;
	increment_position();
	blinker++;
}

/** Normal Dots */
dot* NormalDotFactory::createDot(float _x, float _y, float _r){
	int r=(rand()%26)+230, g=(rand()%150), b=rand()%150;			// Orange
	Color c=fl_rgb_color(r,g,b);
	return new dot(_x, _y, _r, c);
}

/** Tinted dots */
dot* TintedDotFactory::createDot(float _x, float _y, float _r){
	return new TintedDot(_x, _y, _r);
}

Color TintedDot::tint(){
	return fl_rgb_color(rand()%180,5,rand()%200);	// Purple
}

TintedDot::TintedDot(float _x, float _y, float _r) : 
	dot(_x, _y, _r, tint()){
}

/** Mixed dots */
dot* MixedDotFactory::createDot(float _x, float _y, float _r){

}