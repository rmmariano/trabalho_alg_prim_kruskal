#ifndef VERTICE_HPP
#define VERTICE_HPP

#include <string>

using namespace std;

class Vertice{

public:
    Vertice(string nome) : valido(true), nome(nome) {}

    bool valido;    //indentifica se vertice existe
    int id;
    string nome;
};

#endif // VERTICE_HPP
