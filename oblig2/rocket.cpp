#include "rocket.hpp"

using namespace std;

void rocket::operator++(){
	if(fuse!=0) fuse--;
	else {
		for (auto d : dots)
			++(*d);
	}
}
rocket::rocket(int _dotcount,int dotsize, int _fuse, int x, int y) : 
	dotcount{_dotcount}, fuse{_fuse}{
		for(int i=0; i++; i<_dotcount)
			dots.push_back(new dot(x,y,dotsize));
}
rocket::rocket(int _dotcount,int dotsize, int _fuse, int x, int y, 
         AbstractDotFactory* dotFactory){

}
rocket::~rocket(){
	
}