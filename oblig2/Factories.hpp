#ifndef CLASS_FACTORIES_H
#define CLASS_FACTORIES_H

#include "dot.hpp"

class AbstractDotFactory {
public:
	virtual dot* createDot(float _x, float _y, float _r)=0;
};

class NormalDotFactory : public AbstractDotFactory{
public:
	dot* createDot(float _x, float _y, float _r) override;
};

class BlinkingDotFactory : public AbstractDotFactory{
public:
	dot* createDot(float _x, float _y, float _r) override;
};

class TintedDotFactory : public AbstractDotFactory{
public:
	dot* createDot(float _x, float _y, float _r) override;
};

class MixedDotFactory : public AbstractDotFactory{
public:
	dot* createDot(float _x, float _y, float _r) override;
};

class BlinkingDot : public dot{
	int blinker;
public:
	BlinkingDot(float _x, float _y, float _r);

	// Override ++ operator to create the blinking effect
	void operator++() override;
};

class TintedDot : public dot{
	Color tint();
public:
	TintedDot(float _x, float _y, float _r);
};

#endif