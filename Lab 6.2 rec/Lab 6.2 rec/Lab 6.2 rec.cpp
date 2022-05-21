#include <iostream>
using namespace std;

typedef int Info;
struct Elem {
    Info info;
    struct Elem* link;
    Elem(int info)
    {
        this->info = info;
        link = NULL;
    }
};

struct LinkedList {
    Elem* first,
        * last;

    LinkedList()
    {
        first = NULL;
        last = NULL;
    }

    Elem* reverse(Elem* first)
    {
        if (first == NULL || first->link == NULL)
            return first;
        // Recursive call
        Elem* rest = reverse(first->link);
        first->link->link = first;

        first->link = NULL;

        return rest;
    }

    void print(Elem* first)
    {
        Elem* temp = first;
        if (temp != NULL) {
            cout << temp->info << " ";
            temp = temp->link;
            print(temp);
        }
    }

    void enqueue(Elem*& first, Elem*& last, Info value)
    {
        Elem* tmp = new Elem(value); // 1
        tmp->info = value; // 2
        tmp->link = NULL; // 3
        if (last != NULL)
            last->link = tmp; // 4
        last = tmp; // 5
        if (first == NULL)
            first = tmp; // 6
    }

    Info dequeue(Elem*& first, Elem*& last)
    {
        Elem* tmp = first->link; // 1
        Info value = first->info; // 2
        delete first; // 3
        first = tmp; // 4
        if (first == NULL)
            last = NULL; // 5
        return value; // 6
    }
};

int main()
{
    LinkedList ll;

    for (int i = 1; i <= 10; i+=2)
        ll.enqueue(ll.first, ll.last, i);

    ll.print(ll.first);
    cout << endl;

    ll.first = ll.reverse(ll.first);

    ll.print(ll.first);
    cout << endl;

    while (ll.first != NULL)
        cout << "delete: " << ll.dequeue(ll.first, ll.last) << endl;
    cout << endl;

    return 0;
}