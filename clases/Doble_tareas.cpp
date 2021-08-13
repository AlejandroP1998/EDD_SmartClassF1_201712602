#include <iostream>
#include <ostream>

using namespace std;
int id = 0;
class Nodo
{
private:
    int data;
    int id;
    string carne;
    string nombre;
    string descripcion;
    string materia;
    int yy, mm, dd;
    int fecha[10][5][30];
    string hora;
    string estado;

    Nodo *prev;
    Nodo *next;

    friend class LinkedList;
};

class LinkedList
{
public:
    LinkedList();  //Constructor
    ~LinkedList(); //Destructor
    int getFront() const;
    int getBack() const;
    void ingresar(string carne, string nombre, string descripcion,
                  string materia, int yy, int mm, int dd,string hora, string estado);
    void addFront(int dt);
    void addBack(int dt);
    void removeFront();
    void removeBack();
    void printReverse();
    void printForward();

private:
    Nodo *header;
    Nodo *trailer;
};

LinkedList::LinkedList()
{
    header = new Nodo;
    trailer = new Nodo;
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

void LinkedList::ingresar(string carne, string nombre, string descripcion,
                  string materia, int yy, int mm, int dd,string hora, string estado)
{
    Nodo *nd = new Nodo;
    nd->id = id;
    id ++;
    nd->carne = carne;
    nd->nombre = nombre;
    nd->descripcion = descripcion;
    nd->materia = materia;
    nd->yy = yy;
    nd->mm = mm;
    nd->dd = dd;
    nd->hora = hora;
    nd->estado = estado;
    nd->prev = header;
    nd->next = header->next;

    header->next->prev = nd;
    header->next = nd;
    
}

void LinkedList::addFront(int dt)
{
    Nodo *nd = new Nodo;
    nd->data = dt;
    nd->prev = header;
    nd->next = header->next;

    header->next->prev = nd;
    header->next = nd;
}
void LinkedList::addBack(int dt)
{
    Nodo *nd = new Nodo;
    nd->data = dt;
    nd->prev = trailer->prev;
    nd->next = trailer;

    trailer->prev->next = nd;
    trailer->prev = nd;
}



void LinkedList::removeFront()
{
    Nodo *nd = header->next->next;
    delete header->next;

    header->next = nd;
    nd->prev = header;
}
void LinkedList::removeBack()
{
    Nodo *nd = trailer->prev->prev;
    delete trailer->prev;

    trailer->prev = nd;
    nd->next = trailer;
}
void LinkedList::printReverse()
{
    Nodo *nd = trailer->prev;

    while (nd != header)
    {
        cout << nd->data << " ";
        nd = nd->prev;
    }
}
void LinkedList::printForward()
{
    Nodo *nd = header->next;

    while (nd != trailer)
    {
        cout << nd->data << " ";
        nd = nd->next;
    }
}
LinkedList::~LinkedList()
{
    while (header->next != trailer)
        removeFront();
    delete header;
    delete trailer;
}