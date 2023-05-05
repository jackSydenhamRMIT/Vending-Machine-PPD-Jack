#include "LinkedList.h"
#include <iostream>
using std::string;
//using std::vector;



LinkedList::LinkedList() {
   head = nullptr;
   count = 0;
   // TODO
}

LinkedList::~LinkedList() {
    // TODO
}


void LinkedList::loadStockData(const char* filename) {
    std::ifstream stockFile(filename);
    if (!stockFile.is_open()) {
    std::cerr << "Error: could not open stock file." << std::endl;
    EXIT_FAILURE;
    }
    std::string line;
    while (std::getline(stockFile, line)) {
        std::istringstream iss(line);
        std::string id, name, desc, priceStr, onHandStr;
        if (!(std::getline(iss, id, '|') && std::getline(iss, name, '|') &&
              std::getline(iss, desc, '|') && std::getline(iss, priceStr, '|') &&
              std::getline(iss, onHandStr))) {
            std::cerr << "Error: Unable to parse line: " << line << std::endl;
        }

        // Convert price and onHand to their respective types
        std::stringstream ssPrice(priceStr);
        Price price;
        ssPrice >> price.dollars;
        ssPrice.ignore();
        ssPrice >> price.cents;

        std::stringstream ssOnHand(onHandStr);
        unsigned onHand = 0;
        ssOnHand >> onHand;

        // Create new Stock object and add to linked list
        Stock* stock = new Stock;
        stock->id = id;
        stock->name = name;
        stock->description = desc;
        stock->price = price;
        stock->on_hand = onHand;

        Node* newNode = new Node;
        newNode->data = stock;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* currNode = head;
            while (currNode->next != nullptr) {
                currNode = currNode->next;
            }
            currNode->next = newNode;
        }

        count++;
    }
    //test for print
    Node* current = head;
    while (current != NULL) {
    Stock* stock = current->data;
    std::cout << "ID: " << stock->id << std::endl;
    std::cout << "Name: " << stock->name << std::endl;
    std::cout << "Description: " << stock->description << std::endl;
    std::cout << "Price: $" << stock->price.dollars << "." << stock->price.cents << std::endl;
    std::cout << "On Hand: " << stock->on_hand << std::endl;
    std::cout << std::endl;
    current = current->next;
}

}
void LinkedList::loadCoinsData(const char* filename){  
    std::ifstream coinsFile(filename);
    if (!coinsFile.is_open()) {
    std::cerr << "Error: could not open stock file." << std::endl;
    EXIT_FAILURE;
    } 
    std::string line;
        while (std::getline(coinsFile, line)) {
            std::istringstream iss(line);
            Coin coin;
            std::string denom_str;
            if (std::getline(iss, denom_str, ',')) {
                coin.denom = static_cast<Denomination>(std::stoi(denom_str));
            }

            std::string count_str;
            if (std::getline(iss, count_str, ',')) {
                coin.count = std::stoi(count_str);
            }
            //test print
            std::cout << coin.denom << std::endl;
            std::cout << coin.count << std::endl;
            
        }
    

}
    
void Stock::ResetStock(Stock* stock){

    //loops through linkedlist
    //sets all stock::on_hand values to DEFAULT_STOCK_LEVEL 20

    std::cout << "“All stock has been reset to the default level of " << DEFAULT_STOCK_LEVEL << "”" << std::endl;
}


void Coin::ResetCoins(Coin* coin){

    //resets coins to correct denomination
    //DEFAULT_COIN_COUNT 20

    std::cout << "“All coins has been reset to the default level of " << DEFAULT_COIN_COUNT << "”" << std::endl;
}



