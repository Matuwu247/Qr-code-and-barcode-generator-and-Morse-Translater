#include <iostream>
#include <cctype>
#include <stdio.h>
#include <cstdlib>
#include <map>
void diccionario();
using namespace std;
map<char, string> mor;
map<char, string>::iterator iterador;
int main()
{
    string arg = getenv("ARGUMENTO");
    diccionario();
    string palabramorse = "";
    string morse[arg.size()];
    for (int i = 0; i < arg.size(); i++)
    {
        string a;
        if (mor.find(tolower(arg[i])) != mor.end())
        {
            auto it = mor.find(tolower(arg[i]));
            cout << "El caracter " << it->first << " en morse se traduce como: " << it->second << endl;
            morse[i] = it->second;
        }
    }
    cout<<"\n";
    for (int i = 0; i < arg.size(); i++)
    {
        cout << morse[i]<<"\t";
    }
    cout<<"\n\n";
}
void diccionario()
{

    mor['a'] = ".-";
    mor['b'] = "-...";
    mor['c'] = "-.-.";
    mor['d'] = "-..";
    mor['e'] = ". ";
    mor['f'] = "..-. ";
    mor['g'] = "--. ";
    mor['h'] = ".... ";
    mor['i'] = ".. ";
    mor['j'] = ".--- ";
    mor['k'] = "-.- ";
    mor['l'] = ".-.. ";
    mor['n'] = "-. ";
    mor['m'] = "-- ";
    mor['o'] = "--- ";
    mor['p'] = ".--. ";
    mor['q'] = "--.-";
    mor['r'] = ".-. ";
    mor['s'] = "... ";
    mor['t'] = "- ";
    mor['u'] = "..- ";
    mor['v'] = "...- ";
    mor['w'] = ".-- ";
    mor['x'] = "-..- ";
    mor['y'] = "-.-- ";
    mor['z'] = "--.. ";
    mor[' '] = "\t";
}
