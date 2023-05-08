#include "Node.h"
#include <iostream>
using std::string;
//using std::vector;

Node::Node(){
    // TODO
    data = new Stock();
    next = nullptr;
};
Node::~Node(){
    // TODO
   delete data;

};

void Stock::ResetStock(Stock* stock){

    //loops through linkedlist
    //sets all stock::on_hand values to DEFAULT_STOCK_LEVEL 20

    stock->on_hand = DEFAULT_STOCK_LEVEL;

}

void Coin::ResetCoins(Coin* coin){

    //resets coins to correct denomination
    //DEFAULT_COIN_COUNT 20

    coin->count = DEFAULT_COIN_COUNT;
    

}

   
