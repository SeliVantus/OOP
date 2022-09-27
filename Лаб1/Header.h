#pragma once
#ifndef HEADER_H
#include <iostream>

namespace Moe {

	struct Matrix {
		int m;
		int n;
		int Quantity;
		int* x_k;
		int* y_k;
		int* values;
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

	int input(Matrix&);
	void output(Matrix);
	int Change(Matrix , Matrix & );
}
#endif