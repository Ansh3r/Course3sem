#include "Container.h"
#include <iostream>

using namespace std;

int menu(Container& container);

int main() 
{
    setlocale(LC_ALL, "Russian");
    Container cont;
    while (menu(cont) != 0);
    return 0;
}

int menu(Container& container) 
{
    cout << "1. Added item;" << endl
        << "2. Remove item;" << endl
        << "3. Show amount elements of container;" << endl
        << "4. Clear container;" << endl
        << "5. Print all elements of container;" << endl
        << "6. Sort ascending;" << endl //Соритровка по возрастанию
        << "7. Sort descending;" << endl //Сортировка по убыванию
        << "8. Attach container;" << endl //Присвоение контейнера
        << "0. Exit." << endl;
    int action = 0;
    try 
    {
        cin >> action;
        switch (action) 
        {
        case 1: {
            string key;
            cout << "All elements: ";
            container.Print();
            cout << "Enter key to add: ";
            cin >> key;
            container.Add(key);
            return action;
        }
        case 2: 
        {
            string key;
            cout << "All elements: ";
            container.Print();
            cout << "Enter key to remove: ";
            cin >> key;
            if (!container.IsThere(key)) 
            {
                printf("The key not found.\n");
                return action;
            }
            container.Remove(key);
            return action;
        }
        case 3: 
        {
            cout << "Amount elements is " << container.Count() << endl;
            return action;
        }
        case 4: 
        {
            container.Clear();
            return action;
        }
        case 5: 
        {
            container.Print();
            return action;
        }
        case 6: 
        {
            cout << "Before sorting: ";
            container.Print();
            container.SortUp();
            cout << "After sorting: ";
            container.Print();
            return action;
        }
        case 7: 
        {
            cout << "Before sorting: ";
            container.Print();
            container.SortDown();
            cout << "After sorting: ";
            container.Print();
            return action;
        }
        case 8: 
        {
            Container* loc = new Container();
            int pick = 0;
            cout << "Create container to attach." << endl;
            while (menu(*loc) != 0);
            cout << "First container: ";
            container.Print();
            cout << "Second container: ";
            loc->Print();
            cout << "Chose action:\n1.Attach first to second\n2.Attach second to first." << endl;
            cin >> pick;
            if (pick != 1 && pick != 2) pick = 1;
            if (pick == 1) 
            {
                container = *loc;
                cout << "Before attaching: ";
                container.Print();
            }
            else
            {
                *loc = container;
                cout << "Before attaching: ";
                loc->Print();
            }
            return action;
        }
        case 0: 
        {
            return action;
        }
        default:
            return 9;
        }
    }
    catch (exception ex) 
    {
        cout << "Happened " << ex.what() << endl;
    }
}