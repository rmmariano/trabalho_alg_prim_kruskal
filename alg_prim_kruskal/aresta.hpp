#ifndef ARESTA_HPP
#define ARESTA_HPP

#include "vertice.hpp"

class Aresta{
public:
    Aresta();
    Aresta(Vertice de, Vertice para, float peso) : de(de), para(para), peso(peso){}

    Vertice de;
    Vertice para;
    float peso;
};

#endif // ARESTA_HPP
