#ifndef _HEADER_H_
#define _HEADER_H_
#include <iostream>
#include "..\..\StaticMath\MathLibrary\Header1.h"

namespace Prog2 {
	class Settings {
	private:
		std::istream& is = std::cin;
		std::ostream& os = std::cout;
		Evolv evolvent;
		void GetP();
		int chang_rad();
		bool calcul_dist();
		bool calcul_coords();
		bool calcul_lenght();
		bool calcul_curva();
		bool equation();
		bool chang_coord();


	public:
		void dialog();
		int analysis();
	


	};
	template <typename T>
	int getNum(T& a) {
		std::cin >> a;
		if (!std::cin.good()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return -1;
		}
		return 1;
	}
		
}
#endif