#include "rocket.hpp"
#include <iostream>

using namespace std;

int counter{0};

void rocket::operator++(){
	if(fuse!=0)
		fuse--;
	else {
		for (auto d : dots){
			++(*d);
			// Dots will gradually fade out
			if(counter%5==0){
				d->darken_color();
			}
		}
		counter++;
	}
}
rocket::rocket(int _dotcount,int dotsize, int _fuse, int x, int y) : 
	dotcount{_dotcount}, fuse{_fuse}{
		// Create each dot with random colors and add to container
		for(int i=0; i<_dotcount; i++){
			Color color=fl_rgb_color((rand()%26)+200,rand()%150,rand()%120);	// Converting RGB-values to single color.
			dots.push_back(new dot(x,y,dotsize,color));
		}
}
rocket::rocket(int _dotcount,int dotsize, int _fuse, int x, int y, 
         AbstractDotFactory* dotFactory){
}
rocket::~rocket(){	
}