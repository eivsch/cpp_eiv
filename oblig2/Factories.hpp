#ifndef CLASS_FACTORIES_H
#define CLASS_FACTORIES_H

#include "dot.hpp"

class AbstractDotFactory {
public:
	virtual dot* createDot(float _x, float _y, float _r)=0;
};

/** Creates standard colored dots */
class NormalDotFactory : public AbstractDotFactory{
public:
	dot* createDot(float _x, float _y, float _r) override;
};

/** Creates white dots with blinking effect */
class BlinkingDotFactory : public AbstractDotFactory{
public:
	dot* createDot(float _x, float _y, float _r) override;
};

/** Create dots with a predefined tint */
class TintedDotFactory : public AbstractDotFactory{
public:
	dot* createDot(float _x, float _y, float _r) override;
};

/** Creates a different dot-type for each call on createDot() */
class MixedDotFactory : public AbstractDotFactory{
	int mixer{0};		// Counting variable
public:
	dot* createDot(float _x, float _y, float _r) override;
};

class NormalDot : public dot{
public:
	NormalDot(float _x, float _y, float _r);
};

class BlinkingDot : public dot{
	int blinker{0};		// Counting variable
public:
	BlinkingDot(float _x, float _y, float _r);

	// Override ++ operator to create the blinking effect
	void operator++() override;
};

class TintedDot : public dot{
	// Define and return tint
	Color tint();
public:
	TintedDot(float _x, float _y, float _r);
};

#endif