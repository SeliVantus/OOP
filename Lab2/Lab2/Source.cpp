#include <iostream>
#include "header.h"
#include "..\..\StaticMath\MathLibrary\Header1.h"

namespace Prog2 {
	void Settings::dialog() {
		os << "radius --> " << evolvent.GetRadius() << std::endl << "coordinates: ";  GetP(); os << std::endl << std::endl << "Settings:" << std::endl << "0: Ñhanging the radius " << std::endl << "1: Exit" << std::endl << "2: Distance to the center" << std::endl << "3: Coordinate/angle" << std::endl << "4: Arc length/angle" << std::endl << "5: Radius of curvature/length" << std::endl << "6: The equation" << std::endl << "7: chang coord " << std::endl;
 	}

	int Settings::analysis() {
		int flag = -1;

		do {
			std::cout << "Select function" << std::endl;
			if (getNum(flag) < 0) {
				os << "Input incorrect!" << std::endl;
				flag = -1;
				continue;
			}
			if (flag > 7) {
				os << "No such feature!" << std::endl;
				flag = -1;
			}

		} while (flag < 0);

		if (flag == 0) {
			return chang_rad();
		}

		if (flag == 1) {
			return 0;
		}
		if (flag == 2) {
			return calcul_dist();
		}
		if (flag == 3) {
			return calcul_coords();
		}
		if (flag == 4) {
			return calcul_lenght();
		}
		if (flag == 5) {
			return calcul_curva();
		}
		if (flag == 6) {
			return equation();
		}
		if (flag == 7) {
			return chang_coord();
		}
		return flag;

	}

	void Settings::GetP() {
		Point a = evolvent.GetPoint();
		os << "x = " << a.x << "   " << "y = " << a.y;
	}

	int Settings::chang_rad() {
		os << "New Radius -->" << std::endl;
		double a;
		if (getNum(a) > 0) {
			try {
				evolvent.SetRadius(a);
			}
			catch (const std::exception& msg) {
				os << msg.what() << std::endl;
			}
		}
		return 1;
	}

	bool Settings::calcul_dist() {
		os << "Angle ( 0 <= angle <= 2 * PI) -->" << std::endl;
		double f;
		if (getNum(f) > 0) {
			if ((f >= 0) && (f <= 2 * 3.141)) {
				os << "distance = " << evolvent.distance(f) << std::endl;
			}
			else {
				os << "Bad!" << std::endl;
			}
		}
		return 1;
	}

	bool Settings::calcul_coords() {
		os << "Angle ( 0 <= angle <= 2 * PI) -->" << std::endl;
		double f;
		if (getNum(f) > 0) {
			if ((f >= 0) && (f <= 2 * 3.141)) {
				evolvent.coordinates(f);
			}
			else {
				os << "Bad!" << std::endl;
			}
		}
		return 1;
	}

	bool Settings::calcul_lenght() {
		os << "Angle ( 0 <= angle <= 2 * PI) -->" << std::endl;
		double f;
		if (getNum(f) > 0) {
			if ((f >= 0) && (f <= 2 * 3.141)) {
				os << "lenght = " << evolvent.length(f)  << std::endl;
			}
			else {
				os << "Bad!" << std::endl;
			}
		}
		return 1;
	}

	bool Settings::calcul_curva() {
		double s;
		os << "Enter the arc length -->" << std::endl; 
		if (getNum(s) > 0) {
			try {
				os << evolvent.curvat(s) << std::endl;
			}
			catch(const std::exception& msg){
				os << msg.what() << std::endl;
			}
		}
		return 1;
	}
	bool Settings::chang_coord() {
		os << "New X -->" << std::endl << "New Y -->" << std::endl;
		Point a;
		if ((getNum(a.x) > 0) && (getNum(a.y) > 0)) {
			try {
				evolvent.SetPoint(a);
			}
			catch (const std::exception& msg) {
				os << msg.what() << std::endl;
			}
		}
		return 1;
	}



	bool Settings::equation() {
			
		os << evolvent.frm() << std::endl;

		return 1;
	}
}	