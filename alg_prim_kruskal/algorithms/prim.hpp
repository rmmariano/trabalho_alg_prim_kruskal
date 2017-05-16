#ifndef __PRIM_HPP__
#define __PRIM_HPP__

#include "graph.hpp"

Aresta menor_peso(vector<Aresta>);

vector<Aresta> prim(Graph grafo){
    vector<Aresta> agm;
    vector<int> visitados;

    int v_atual = grafo.vertices[3].id;

    while(visitados.size() != grafo.vertices.size()){
        vector<Aresta> adj;
        vector<Aresta> adj_aux;
        vector<Aresta> adj_vis;
        vector<Aresta> adj_perm;

        visitados.push_back(v_atual);

        //Arestas adjacentes aos vértice visitados
        int tam = grafo.getAdjList().size();
        for(int i = 0; i < tam; ++i){
            adj = grafo.getAdjList()[i];

            for(int ver : visitados){
                if(adj[0].de == ver){
                    for(int j = 0; j < adj.size(); ++j){
                        adj_vis.push_back(adj[j]);
                    }
                }
            }
        }

        //Exclui ligação com vértices já visitados
        for(Aresta a : adj_vis){
            bool info = true;
            for(int v : visitados){
                if(a.para == v)
                    info = false;
            }

            if(info)
                adj_perm.push_back(a);
        }

        //Exclui já inseridas
        for(Aresta a : adj_perm){
            bool info = true;
            for(Aresta a_esc : agm){
                if ((a.de == a_esc.de && a.para == a_esc.para) || (a.de == a_esc.para && a.para == a_esc.de)){
                    info = false;
                }
            }

            if(info)
                adj_aux.push_back(a);
        }

        if(adj_aux.size() > 0){
            //Calcula o menor peso
            Aresta a_menor = menor_peso(adj_aux);

            //Novo vértice a ser consultado
            v_atual = a_menor.para;

            //Adiciona aresta na árvore geradora mínima
            agm.push_back(a_menor);
        }
    }

    return agm;
}

Aresta menor_peso(vector<Aresta> arestas){
    Aresta a_menor(0,0,0);
    int tam = arestas.size();

    if(tam == 1)
        return arestas[0];
    else{
        for(int i = 1; i < tam; ++i){
            if(arestas[i].peso < arestas[i-1].peso){
                a_menor = arestas[i];
            }
            else{
                a_menor = arestas[i-1];
                arestas[i] = arestas[i-1];
            }
        }

        return arestas[tam-1];
    }
}

#endif // __PRIM_HPP__
