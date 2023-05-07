#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include "Coin.h"
#include <map>

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    void loadStockData(const char* filename);
    void loadCoinsData(const char* filename);
    void saveStockData(const char* filename);
    void saveCoinsData(const char* filename);
    void freeMemory();

    // more functions to be added perhaps...
    //Get product information node
    Stock*  find_node(std::string ID);
    //Get the money information
    Coin get_coin(int cn);
    // Use money
    void use_coin(int cn);

    Node* getHead();

private:
    // the beginning of the list
    Node* head;
  
    // how many nodes are there in the list?
    unsigned count;
    std::map<int,Coin> m_coins;
};

#endif  // LINKEDLIST_H


