#include "fireworks.hpp"
#include "rocket.hpp"
#include "Factories.hpp"
#include <iostream>

using namespace std;

fireworks::fireworks(const char* title,int w, int h, int _rocketcount)
	: animation_canvas(title, w, h), rocketcount{_rocketcount}
{
	int fuse, x, y;
	for(int i=0;i<rocketcount;i++){
		// Generate random numbers for rocket position and fuse, and create different factories
		fuse=rand()%250; x=(Fl::w()/2)+(rand()%800)-400; y=(Fl::h()/2)+(rand()%300)-150;
		if(i%2==0)
			animation_canvas::add(new rocket(200, 4, fuse, x, y, new BlinkingDotFactory()));
		else animation_canvas::add(new rocket(200, 4, fuse, x, y, new TintedDotFactory()));
	}
}
fireworks::~fireworks(){}