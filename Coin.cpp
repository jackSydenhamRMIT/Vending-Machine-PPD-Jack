#include "Coin.h"
#include <iostream>

 // implement functions for managing coins; this may depend on your design.
using std::string;
//using std::vector;

 

 Coin::Coin() {
    denom = FIVE_CENTS;
    count = 0;
}

Coin::Coin(Denomination denomination, unsigned count) {
    denom = denomination;
    this->count = count;
}

void Coin::display(Coin* coin){

    int fiveCents = 0;
    int tenCents = 0;
    int twentyCents = 0;
    int fiftyCents = 0;
    int oneDollar = 0;
    int twoDollar = 0;
    int fiveDollar = 0;
    int tenDollar = 0;

    if (coin->denom == FIVE_CENTS){
        fiveCents = coin->count;
    }
    else if (coin->denom == TEN_CENTS){
        tenCents = coin->count;
    }
    else if (coin->denom == TWENTY_CENTS){
        twentyCents = coin->count;
    }
    else if (coin->denom == FIFTY_CENTS){
        fiftyCents = coin->count;
    }
    else if (coin->denom == ONE_DOLLAR){
        oneDollar = coin->count;
    }
    else if (coin->denom == TWO_DOLLARS){
        twoDollar = coin->count;
    }
    else if (coin->denom == FIVE_DOLLARS){
        fiveDollar = coin->count;
    }
    else if (coin->denom == TEN_DOLLARS){
        tenDollar = coin->count;
    }
    
    

    std::cout << "Coin Summary" << std::endl;
    std::cout << "-------------" << std::endl;
    std::cout << "Denomination | Count" << std::endl;    
    std::cout << "---------------------------" << std::endl;    
    std::cout << "5 Cents      |" << fiveCents << std::endl;  
    std::cout << "10 Cents     |" << tenCents << std::endl;  
    std::cout << "20 Cents     |" << twentyCents << std::endl;  
    std::cout << "50 Cents     |" << fiftyCents << std::endl;  
    std::cout << "1 Dollar     |" << oneDollar << std::endl;  
    std::cout << "2 Dollar     |" << twoDollar << std::endl;
    std::cout << "5 Dollar     |" << fiveDollar << std::endl;
    std::cout << "10 Dollar    |" << tenDollar << std::endl;
}