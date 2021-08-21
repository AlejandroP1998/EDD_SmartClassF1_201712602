#include <iostream>
#include <string>

using namespace std;

int num = 0;
int contarN=0;
class Node
{
public:
    Node *next;
    Node *prev;
    int id = 0;
    string tipo;
    string campo;

    friend class Queue;
};

class Queue
{
public:
    Queue(int tam = 100);
    ~Queue();
    const string &front();
    void enqueue(string tipo, string campo);
    void dequeue();
    void imprimir();
    bool empty() const;
    int size() const;
    void grafico();

private:
    Node *header;
    Node *trailer;
    int tam;
    int tamMax;
};

Queue::Queue(int tm)
{
    header = new Node;
    trailer = new Node;
    header->next = trailer;
    trailer->prev = header;
    header->prev = NULL;
    trailer->next = NULL;

    tam = 0;
    tamMax = tm;
}

const string &Queue::front()
{
    return header->next->tipo;
}

void Queue::enqueue(string tipo, string campo)
{
    if (tam < tamMax)
    {
        Node *nd = new Node;
        nd->id = num;
        num++;
        nd->tipo = tipo;
        nd->campo = campo;
        nd->next = trailer;
        nd->prev = trailer->prev;

        trailer->prev->next = nd;
        trailer->prev = nd;
        tam++;
    }
}

void Queue::dequeue()
{
    if (!empty())
    {
        Node *nd = header->next->next;

        delete header->next;
        header->next = nd;
        nd->prev = header;

        tam--;
    }
}

void Queue::imprimir()
{
    int i = 0;
    while (i != tam)
    {
        cout << "Id: " << header->next->id << endl;
        cout << "Tipo: " << header->next->tipo << endl;
        cout << "Campo: " << header->next->campo << endl;

        header = header->next;
        i++;
    }
    while (i != 0)
    {
        header = header->prev;
        i--;
    }
}

bool Queue::empty() const
{
    return (tam == 0);
}

int Queue::size() const
{
    return tam;
}

Queue::~Queue()
{
    while (!empty())
        dequeue();
    delete header;
    delete trailer;
}

void Queue::grafico()
{
    int contador = 0;
    ofstream archivo;
    archivo.open("errores.dot", ios::out); //Abriendo el archivo
    archivo << "digraph G {\n";
    archivo << "rankdir=LR;\n";
    archivo << "node[shape = record];\n ";
    int i = 0;
    while (i != tam)
    {
        string str1 = std::to_string(contador);
        string str2 = std::to_string(contador + 1);
        string ide = std::to_string(header->next->id);

        archivo << "nodo" + str1 << "[label=\" id:" + ide + "\n| Tipo:" + header->next->tipo + "\n|Descripcion:" + header->next->campo + "\" ]";

        if (header->next != NULL)
        {
            archivo << "\n nodo" + str1 + "->" + "nodo" + str2 + "\n";
        }
        else
        {
            archivo << "nodo" + str1 + "\n";
        }
        contador++;
        header = header->next;
        i++;
    }
    archivo << "}\n";
    archivo.close();
    string cmd = "dot -Tpng errores.dot -o errores";
    string str = std::to_string(contarN);
    cmd += str;
    cmd += ".png";
    system(cmd.c_str());
    contarN++;
    while (i != 0)
    {
        header = header->prev;
        i--;
    }
}
