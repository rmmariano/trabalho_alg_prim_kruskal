#ifndef __KRUSKAL_HPP__
#define __KRUSKAL_HPP__

#include "graph.hpp"


// colocar algoritmo de kruskal aqui
Graph kruskal(Graph inicio){
    //Declara o grafo representando a arvore minima geradora
    Graph gResult(true);

    //vector<Vertice> la;

    //itera todas as vertices do grafo inicial, registrando-os no novo grafo
    for(Vertice a: inicio.vertices){
        gResult.insereVertice(a);
    }
    //Ordena a lista de arestas por peso
    inicio.ordenaArestas();

    //itera as arestas do gráfico inicial
    for(Aresta a: inicio.arestas){
        //insere no novo grafo
        gResult.insereAresta(a.de, a.para, a.peso);
        //se há ciclos com essa ultima aresta, deleta do grafo
        if(gResult.graphHasCicle()){
            gResult.removeAresta(a.de, a.para);
        }
    }



    return gResult;

}


#endif // __KRUSKAL_HPP__
