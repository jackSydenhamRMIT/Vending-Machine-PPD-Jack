#include "Node.h"

Node::Node(){
    // TODO
    data = new Stock();
    next = nullptr;
};
Node::~Node(){
    // TODO
    delete data;
};
