#include "has_color.hpp"
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

// Color representation is RGBI (1 byte each), assigning each ColorPart to corresponding byte.
has_color::has_color(bool Random) : red_{(unsigned char * ) &color_}, green_{((unsigned char * ) &color_) + 1}, 
									blue_{((unsigned char * ) &color_) + 2} {
	unsigned char* i=((unsigned char *)  &color_) + 3;
	i=0x00;
	if(Random)
		color_ = rand(); // TODO: Hva med den fjerde biten? Skal den være null?
}
has_color::has_color(Color start) : has_color{false} {
	color_ = start;
}
has_color::has_color(ColorPart red, ColorPart green, ColorPart blue) : has_color{false}
{
	*red_=red; *green_=green; *blue_=blue;
}
void has_color::darken_color(){
	color_=fl_darker(color_);
}
void has_color::lighten_color(){
	color_=fl_lighter(color_);
}