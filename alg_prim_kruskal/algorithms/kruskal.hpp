#ifndef __KRUSKAL_HPP__
#define __KRUSKAL_HPP__

#include "graph.hpp"

Graph kruskal(Graph inicio){
    //Declara o grafo representando a arvore minima geradora
    Graph gResult(true);    //orientado

    //itera todas as vertices do grafo inicial, registrando-os no novo grafo
    for(Vertice a: inicio.vertices){
        gResult.insereVertice(a);
    }
    //Ordena a lista de arestas por peso
    inicio.ordenaArestas();

    //itera as arestas do grafo inicial
    for(Aresta a: inicio.arestas){        
        gResult.insereAresta(a.de, a.para, a.peso);     //insere no novo grafo

        //se surgir ciclos com essa ultima aresta, remove do grafo
        if(gResult.graphHasCicle()){
            gResult.removeAresta(a.de, a.para);
        }
    }

    return gResult;     //retorna grafo MST
}


#endif // __KRUSKAL_HPP__
