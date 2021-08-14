#include<string>
#include<iostream>

using namespace std;

void removeDupWord(string str);

void removeDupWord(string str)
{
    string word1;
    string word2;
    string word3;

    string word = "";
    for (auto x : str) 
    {
        if (x == '/')
        {
            word1 = word;
            cout << word << endl;
            word = "";
        }
        else {
            word = word + x;
        }
        cout<<"word1"<<word1<<endl;
        cout<<"word2"<<word2<<endl;
    }
    cout << word << endl;
}


int main()
{
    string str = "Geeks/for/Geeks";
    removeDupWord(str);
    /*
    string cadena1 = "Hola";
    cout << "cadena:" << cadena1;
    cout << "\n";
    cout << cadena1.size();
    cout << "\n";
    cout << cadena1.length();
    */
    return 0;
}

