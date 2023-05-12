#ifndef PTRCHASE_H
#define PTRCHASE_H
#include "LinkedList.h"
#include "Cin.h"
class Purchase
{
private:
    LinkedList & m_lst;
    LinkedList & m_coin;
    Cin & m_in;
    Display &m_put;

public:
    //Get the input product information
    std::string get_cin(bool a = true);
    Purchase(LinkedList & lst,LinkedList & coin,Cin &in,Display &put);

    void purchase_room();

    ~Purchase();

    int face_value[10] = {1000,500,200,100,50,20,10,5};
};

#endif // PTRCHASE_H
