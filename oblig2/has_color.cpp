#include "has_color.hpp"
#include <stdlib.h>
#include <time.h>

using namespace std;

has_color::has_color(bool Random){
	// generate random rgb-number (0-255) and assign each part
	if(Random){
		srand(time(NULL));
		*red_=rand()%256;
		*green_=rand()%256;
		*blue_=rand()%256;
		// set corresponding value to color_
		color_=fl_rgb_color(*red_,*green_,*blue_);
	}else{
		// initialize with default color
		color_=FL_WHITE;
		*red_=255; *green_=255; *blue_=255;
	}
}
has_color::has_color(Color start) : color_{start}{
	// give ColorParts dummy values
	*red_=0; *green_=0; *blue_=0;
}
has_color::has_color(ColorPart red, ColorPart green, ColorPart blue){
	*red_=red; *green_=green; *blue_=blue;
	// set corresponding value to color_
	color_=fl_rgb_color(*red_,*green_,*blue_);
}
void has_color::darken_color(){
	color_=fl_darker(color_);
}
void has_color::lighten_color(){
	color_=fl_lighter(color_);
}