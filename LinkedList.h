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

    void addStock(const std::string& id, 
                  const std::string& name, 
                  const std::string& desc, 
                  const int dollars, 
                  const int cents, 
                  int onHand);
    void displayItems();



    // more functions to be added perhaps...
    void removeItem(std::string ID);
    void saveStockData(const char* filename);
    void saveCoinsData(const char* filename);
    void freeMemory();

    // more functions to be added perhaps...
    //Get product information node
    Stock*  find_node(std::string ID);
    //Get the money information
    int get_coin(int cn);
    // Use money
    void use_coin(int cn);
    //Change money
    void change_coin(int cn);


    void display_coin()
    {
        for(auto o:m_coins)
        std::cout<<o.second.denom<<" - "<<o.second.count<<"\n";
    }

    Node* getHead();

    void displayCoins(LinkedList& coinList);


private:
    // the beginning of the list
    Node* head;
  
    // how many nodes are there in the list?
    unsigned count;
    std::map<int,Coin> m_coins;
};

#endif  // LINKEDLIST_H


