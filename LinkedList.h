#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"


class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    void loadStockData(const char* filename);
    void loadCoinsData(const char* filename);
    void addStock(const std::string& id, 
                  const std::string& name, 
                  const std::string& desc, 
                  const Price& price, 
                  unsigned onHand);
    bool removeStock(const std::string& id);



    // more functions to be added perhaps...
    Stock*  find_node(std::string ID);
    int get_coin(int cn);

private:
    // the beginning of the list
    Node* head;
  
    // how many nodes are there in the list?
    unsigned count;
};

#endif  // LINKEDLIST_H


