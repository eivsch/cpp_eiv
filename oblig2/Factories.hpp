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
	//~BlinkingDotFactory() override;
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
	int r, g, b;
public:
	BlinkingDot(float _x, float _y, float _r);
};

#endif