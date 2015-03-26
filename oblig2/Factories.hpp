#ifndef CLASS_FACTORIES_H
#define CLASS_FACTORIES_H

#include "dot.hpp"

class AbstractDotFactory {
	virtual dot* createDot(float _x, float _y, float _r)=0;
};

class NormalDotFactory : AbstractDotFactory{
public:
	dot* createDot(float _x, float _y, float _r) override;
};

class BlinkingDotFactory : AbstractDotFactory{
public:
	dot* createDot(float _x, float _y, float _r) override;
};

class TintedDotFactory : AbstractDotFactory{
public:
	dot* createDot(float _x, float _y, float _r) override;
};

class MixedDotFactory : AbstractDotFactory{
public:
	dot* createDot(float _x, float _y, float _r) override;
};

class BlinkingDot : dot{
	int r, g, b;
public:
	BlinkingDot(float _x, float _y, float _r);
	void dot::operator++() override;
};

#endif