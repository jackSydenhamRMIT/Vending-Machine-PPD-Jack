#include "Coin.h"

 Coin::Coin() {
    denom = FIVE_CENTS;
    count = 0;
}

Coin::Coin(Denomination denomination, unsigned count) {
    denom = denomination;
    this->count = count;
}
 
 // implement functions for managing coins; this may depend on your design.
