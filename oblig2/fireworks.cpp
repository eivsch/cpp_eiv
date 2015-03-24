#include "fireworks.hpp"
#include "rocket.hpp"

using namespace std;

fireworks::fireworks(const char* title,int w, int h, int _rocketcount)
	: animation_canvas(title, w, h), rocketcount{_rocketcount}
{
	for(int i=0;i<rocketcount;i++)
		add(new rocket(200,10,10,100,100));
}
fireworks::~fireworks(){}