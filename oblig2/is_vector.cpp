#include "is_vector.hpp"
#include <stdlib.h>

using namespace std;

is_vector::is_vector(double x, double y) : x_{x}, x_orig_{x}, 
	y_{y}, y_orig_{y}{
	// Assigning speed and direction randomly
	speed_=(rand()%2000)/100;
	// Generate direction by degrees and convert to radians
	double deg=rand()%361;
	direction_=(deg/180)*M_PI;
}
void is_vector::increment_position(){
	// Increment x with x-component of speed
	x_+=speed_*(cos (direction_));
	// Increment y with y-component of speed
	y_+=speed_*(sin (direction_));
}
void is_vector::reset(){
	x_=x_orig_; y_=y_orig_;
}