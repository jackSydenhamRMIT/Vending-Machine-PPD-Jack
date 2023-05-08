#include "LinkedList.h"
#include <iostream>
#include <iomanip>
using std::string;
//using std::vector;



LinkedList::LinkedList() {
   head = nullptr;
   count = 0;
   // TODO
}

LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current->data;
        delete current;
        current = nextNode;
    }
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

void LinkedList::displayItems() {
    Node* current = head;
    while (current != nullptr) {
        Stock* stock = current->data;
        std::cout << stock->id << "|" 
                  << std::left << std::setw(35) << stock->name << "|"
                  << std::left << std::setw(10) << stock->on_hand << "|"
                  << "$" << stock->price.dollars << "." << std::setw(2) << std::setfill('0') << stock->price.cents << std::setfill(' ')
                  << std::endl;
        current = current->next;
    }
}

void LinkedList::addStock(const std::string& id, const std::string& name, const std::string& desc, int dollars, int cents, int onHand) {
    
    // Create new Stock object with given parameters
    Stock* stock = new Stock;
    stock->id = id;
    stock->name = name;
    stock->description = desc;

    // Initialize the price with the given dollars and cents
    stock->price.dollars = dollars;
    stock->price.cents = cents;

    stock->on_hand = onHand;

    // Create a new node in the linked-list
    Node* newNode = new Node;
    newNode->data = stock;
    newNode->next = nullptr;

    // Place the new node in the linked-list
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* currNode = head;
        while (currNode->next != nullptr) {
            currNode = currNode->next;
        }
        currNode->next = newNode;
    }

    // Increment the count of items stocked (linked-list size)
    count++;
}



bool LinkedList::removeStock(const std::string& id) {
    if (head == nullptr) {
        return false; // Nothing to remove
    }

    if (head->data->id == id) {
        // The stock to remove is at the list head
        Node* nodeToRemove = head;
        head = head->next;
        delete nodeToRemove->data;
        delete nodeToRemove;
        count--;
        return true;
    }

    // Find stock object with given stock ID
    Node* currNode = head;
    while (currNode->next != nullptr && currNode->next->data->id != id) {
        currNode = currNode->next;
        if (currNode == nullptr) {
            return false; // Stock not found
        }
    }

    if (currNode->next == nullptr) {
        return false; // Stock not found
    }

    // Remove the specific stock object from the list
    Node* nodeToRemove = currNode->next;
    currNode->next = nodeToRemove->next;
    delete nodeToRemove->data;
    delete nodeToRemove;
    count--;
    return true;
}



Stock* LinkedList::find_node(std::string ID)
{
    Node *new_p = head;
    while(new_p != NULL)
    {
        if(new_p->data->id == ID)
            return new_p->data;
        new_p = new_p->next;
    }
    return nullptr;
}

int LinkedList::get_coin(int cn)
{
    return 1;
}
