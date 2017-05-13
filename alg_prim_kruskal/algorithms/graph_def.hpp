#ifndef __GRAPH_DEF_HPP__
#define __GRAPH_DEF_HPP__

#include <iostream>

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
        int test;
};


#endif // __GRAPH_DEF_HPP__
