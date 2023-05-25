#include "LinkedList.h"
#include <iostream>
#include <iomanip>
using std::string;
//using std::vector;

bool COLOUR;
bool HELP;

// Enable/disable coloured text for minor enhancement 
void LinkedList::changeColourVariable(){
    COLOUR = !(COLOUR);
}

// Enable/disable coloured text for minor enhancement 
void LinkedList::changeHelpVariable(){
    HELP = !(HELP);
}

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
//     Node* current = head;
//     while (current != NULL) {
//     Stock* stock = current->data;
//     std::cout << "ID: " << stock->id << std::endl;
//     std::cout << "Name: " << stock->name << std::endl;
//     std::cout << "Description: " << stock->description << std::endl;
//     std::cout << "Price: $" << stock->price.dollars << "." << stock->price.cents << std::endl;
//     std::cout << "On Hand: " << stock->on_hand << std::endl;
//     std::cout << std::endl;
//     current = current->next;
// }

}
void LinkedList::loadCoinsData(const char* filename) {  
    std::ifstream coinsFile(filename);
    if (!coinsFile.is_open()) {
        std::cerr << "Error: could not open stock file." << std::endl;
        exit(EXIT_FAILURE);
    } 

    std::string line;
    while (std::getline(coinsFile, line)) {
        std::istringstream iss(line);
        Coin* coin = new Coin;
        std::string denom_str;
        if (std::getline(iss, denom_str, ',')) {
            
            if(denom_str == "5"){
                coin->denom = FIVE_CENTS;
            }
            else if (denom_str == "10"){
                coin->denom = TEN_CENTS;
            }
            else if (denom_str == "20"){
                coin->denom = TWENTY_CENTS;
            }
            else if (denom_str == "50"){
                coin->denom = FIFTY_CENTS;
            }
            else if (denom_str == "100"){
                coin->denom = ONE_DOLLAR;
            }
            else if (denom_str == "200"){
                coin->denom = TWO_DOLLARS;
            }
            else if (denom_str == "500"){
                coin->denom = FIVE_DOLLARS;
            }
            else if (denom_str == "1000"){
                coin->denom = TEN_DOLLARS;
            }
            else{
                coin->denom = FIVE_CENTS;
            }        
                         
        }

        std::string count_str;
        if (std::getline(iss, count_str, ',')) {
            coin->count = std::stoi(count_str);
        }

        Node* currNode = head;
        while (currNode != nullptr) {
            if (currNode->data1->denom == coin->denom) {
                currNode->data1->count += coin->count;
                delete coin;
            }

            currNode = currNode->next;
        }

        if (currNode == nullptr) {
            Node* newNode = new Node;
            newNode->data1 = coin;
            newNode->next = nullptr;
            //std::cout << coin->count << coin->denom << std::endl;

            if (head == nullptr) {
                head = newNode;
            } else {
                Node* currNode = head;
                while (currNode->next != nullptr) {
                    currNode = currNode->next;
                }
                currNode->next = newNode;
            }

        }
    }
}
Stock* LinkedList::find_node(std::string ID)
{
    Stock* result = nullptr;
    Node *new_p = head;
    while(new_p != NULL && result == nullptr)
    {
        if(new_p->data->id == ID)
            result = new_p->data;
        new_p = new_p->next;
    }
    return result;
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
void LinkedList::use_coin(int cn) {
    if (m_coins.find(cn) != m_coins.end()) {
        m_coins[cn].count--;
    }
}


void LinkedList::saveStockData(const char* filename){
    std::ofstream stockFile(filename);
    if(!stockFile){
        std::cerr << "Error: could not open file for writing." << std::endl;
        EXIT_FAILURE;
    }

    Node* current = head;
    while (current != NULL){
        Stock* stock = current->data;
        stockFile << stock->id << "|" << stock->name << "|" << stock->description << "|" << stock->price.dollars
        << "." << stock->price.cents << "|" << stock->on_hand << std::endl;
        current = current->next;
    }
    stockFile.close();

}

void LinkedList::saveCoinsData(const char* filename){
    std::ofstream coinsFile(filename);
    if(!coinsFile){
        std::cerr << "Error: could not open file for writing." << std::endl;
        EXIT_FAILURE;
    }
   
    Node* current = head;
    while (current != NULL){
        Coin* coin = current->data1;
        //make denom from enumerations to character types
        string denom = "";
        if(coin->denom == FIVE_CENTS){
            denom = "5";
        }else if (coin->denom == TEN_CENTS)
        {
            denom = "10";
        }else if (coin->denom == TWENTY_CENTS)
        {
            denom = "20";
        }else if (coin->denom == FIFTY_CENTS)
        {
            denom = "50";
        }else if (coin->denom == ONE_DOLLAR)
        {
            denom = "100";
        }else if (coin->denom == TWO_DOLLARS)
        {
            denom = "200";
        }else if (coin->denom == FIVE_DOLLARS)
        {
            denom = "500";
        }else if (coin->denom == TEN_DOLLARS)
        {
            denom = "1000";
        }
        coinsFile << denom << "," << coin->count << std::endl;
        current = current->next;
    }
    coinsFile.close();

}

void LinkedList::freeMemory(){
    Node* current = head;
    while (current != nullptr){
        Node* next = current->next;
        if (current->data != nullptr)
        {
            delete current->data;
            delete current->data1;
            current->data = nullptr;
        }
        delete current;
        current = next;
        
    }
    head = nullptr;
    count = 0;
    
}


void LinkedList::change_coin(int cn)
{
    if (m_coins.find(cn) != m_coins.end()) {
        m_coins[cn].count++;
    }
}


void LinkedList::displayCoins(LinkedList& coinList){


    int fiveCents = 0;
    int tenCents = 0;
    int twentyCents = 0;
    int fiftyCents = 0;
    int oneDollar = 0;
    int twoDollar = 0;
    int fiveDollar = 0;
    int tenDollar = 0;


    Node* current = coinList.getHead();
            while (current != NULL) {
                Coin* coin = new Coin(current->data1->denom, current->data1->count); 
 
                //std::cout << "Passed denom: " << coin->denom << " Passed count: " << coin->count << std::endl;
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

                // switch (Denomination){

                //     case FIVE_DOLLARS:
                        
                // }
                current = current->next;

                
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


int LinkedList::get_coin(int cn)
{
    return 1;
}

Node* LinkedList::getHead(){
    return head;
}

void LinkedList::removeItem(string itemID){
    Node* current = head;
    Node* previous = nullptr;
    while (current != nullptr)
    {
        if (current->data->id == itemID)
        {
            if (previous == nullptr)
            {
                head = current->next;
            }else{
                previous->next = current->next;
            }
            count--;
            return;
        }
        previous = current;
        current = current->next;    
    }
    
}
