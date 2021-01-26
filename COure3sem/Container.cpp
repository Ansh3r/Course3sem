#include <cstring>
#include "Container.h"

Item& Container::operator[](std::string key) 
{
    if (first == nullptr) 
    {
        printf("Container have nothing.\n");
        exit(0);
    }
    for (int i = 0; i < Count(); i++) 
    {
        if ((*this)[i].GetKey() == key)
            return (*this)[i];
    }

    printf("The key not found.\n");
    exit(0);
}

Item& Container::operator[](int index) 
{
    if (index < 0 || index >= Count())
    {
        printf("Incorrect index. %i\n", index);
        exit(0);
    }
    int counter = 0;
    Item* item = first;
    while (counter < index)
    {
        item = item->GetNext();
        counter++;
    }
    return *item;
}

void Container::Add(Item& item)
{
    //Если ключ добавляемого элемента уже есть в контейнере, то он не присваивает
    if (IsThere(item.GetKey())) 
    {
        printf("Element not was added. Element with this key already there.\n");
        return;
    }

    if (this->first == nullptr)
    {
        this->first = this->last = &item;
        item.SetNext(nullptr);
        item.SetPrev(nullptr);
        return;
    }
    if (Count() == 1)
    {
        this->last = &item;
        this->first->SetNext(&item);
        item.SetPrev(first);
        item.SetNext(nullptr);
        return;
    }
    this->last->SetNext(&item);
    item.SetPrev(this->last);
    item.SetNext(nullptr);
    this->last = &item;
}

Container::~Container()
{
    Clear();
}

Container::Container()
{
    this->first = nullptr;
    this->last = nullptr;
}
//Возвращает кол-во элементов в контейнере
int Container::Count()
{
    if (first == nullptr) return 0;
    if (first == last) return 1;
    Item* loc = first;
    int counter = 0;
    while (loc != nullptr) 
    {
        counter++;
        loc = loc->GetNext();
    }
    return counter;
}
//Очищает весь список
void Container::Clear() 
{
    while (Count() > 0)
        Remove(first->GetKey());
}

void Container::Remove(std::string key) 
{
    Item* item = &((*this)[key]);
    //Если удаляется один единственный элемент
    if (Count() == 1)
    {
        first = last = nullptr;
        delete item;
        return;
    }
    //Если удаляем первый элемент
    if (item == first) 
    {
        first = first->GetNext();
        first->SetPrev(nullptr);
        delete item;
        return;
    }
    //Если удаляем последний элемент
    if (item == last) 
    {
        last = last->GetPrev();
        last->SetNext(nullptr);
        delete item;
        return;
    }
    //Удаление любого другого
    item->GetPrev()->SetNext(item->GetNext());
    item->GetNext()->SetPrev(item->GetPrev());
    delete item;
}
//Вывoдит все элементы
void Container::Print() 
{
    if (first == nullptr)
    {
        printf("Container have nothing.\n");
        return;
    }
    Item* item = first;
    while (item != nullptr) 
    {
        std::cout << item->GetKey() << " ";
        item = item->GetNext();
    }
    std::cout << std::endl;
}
//Сортирует по возрастанию
void Container::SortUp()
{
    for (int i = 0; i < Count(); i++)
    {
        for (int j = 0; j < Count() - 1; j++) 
        {
            Item* item1 = &(*this)[j];
            Item* item2 = &(*this)[j + 1];
            if (item1->GetKey() > item2->GetKey()) 
            {
                Swap(item1, item2);

                if (j == 0)
                    this->first = item2;
                if (j == Count() - 1)
                    this->last = item1;
            }
        }
    }
}

//Соритует по убыванию
void Container::SortDown()
{
    for (int i = 0; i < Count(); i++) 
    {
        for (int j = 0; j < Count() - 1; j++) 
        {
            Item* item1 = &(*this)[j];
            Item* item2 = &(*this)[j + 1];
            if (item1->GetKey() < item2->GetKey()) 
            {
                Swap(item1, item2);

                if (j == 0)
                    this->first = item2;
                if (j == Count() - 1)
                    this->last = item1;
            }
        }
    }
}
//Меняет два элемента местами, с учётом смены связей каждого из них
void Container::Swap(Item* item1, Item* item2) 
{
    Item* med = item2->GetNext();
    item2->SetNext(item1);
    item1->SetNext(med);
    if (med != nullptr)
        med->SetPrev(item1);

    med = item1->GetPrev();
    item1->SetPrev(item2);
    item2->SetPrev(med);
    if (med != nullptr)
        med->SetNext(item2);
}

Container& Container::operator=(Container& value) 
{
    Container* result = new Container();
    int amountContainer = value.Count(), amountFirstCont = this->Count();
    for (int i = 0; i < amountContainer; i++)
    {
        if (i < amountFirstCont) 
        {
            Item med = (*this)[i];
            result->Add(med.GetKey());
        }
        else {
            Item med = value[i];
            result->Add(med.GetKey());
        }
    }
    Clear();
    first = result->first;
    last = result->last;
    return *this;
}
//Добавляет элемент по ключу, то есть создаёт новый с полученным ключом
void Container::Add(std::string key) 
{
    Item* item = new Item(key);
    this->Add(*item);
}

bool Container::IsThere(std::string key) 
{
    if (first == nullptr) 
    {
        return false;
    }
    for (int i = 0; i < Count(); i++)
    {
        if ((*this)[i].GetKey() == key)
            return true;
    }
    return false;
}
