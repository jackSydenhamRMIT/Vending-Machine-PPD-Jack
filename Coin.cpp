#include "Coin.h"
#include <iostream>
 // implement functions for managing coins; this may depend on your design.
using std::string;
using std::vector;

 

Coin::Coin()
{

}

void Coin::display(){
    int fiveCents = 5;
    int tenCents = 19;
    int twentyCents = 25;
    int fiftyCents = 40;
    int oneDollar = 12;
    int twoDollar = 30;
    int fiveDollar = 3;
    int tenDollar = 45;

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