#pragma once
#include "..\..\Library3b\Library3b\Lab.Header.h"

namespace Prog3 {
	class Settings {
	private:
		std::istream& is = std::cin;
		std::ostream& os = std::cout;
		Ternary_Vector Tvector;
		//Ternary_Vector Tvector2;
		//Ternary_Vector Tvector3;
		//bool size_change();
		bool V1_change();
		bool Logical_ILI();
		bool Logical_I();
		bool Logical_campare();
		bool invertor();
		bool Analisys();
		bool Input();
		bool Output();
		void Getter();
		bool Plus_Equal();
		bool Plus();
		bool Equal();
		bool plus_pref();
		bool post_plus();
		bool Tilda();
		bool Equal_Equal();
		bool A_Bi();
		bool Bi_A();


	public:
		void dialog();
		int analysis();
	};
	template <class T>
	int getNum(T& a) {
		std::cin >> a;
		if (!std::cin.good() || (std::cin.peek() != '\n')) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return -1;
		}
		return 1;
	}

}