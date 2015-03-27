#include "rocket.hpp"
#include "Factories.hpp"
#include <iostream>


using namespace std;

int counter=1000;

void rocket::operator++(){
	if(fuse!=0)
		fuse--;
	else {
		for (auto d : dots){
			++(*d);
			// Dots will gradually fade out
			if(counter%5==0)
				d->darken_color();
		}
		counter--;
	}
}
rocket::rocket(int _dotcount,int dotsize, int _fuse, int x, int y){
}
rocket::rocket(int _dotcount,int dotsize, int _fuse, int x, int y, 
         AbstractDotFactory* dotFactory) : dotcount{_dotcount}, fuse{_fuse}{
	for(int i=0; i<dotcount; i++)
		dots.push_back(dotFactory->createDot(x,y,dotsize));
}
rocket::~rocket(){
}
