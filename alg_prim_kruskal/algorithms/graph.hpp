#ifndef __GRAPH_DEF_HPP__
#define __GRAPH_DEF_HPP__

#include <iostream>
#include <vector>
#include "aresta.hpp"

/* Ao remover um vertice, a posição dos vertices posteriores no vetor seria alterada
 * invalidando a relação vertice.id == adjList[id].
 * Solução: Não remover vertice da lista de adjacencia
 *      Flag no vértice para indicar se é válido
 * Assim, preserva-se o tamanho do vetor, não alterando os IDs/posições
 */

using namespace std;

class Graph {
    public:
        vector<Vertice> vertices;

        Graph(bool orientado);
        ~Graph(){}
        int insereVertice(Vertice& v);       //retorna ID do vertice inserido
        bool removeVertice(unsigned int id_v);      //retorna se foi removido
        bool verificaVertice(unsigned int id_v);
        bool insereAresta(unsigned int  id_v1, unsigned int id_v2, float peso);    //ret false se nao for possivel criar (nó nao existir ou aresta existir)
        Aresta* verificaAresta(unsigned int id_v1, unsigned int id_v2);      //retorna obj da aresta, nullptr se nao existir
        bool removeAresta(unsigned int id_v1, unsigned int id_v2);     //retorna se foi removido
        void imprime();

    private:
        bool orientado;
        int numArestas;
        int numVertices;
        //Vertice v0;                 //vertice inicial
        vector< vector<Aresta> > adjList;

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

bool Graph::removeVertice(unsigned int id_v){
    //verifica se vertice nao existe
    if(!verificaVertice(id_v))
        return false;

    //remove arestas que chegam no vertice
    for(unsigned int vert=0; vert < adjList.size(); vert++){    //para cada vertice do grafo
        if(vertices[vert].valido){  //se vertice nao foi removido
            for(unsigned int are=0; are < adjList[vert].size(); are++){ //para cada aresta do vertice
                if(adjList[vert][are].para == id_v){    //se é aresta para vertice a ser removido
                    removeAresta(vert, id_v);   //remove aresta
                }
            }
        }
    }

    //remove arestas que saem do vertice
    adjList[id_v].clear();


    //remove vertice
    vertices[id_v].valido = false;
    numVertices--;
}

bool Graph::verificaVertice(unsigned int id_v){
    if(id_v >= adjList.size())  //id maior que o tamanho da lista
        return false;
    if(!vertices[id_v].valido)    //vertice morto
        return false;

    return true;
}

bool Graph::insereAresta(unsigned int id_v1, unsigned int id_v2, float peso){
    //verificar se vertices nao existem
    if(!verificaVertice(id_v1) || !verificaVertice(id_v2))
        return false;

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

Aresta* Graph::verificaAresta(unsigned int id_v1, unsigned int id_v2){
    for(unsigned int i=0; i < adjList[id_v1].size(); i++){
        if(adjList[id_v1][i].para == id_v2){    //se encontrou aresta para vertice 2
            return &adjList[id_v1][i];
        }
    }

    return nullptr; //se nao encontrar retorna null
}

bool Graph::removeAresta(unsigned int id_v1, unsigned int id_v2){
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
    for(unsigned int vert=0; vert < adjList.size(); vert++){
        if(vertices[vert].valido){  //se vertice nao foi removido
            cout << vertices[vert].nome<< " -> ";
            for(unsigned int are=0; are < adjList[vert].size(); are++){
                cout << vertices[adjList[vert][are].para].nome << " peso " << adjList[vert][are].peso << ", ";
            }
            cout << endl;
        }
    }
}

bool Graph::removeAresta(int id_v1, int id_v2){
    bool achou = false;

    //percorre lista de arestas do vertice 1
    for(unsigned int i=0; i < adjList[id_v1].size(); i++){
        if(adjList[id_v1][i].para == id_v2){    //se encontrou aresta para vertice 2
            cout << "achou" << endl;
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

#endif // __GRAPH_DEF_HPP__
