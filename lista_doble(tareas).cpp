#include <iostream>
#include <ostream>

using namespace std;

class Node
{
private:
    int data;
    Node *prev;
    Node *next;

    friend class LinkedList;
};

class LinkedList
{
    public:
        LinkedList();  //Constructor
        ~LinkedList(); //Destructor
        int getFront() const;
        int getBack() const;
        void addFront(int dt);
        void addBack(int dt);
        void removeFront();
        void removeBack();
        void printReverse();
        void printForward();

private:
    Node *header;
    Node *trailer;
};

LinkedList::LinkedList()
{
    header = new Node;
    trailer = new Node;
    header->next = trailer;
    trailer->prev = header;
    header->prev = NULL;
    trailer->next = NULL;
}
int LinkedList::getFront() const
{
    return trailer->next->data;
}
int LinkedList::getBack() const
{
    return trailer->prev->data;
}
void LinkedList::addFront(int dt)
{
    Node *nd = new Node;
    nd->data = dt;
    nd->prev = header;
    nd->next = header->next;

    header->next->prev = nd;
    header->next = nd;
}
void LinkedList::addBack(int dt)
{
    Node *nd = new Node;
    nd->data = dt;
    nd->prev = trailer->prev;
    nd->next = trailer;

    trailer->prev->next = nd;
    trailer->prev = nd;
}
void LinkedList::removeFront()
{
    Node *nd = header->next->next;
    delete header->next;

    header->next = nd;
    nd->prev = header;
}
void LinkedList::removeBack()
{
    Node *nd = trailer->prev->prev;
    delete trailer->prev;

    trailer->prev = nd;
    nd->next = trailer;
}
void LinkedList::printReverse()
{
    Node *nd = trailer->prev;

    while (nd != header)
    {
        cout << nd->data <<" ";
        nd = nd->prev;
    }
    
}
void LinkedList::printForward()
{
    Node *nd = header->next;

    while (nd != trailer)
    {
        cout << nd->data <<" ";
        nd = nd->next;
    }
}
LinkedList::~LinkedList()
{
    while (header->next!=trailer)
        removeFront();
    delete header;
    delete trailer;
}