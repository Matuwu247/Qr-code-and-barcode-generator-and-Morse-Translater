#include <iostream>
#include <cctype>
#include <stdio.h>
#include <cstdlib>
#include <map>
void diccionario(); //Instaciacion de la funcio diccionario
using namespace std;
map<char, string> mor;//Funciones de la biblioteca map para poder crear el diccionario morse
map<char, string>::iterator iterador;
int main()
{
    string arg = getenv("ARGUMENTO"); //Toma el argumento ingresado en la terminal
    diccionario();
    string palabramorse = "";
    string morse[arg.size()]; //Declara un vector llamado morse con el largo del argumento
    for (int i = 0; i < arg.size(); i++)
    {
        string a;
        if (mor.find(tolower(arg[i])) != mor.end()) //Convierte las letras a minuscula
        { 
            auto it = mor.find(tolower(arg[i]));
            cout << "El caracter " << it->first << " en morse se traduce como: " << it->second << endl; //Traduce la letra ingresada a morse y la muestra
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
void diccionario() // Funcion diccionario con las traducciones a Morse
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
