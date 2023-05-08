#include "Coin.h"
#include <iostream>

 // implement functions for managing coins; this may depend on your design.
using std::string;
//using std::vector;
 

 Coin::Coin() {
    // denom = FIVE_CENTS;
    // count = 0;
}

Coin::Coin(Denomination denomination, unsigned count) {
    this->denom = denomination;
    this->count = count;
}
