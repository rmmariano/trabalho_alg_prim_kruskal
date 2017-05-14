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
        bool insereAresta(int  id_v1, int id_v2, float peso);    //ret false se nao for possivel criar (nó nao existir)
        Aresta* verificaAresta(int id_v1, int id_v2);      //retorna obj da aresta, nullptr se nao existir
        bool removeAresta(int id_v1, int id_v2);     //retorna se foi removido
        void imprime();

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

//Construtor
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
    //Se remove vertice, outro vertice ocupa posição dele no vetor?
    //Isso invalidaria a relação ID==posição


    //verifica se vertice nao existe
    return false;

    //remove arestas que saem do vertice

    //remove arestas que chegam no vertice

    //remove vertice
}

bool Graph::insereAresta(int id_v1, int id_v2, float peso){
    //verificar se vertices nao existem
        //return false;

    //se aresta ja existe
    if(verificaAresta(id_v1, id_v2))
        return false;

    Aresta a{id_v1, id_v2, peso};
    adjList.at(id_v1).push_back(a);
    numArestas++;

    //se grafo nao orientado, insere aresta no sentido contrário
    if(!orientado){
        Aresta a2{id_v2, id_v1, peso};
        adjList.at(id_v2).push_back(a2);
        numArestas++;
    }

    return true;
}

Aresta* Graph::verificaAresta(int id_v1, int id_v2){
    for(unsigned int i=0; i < adjList[id_v1].size(); i++){
        if(adjList[id_v1][i].para == id_v2){    //se encontrou aresta para vertice 2
            return &adjList[id_v1][i];
        }
    }

    return nullptr; //se nao encontrar retorna null
}

bool Graph::removeAresta(int id_v1, int id_v2){
    bool achou = false;

    //percorre lista de arestas do vertice 1
    for(unsigned int i=0; i < adjList[id_v1].size(); i++){
        if(adjList[id_v1][i].para == id_v2){    //se encontrou aresta para vertice 2
            achou = true;
            adjList[id_v1].erase(adjList[id_v1].begin()+i);    //remove aresta
            numArestas--;
            break;
        }
    }

    //se grafo nao orientado, remove aresta no sentido contrario
    if(!orientado){
        for(unsigned int i=0; i < adjList[id_v2].size(); i++){
            if(adjList[id_v2][i].para == id_v1){    //se encontrou aresta para vertice 1
                cout << "achou contrario" << endl;
                adjList[id_v2].erase(adjList[id_v2].begin()+i);    //remove aresta
                numArestas--;
                break;
            }
        }
    }

    return achou;
}

void Graph::imprime(){

}



#endif // __GRAPH_DEF_HPP__
