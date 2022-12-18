#include <iostream>
#include "Lab4.h"
using namespace Prog4;

int main() {
    Manager settin;
    do {
        settin.dialog();

    } while (settin.analysis());

    return 0;
}
