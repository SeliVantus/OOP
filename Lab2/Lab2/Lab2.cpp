
#include <iostream>
#include "header.h"
using namespace Prog2;

int main(){
    Settings settin;
    do {
        settin.dialog();

    } while (settin.analysis());
  
    return 0;
}

