#include "Item.h"
Item::Item() 
{
    this->key = "";
    this->prev = nullptr;
    this->next = nullptr;
}

Item::Item(std::string k) 
{
    this->key = k;
    this->next = nullptr;
    this->prev = nullptr;
}
