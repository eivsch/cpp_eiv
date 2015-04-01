#include "fireworks.hpp"
#include "rocket.hpp"

using namespace std;

fireworks::fireworks(const char* title,int w, int h, int _rocketcount)
	: animation_canvas(title, w, h), rocketcount{_rocketcount}
{
	int fuse, x, y;
	for(int i=0;i<rocketcount;i++){
		// Generate random numbers for rocket position and fuse
		fuse=rand()%250; x=(w/2)+(rand()%800)-400; y=(h/2)+(rand()%300)-150;
		animation_canvas::add(new rocket(200,4,fuse,x,y));
	}
}
fireworks::~fireworks(){}