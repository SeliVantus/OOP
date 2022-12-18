#include <iostream>
#include "Header.h"
using namespace Prog3;

int main() {
    Settings settin;
    do {
        settin.dialog();

    } while (settin.analysis());

    return 0;
}
