#pragma once
#include "template.h"

class Dyhotomia_class
{
public:
	Dyhotomia_class();
	~Dyhotomia_class();

	void setVolumes(double vol_a, double vol_b);
	void setTolerance(double vol_eps);

	double F(double x);

	int count(double& x);

private:
	double a;
	double b;
	double eps;
};

