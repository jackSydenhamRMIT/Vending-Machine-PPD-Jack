#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include <map>

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    void loadStockData(const char* filename);
    void loadCoinsData(const char* filename);

    // more functions to be added perhaps...
    Stock*  find_node(std::string ID);
    Coin get_coin(int cn);

    void use_coin(int cn);

private:
    // the beginning of the list
    Node* head;
  
    // how many nodes are there in the list?
    unsigned count;
    std::map<int,Coin> m_coins;
};

#endif  // LINKEDLIST_H


