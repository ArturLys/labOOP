#include "Dyhotomia_class.h"
#include "Newtons_class.h"

using namespace std;

auto F = [](double x) {
	double tan_x = tan(x);
	return tan_x - (pow(tan_x, 3) + 1) / 3 + 0.2 * pow(tan_x, 5);
};

int32_t main() {
	double a = 0, b = 0.8, eps = 0.0000001;
	//cout << "a b eps: ";
	//cin >> a, b, eps;

	cout << "-=Dyhotomia method=-\n";

	Dyhotomia_class* dyh = new Dyhotomia_class();

	double x = 0;

	dyh->setVolumes(a, b);
	dyh->setTolerance(eps);

	int err = dyh->count(x);

	if (err == 0) {
		cout << "x = " << x << "\n";
	}
	else {
		cout << "no solution found\n";
	}
	cout << F(x);

	delete dyh;

	cout << "\n-=Newton's method=-\n";

	x = 800;

	Newtons_class* newt = new Newtons_class();

	newt->setVolumes(a, b);
	newt->setTolerance(eps);

	int err2 = newt->count(x);

	if (err2 == 0) {
		cout << "x = " << x << "\n";
	}
	else {
		cout << "x = " << x << "\n";
		cout << "no solution found\n";
	}

	cout << F(x);

	delete newt;
}
