#pragma once
#include "template.h"

class Newtons_class
{
public:
	Newtons_class();
	~Newtons_class();

	void setVolumes(double vol_a, double vol_b);
	void setTolerance(double vol_eps);

	int count(double& x);

private:
	double a;
	double b;
	double eps;
};


