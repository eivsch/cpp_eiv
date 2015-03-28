#include "fireworks.hpp"
#include "rocket.hpp"
#include "Factories.hpp"

using namespace std;

/** Creates the rockets using in turn each one of the 4 different factories */
fireworks::fireworks(const char* title,int w, int h, int _rocketcount)
	: animation_canvas(title, w, h), rocketcount{_rocketcount}
{
	int fuse, x, y, counter=0;
	for(int i=0;i<rocketcount;i++){
		// Generate random numbers for rocket position and fuse
		fuse=rand()%250; x=(Fl::w()/2)+(rand()%800)-400; y=(Fl::h()/2)+(rand()%300)-150;

		counter++;
		if(counter==1)
			animation_canvas::add(new rocket(200, 4, fuse, x, y, new NormalDotFactory()));
		else if(counter==2) 
			animation_canvas::add(new rocket(200, 4, fuse, x, y, new BlinkingDotFactory()));
		else if (counter==3)
			animation_canvas::add(new rocket(200, 4, fuse, x, y, new TintedDotFactory()));
		else{
			animation_canvas::add(new rocket(200, 4, fuse, x, y, new MixedDotFactory()));
			counter=0;																						// TODO: Switch-case?
		}
	}
}
fireworks::~fireworks(){
}