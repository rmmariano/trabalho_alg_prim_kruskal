#ifndef __GRAPH_DEF_HPP__
#define __GRAPH_DEF_HPP__

#include <iostream>
#include <vector>

#include "aresta.hpp"

using namespace std;

class Graph {
    public:
        Graph(bool orientado);
        ~Graph(){}
        int insereVertice(Vertice& v);       //retorna ID do vertice inserido
        bool removeVertice(Vertice& v);      //retorna se foi removido
        Aresta insereAresta(int  id_v1, int id_v2, float peso);    //ret obj da aresta, nullptr se nao for possivel criar (nó nao existir)
        Aresta verificaAresta(Vertice& v1, Vertice& v2);      //retorna obj da aresta, nullptr se nao existir
        bool removeAresta(int id_v1, int id_v2);     //retorna se foi removido
        imprime();

    private:
        bool orientado;
        int numArestas;
        int numVertices;
        //Vertice v0;                 //vertice inicial
        vector< vector<Aresta> > adjList;
        vector<Vertice> vertices;

        // nao permite copia do obj
        Graph(Graph&);
        Graph&	operator=(Graph&);
};

Graph::Graph(bool orientado) : orientado(orientado){
    numArestas = 0;
    numVertices = 0;
}

int Graph::insereVertice(Vertice& v){
    v.id = vertices.size();     //id = posicao do ultimo elemento inserido
    vertices.push_back(v);

    vector<Aresta> arestas;     //vetor de arestas que partem daquele nó
    adjList.push_back(arestas); //adiciona vetor de arestas vazio

    numVertices++;
    return v.id;
}

bool Graph::removeVertice(Vertice& v){
    //verifica se vertice nao existe
    return false;

    //remove arestas que saem do vertice

    //remove arestas que chegam no vertice

    //remove vertice
}

Aresta Graph::insereAresta(int id_v1, int id_v2, float peso){
    //verificar se vertices existem

    Aresta a;
    a.de = vertices[id_v1];
    a.para = vertices[id_v2];
    a.peso = peso;

    adjList.at(id_v1).push_back(a);
    numArestas++;

    //se grafo nao orientado, insere aresta no sentido contrário
    if(!orientado){
        Aresta a2{vertices[id_v2], vertices[id_v1], peso};
        adjList.at(id_v2).push_back(a2);
        numArestas++;
    }
}



#endif // __GRAPH_DEF_HPP__
