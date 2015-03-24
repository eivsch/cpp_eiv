#include <FL/Fl_Window.H>
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include "fireworks.hpp"

using namespace std;

int main(int argc, char** argv){
	Fl_Window* window=new Fl_Window(340,180,"Fireworks!");

	fireworks* f=new fireworks("F2",340,180,10);

	animation_canvas::timer(window);

	
	window->end();
	window->show();
	Fl::run();

	delete f;
  	delete window;
}