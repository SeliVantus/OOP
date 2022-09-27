#include <iostream>
#include "Header.h"

using namespace Moe;

int main()
{
	Matrix arr;
	Matrix New;
	int a = 0;
	do {
		if (input(arr)) {
			std::cout << "You made a mistake!\n Please repeat again" << std::endl;
		}
		else {
			a = 2;
		}
	} while (a < 1);

	output(arr);
	Change(arr, New);
	output(New);
	//remove(arr);

	return 0;
}