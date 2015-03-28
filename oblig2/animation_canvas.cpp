#include "animation_canvas.hpp"
#include <FL/fl_draw.H>

using namespace std;

int animation_canvas::fps{25};

animation_canvas::animation_canvas(const char *l, int w, int h) :
	Fl_Box(0,0,w,h,l)
{
}
void animation_canvas::timer(void* canvas){
	Fl::repeat_timeout(1.0/fps, timer, canvas);
	((Fl_Window*)canvas)->redraw();
}
void animation_canvas::add(animated* part){
	parts.push_back(part);
}
animation_canvas::~animation_canvas(){
}
void animation_canvas::draw(){
	increment();
}
void animation_canvas::increment(){
	for(auto p : parts)
		++(*p);
}