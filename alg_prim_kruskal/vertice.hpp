#ifndef VERTICE_HPP
#define VERTICE_HPP

#include <string>

using namespace std;

class Vertice{

public:
    Vertice(string nome) : nome(nome) {}

    int id;
    string nome;
    //outros atributos...
};

#endif // VERTICE_HPP
