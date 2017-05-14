#ifndef __GRAPH_DEF_HPP__
#define __GRAPH_DEF_HPP__

#include <iostream>
#include <vector>

#include "aresta.hpp"

using namespace std;

class Graph {

    public:
        Graph();
        ~Graph();
       // colocar os metodos aqui

    private:
        // nao permite copia
        Graph(Graph&);
        Graph&	operator=(Graph&);

    private:
        // atributos privados aqui
        int numArestas;
        int numVertices;
        vector<Aresta> arestas;
        vector<Vertice> vertices;
};


#endif // __GRAPH_DEF_HPP__
