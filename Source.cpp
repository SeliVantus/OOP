#include <iostream>
#include "Header.h"


namespace Moe {
	int input(Matrix& arr) {
		const char* pr = "";
		arr.m = 0;
		arr.n = 0;
		int Quantity;
		do {
			std::cout << pr << std::endl;
			std::cout << "Enter number of lines: --> ";
			pr = "You are wrong; repeat please!";
			if (getNum(arr.m) < 0)
				return 1;
		} while (arr.m < 1);
		pr = "";
		do {
			std::cout << "Enter number of columns: --> ";
			pr = "You are wrong; repeat please!";
			if (getNum(arr.n) < 0)
				return 1;
		} while (arr.n < 1);
		pr = "";
		do {
			std::cout << pr << std::endl;
			std::cout << "Enter the number of elements: --> ";
			pr = "You are wrong; repeat please!";
			if (getNum(Quantity) < 0)
				return 1;
			if (Quantity > arr.m * arr.n) {
				return 1;
			}
		} while (Quantity < 0);
		if (Quantity == 0)
			return 1;


		try {
			arr.x_k = new int[Quantity];
		}
		catch (std::bad_alloc& ba) {
			std::cout << ba.what() << std::endl;
			return 1;
		}
		try {
			arr.y_k = new int[Quantity];
		}
		catch (std::bad_alloc& ba) {
			std::cout << ba.what() << std::endl;
			delete[] arr.x_k;
			return 1;
		}
		try {
			arr.values = new int[Quantity];
		}
		catch (std::bad_alloc& ba) {
			std::cout << ba.what() << std::endl;
			delete[] arr.x_k;
			delete[] arr.y_k;
			return 1;
		}
		for (int i = 0; i < Quantity; i++) {

			int tmp_x_c = -1;
			int tmp_y_c = -1;
			int tmp_num;
			do {
				std::cout << "Enter x and y coordinate --> " << std::endl;
				if ((getNum(tmp_x_c) < 0) || (getNum(tmp_y_c) < 0)) {
					std::cout << "Try to enter the number correctly again" << std::endl;
					tmp_x_c = -1;
					tmp_y_c = -1;
					continue;
				}

				if ((tmp_x_c > arr.m - 1) || (tmp_x_c < 0) || (tmp_y_c > arr.n - 1) || (tmp_y_c < 0)) {
					std::cout << "Try to enter the number correctly again" << std::endl;
					tmp_x_c = -1;
					tmp_y_c = -1;
				}
			} while ((tmp_x_c < 0) || (tmp_y_c < 0));

			do {
				std::cout << "Enter number --> " << std::endl;
			} while (getNum(tmp_num) < 0);
			for (int j = 0; j < i; j++) {
				if ((tmp_x_c == arr.x_k[j]) && (tmp_y_c == arr.y_k[j])) {
					i--;
					std::cout << "1 oshibka i ty oshibsya" << std::endl;
					continue;
				}
			}
			if (tmp_num == 0) {
				i--;
				continue;
			}
			if (tmp_num != 0) {
				arr.x_k[i] = tmp_x_c;
				arr.y_k[i] = tmp_y_c;
				arr.values[i] = tmp_num;
			}
		}
		arr.Quantity = Quantity;
		return 0;
	}

	void output(Matrix arr) {
		std::cout << "Matrix: -->" << std::endl;
		for (int i = 0; i < arr.Quantity; i++) {
			std::cout << arr.x_k[i] << ",  ";
		}
		std::cout << std::endl;
		for (int i = 0; i < arr.Quantity; i++) {
			std::cout << arr.y_k[i] << ",  ";
		}
		std::cout << std::endl;
		for (int i = 0; i < arr.Quantity; i++) {
			std::cout << arr.values[i] << ",  ";
		}
		std::cout << std::endl << std::endl;
	}



	int Change(Matrix arr, Matrix & New) {
		New.m = arr.m;
		New.n = arr.n;
		try {
			New.x_k = new int[arr.Quantity];
		}
		catch (std::bad_alloc& ba) {
			std::cout << ba.what() << std::endl;
			return 1;
		}
		try {
			New.y_k = new int[arr.Quantity];
		}
		catch (std::bad_alloc& ba) {
			std::cout << ba.what() << std::endl;
			delete[] New.x_k;
			return 1;
		}
		try {
			New.values = new int[arr.Quantity];
		}
		catch (std::bad_alloc& ba) {
			std::cout << ba.what() << std::endl;
			delete[] New.x_k;
			delete[] New.y_k;
			return 1;
		}

		int* tmp_masx;
		int* tmp_masy;
		int* tmp_val;
		int ryad = 0;
		try {
			tmp_masx = new int[arr.Quantity];
		}
		catch (std::bad_alloc& ba) {
			std::cout << ba.what() << std::endl;
			return 1;
		}
		try {
			tmp_masy = new int[arr.Quantity];
		}
		catch (std::bad_alloc& ba) {
			std::cout << ba.what() << std::endl;
			delete[] tmp_masx;
			return 1;
		}
		try {
			tmp_val = new int[arr.Quantity];
		}
		catch (std::bad_alloc& ba) {
			std::cout << ba.what() << std::endl;
			delete[] tmp_masx;
			delete[] tmp_masy;
			return 1;
		}
		int count2 = 0;
		for (int count2 = 0; count2 < arr.m; count2++) {
			int count3 = 0;
			for (int i = 0; i < arr.Quantity; i++) {
				if (arr.x_k[i] == count2) {
					tmp_masx[count3] = arr.x_k[i];
					tmp_masy[count3] = arr.y_k[i];
					tmp_val[count3] = arr.values[i];
					count3++;
				}
			}
			if (count3 == 0) {
				continue;
			}
			int a = 0;
			for (int h = 0; h < count3; h++) {
				int zamena = tmp_val[h];
				while (zamena > 0) {
					zamena = zamena / 10;
					a++;
				}

			}
			a = a / count3;
			for (int j = 0; j < count3; j++) {
				int b = 0;
				int zamena = tmp_val[j];
				while ((zamena) > 0) {
					zamena = zamena / 10;
					b++;
				}
					
				if (b > a) {
					New.x_k[ryad] = tmp_masx[j];
					New.y_k[ryad] = tmp_masy[j];
					New.values[ryad] = tmp_val[j];
					ryad++;
				}
				
			}
		}
		New.Quantity = ryad;
		return 0;
	}

}

