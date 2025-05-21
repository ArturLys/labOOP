#include "Dyhotomia_class.h"
using namespace std;

Dyhotomia_class::Dyhotomia_class() {}
Dyhotomia_class::~Dyhotomia_class() {}

void Dyhotomia_class::setVolumes(double vol_a, double vol_b) {
	a = vol_a;
	b = vol_b;
}

void Dyhotomia_class::setTolerance(double vol_eps) {
	eps = vol_eps;
}

double Dyhotomia_class::F(double x) {
	return tan(x) - (pow(tan(x), 3) + 1) / 3 + 0.2 * pow(tan(x), 5);
}

int Dyhotomia_class::count(double& x) {
	double m;

	while (fabs(b-a) >= eps) {
		m = a + (b - a) / 2;
		if (F(m) == 0) {
			x = m;
			return 0;
		}
		else if (F(m) * F(a) < 0) {
			b = m;
		}
		else {
			a = m;
		}
	}

	x = a + (b - a) / 2;
	return 0;
}
