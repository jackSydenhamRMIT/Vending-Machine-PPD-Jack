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


   
