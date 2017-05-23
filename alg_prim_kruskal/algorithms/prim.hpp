#ifndef __PRIM_HPP__
#define __PRIM_HPP__

#include "graph.hpp"

Aresta menor_peso(vector<Aresta>);
Aresta menor_pesoG(vector<Aresta>);

Graph prim(Graph& grafo){
    vector<Aresta> franja;      //arestas que partem dos vértices já visitados, e levam à vértices ainda não visitados
    vector<Aresta> adj_aux;     //auxiliar para panipulaçao da lista de arestas de um vertice

    const unsigned int qtdVertices = grafo.vertices.size();   //quantidade total de vertices
    unsigned int qtdVisitados = 0;   //quantidade de vertices ja visitados
    bool visitados[qtdVertices] {false};    //flag para vertices visitados

    //Declara o grafo representando a arvore minima geradora
    Graph result(false);    //nao orientado

    if(grafo.orientado){
        cout << "Prim eh destinado a grafos nao orientados!" << endl;
        return result;
    }

    //Copia todos os vertices do grafo original para o novo
    for(Vertice v: grafo.vertices){
        result.insereVertice(v);
    }

    //1. Escolhe vértice inicial e marca como visitado
    int v_atual = grafo.vertices[0].id;
    visitados[grafo.vertices[0].id] = true;
    qtdVisitados++;

    //Repete até todos os vértices serem visitados
    while(qtdVisitados < qtdVertices){
        //Copia para vetor de ajacentes as arestas ligadas ao ultimo vertice visitado
        adj_aux = grafo.getAdjList()[v_atual];
        for(Aresta a : adj_aux)
            franja.push_back(a);

        //Elimina arestas que ligam 2 vertices visitados (formariam ciclo)
        for(unsigned int i=0; i<franja.size(); i++){
            if(visitados[franja[i].para]){    //se ja visitou o destino da aresta
                franja.erase(franja.begin()+i);    //remove aresta do vetor
                i--;    //se removeu iésimo elemento, deve verificar esta posicao novamente na proxima iteracao
            }
        }

        //Encontra aresta com menor peso
        Aresta menorAresta = menor_peso(franja);

        //Adicionar aresta com menor peso na árvore geradora mínima
        result.insereAresta(menorAresta.de, menorAresta.para, menorAresta.peso);

        //Marca o vértice destino da aresta como visitado
        visitados[menorAresta.para] = true;
        qtdVisitados++;

        //Vértice destino passa a ser atual
        v_atual = menorAresta.para;
    }

    return result;
}

//Encontra aresta com menor peso
Aresta menor_peso(vector<Aresta> arestas){
    int qtdArestas = arestas.size();
    int menorAresta = 0;

    if(qtdArestas == 1)
        return arestas[0];
    else{
        //Encontra aresta com menor peso
        for(int i = 1; i < qtdArestas; ++i){
            if(arestas[i].peso < arestas[menorAresta].peso){
                menorAresta = i;
            }
        }

        return arestas[menorAresta];
    }
}

#endif // __PRIM_HPP__
