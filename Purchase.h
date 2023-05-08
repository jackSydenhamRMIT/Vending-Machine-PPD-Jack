#ifndef PTRCHASE_H
#define PTRCHASE_H
#include "LinkedList.h"

class Purchase
{
private:
    LinkedList & m_lst;
    //Get the amount entered by the user
    std::string get_cin(bool a = true);

public:
    Purchase(LinkedList & lst);

    void purchase_room();

    ~Purchase();

    int face_value[10] = {1000,500,200,100,50,20,10,5};
};

#endif // PTRCHASE_H