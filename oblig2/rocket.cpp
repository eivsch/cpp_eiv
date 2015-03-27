#include "rocket.hpp"
#include <iostream>

using namespace std;

int counter=1000;    						// TODO: bruke t i animated

void rocket::operator++(){
	if(fuse!=0) {
		fuse--;
		cout << "Fuse: " << fuse << endl;
	}
	else {
		for (auto d : dots){
			++(*d);
			// Dots will gradually fade out
			if(counter%5==0){
				d->darken_color();
			}
		}
		counter--;
	}
}
rocket::rocket(int _dotcount,int dotsize, int _fuse, int x, int y) : 
	dotcount{_dotcount}, fuse{_fuse}{
		// Generate random, light colors
		int r=(rand()%26)+230, g=(rand()%150), b=rand()%150;        // TODO: ha g og b som x^2 funksjoner for større variasjoner
		Color color=fl_rgb_color(r,g,b);
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