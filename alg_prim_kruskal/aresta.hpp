#ifndef ARESTA_HPP
#define ARESTA_HPP

#include "vertice.hpp"

class Aresta{
public:
    Aresta();
    Aresta(int de, int para, float peso) : de(de), para(para), peso(peso){}

    unsigned int de;     //ID do vertice de origem
    unsigned int para;   //ID do vertice destino
    float peso;
};

#endif // ARESTA_HPP
