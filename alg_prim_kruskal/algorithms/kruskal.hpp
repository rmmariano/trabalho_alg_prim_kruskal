#ifndef __KRUSKAL_HPP__
#define __KRUSKAL_HPP__

#include "graph.hpp"

Graph kruskal(Graph& inicio){
    //Declara o grafo representando a arvore minima geradora
    Graph gResult(false);    //nao orientado

    if(inicio.orientado){
        cout << "Kruskal eh destinado a grafos nao orientados!" << endl;
        return gResult;
    }

    //Copia todos os vertices do grafo original para o novo
    for(Vertice a: inicio.vertices)
        gResult.insereVertice(a);

    //Ordena a lista de arestas por peso
    inicio.ordenaArestas();

    //Itera as arestas do grafo inicial
    for(Aresta a: inicio.arestas){        
        gResult.insereAresta(a.de, a.para, a.peso);     //insere no novo grafo

        //se surgir ciclo com essa ultima aresta, remove do grafo
        if(gResult.isCyclic()){
            gResult.removeAresta(a.de, a.para);
        }
    }

    return gResult;     //retorna grafo AGM
}

#endif // __KRUSKAL_HPP__
