#include <FL/Fl_Window.H>
#include <iostream>
#include "fireworks.hpp"

using namespace std;

int main(int argc, char** argv){

	srand(time(NULL));

	const int screen_width=Fl::w(), screen_height=Fl::h();
	Fl_Window* window=new Fl_Window(screen_width,screen_height,"Fireworks!");

	fireworks* f=new fireworks("F2",screen_width,screen_height,12);

	animation_canvas::timer(window);
	
	window->color(FL_BLACK);
	window->end();
	window->show();
	Fl::run();

	delete f;
  	delete window;
}