#ifndef __KRUSKAL_HPP__
#define __KRUSKAL_HPP__

#include "graph.hpp"


// colocar algoritmo de kruskal aqui
Graph kruskal(Graph inicio){
    Graph gResult(true);

    vector<Vertice> la;

    for(Vertice a: inicio.vertices){
        gResult.vertices.push_back(a);
    }

    inicio.ordenaArestas();
    for(Aresta a: inicio.arestas){
        gResult.arestas.push_back(a);
        if(gResult.graphHasCicle()){
            gResult.arestas.pop_back();
        }
    }



    return gResult;

}


#endif // __KRUSKAL_HPP__
