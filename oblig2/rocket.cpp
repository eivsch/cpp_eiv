#include "rocket.hpp"
#include <iostream>

using namespace std;

int counter=1000;

void rocket::operator++(){
	if(fuse!=0) {
		fuse--;
		cout << "Fuse: " << fuse << endl;
	}
	else {
		for (auto d : dots){
			++(*d);
			// Dots will gradually fade out
			if(counter%4==0){
				d->darken_color();
			}
		}
		counter--;
	}
}
rocket::rocket(int _dotcount,int dotsize, int _fuse, int x, int y) : 
	dotcount{_dotcount}, fuse{_fuse}{
		// Generate random, light colors
		int r=(rand()%100)+100, g=rand()%50, b=rand()%80;        // TODO: ha g og b som x^2 funksjoner for større variasjoner
		int color=fl_rgb_color(r,g,b);
		for(int i=0; i<_dotcount; i++){
			// Have slightly different colors for each dot
			r+=rand()%56; 										 // TODO: Mer variasjon (g,b)
			color=fl_rgb_color(r,g,b);
			dots.push_back(new dot(x,y,dotsize,color));
		}
}
rocket::rocket(int _dotcount,int dotsize, int _fuse, int x, int y, 
         AbstractDotFactory* dotFactory){
}
rocket::~rocket(){
	
}