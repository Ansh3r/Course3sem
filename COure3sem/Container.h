#include <iostream>
#include "Item.h"

class Container 
{
private:
    Item* first;
    Item* last;
    void Swap(Item* item1, Item* item2);
public:
    bool IsThere(std::string key);
    void Add(Item& item); //���������� �������� � ��� �����
    void Add(std::string key);
    virtual Item& operator [](std::string key); //������ � �������� �� �����
    virtual Item& operator [](int index); //������ � �������� �� �������
    virtual Container& operator =(Container& value);
    Item* GetFirst() { return first; };
    Item* GetLast() { return last; };
    ~Container(); //TODO ������ ���������� ������ �� ���� ��������� ������
    Container();
    int Count();
    void Clear();
    void Remove(std::string key);
    void Print();
    void SortUp();
    void SortDown();
};
