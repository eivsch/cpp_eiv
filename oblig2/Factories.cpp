#include "Factories.hpp"

using namespace std;

/** Blinking Dots */

// Generate color for the dot and create
dot* BlinkingDotFactory::createDot(float _x, float _y, float _r){
	return new BlinkingDot(_x, _y, _r);
}

BlinkingDot::BlinkingDot(float _x, float _y, float _r) : 
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
	return new NormalDot(_x, _y, _r);
}

NormalDot::NormalDot(float _x, float _y, float _r) : 
	dot(_x, _y, _r, fl_rgb_color((rand()%26)+230,rand()%100,rand()%40))		// Orange
{
}

/** Tinted dots */
dot* TintedDotFactory::createDot(float _x, float _y, float _r){
	return new TintedDot(_x, _y, _r);
}

Color TintedDot::tint(){
	Color tint=fl_rgb_color(rand()%180,5,(rand()%20)+180);	// Purple
	return tint;
}

TintedDot::TintedDot(float _x, float _y, float _r) : 
	dot(_x, _y, _r, tint()){
}

/** Mixed dots, alternating between existing dot-types */
dot* MixedDotFactory::createDot(float _x, float _y, float _r){
	mixer++;
	if(mixer==1)
		return new NormalDot(_x, _y, _r);
	else if(mixer==2)
		return new TintedDot(_x, _y, _r);
	else{ 
		mixer=0;
		return new BlinkingDot(_x, _y, _r);
	}
}