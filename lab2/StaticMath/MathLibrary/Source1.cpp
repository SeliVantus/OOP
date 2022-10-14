#include <iostream>
#include "Header1.h"
namespace Prog2 {


	Evolv::Evolv(double rad) :point(0, 0)	
	{
		if (rad < 0)
			throw std::exception("Bad radius!");
		r = rad;
	}


	void Evolv::SetRadius(double Radius) {
		if (Radius < 0) {
			throw std::exception("Bad radius");
		}
		else {
			r = Radius;
		}
	}


	void Evolv::coordinates(double f)const {
		std::cout << "x = " << r * (cos(f) + f * sin(f)) + point.x << std::endl;
		std::cout << "y = " << r * (sin(f) - f * cos(f)) + point.y << std::endl;
	}

	double Evolv::curvat(double  s) const {
		if (s <= 0) {
			throw std::exception("Bad!");
		}
		else {
			return (1 / (sqrt(2 * r * s)));
		}
	}
	
	char* Evolv::frm() const {
		char* s = new char[100];
		sprintf_s(s, 100, "x = %.2f * (cos(f) + f * sin(f)) + (%.2f)\ny = %.2f * (sin(f) - f * cos(f)) + (%.2f)\n", GetRadius(),point.x, GetRadius(), point.y);
		return s;
	}

}
