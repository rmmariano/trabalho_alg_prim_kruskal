#ifndef __PRIM_HPP__
#define __PRIM_HPP__

#include "graph.hpp"

Aresta menor_peso(vector<Aresta>);

vector<Aresta> prim(Graph grafo){
    vector<Aresta> agm;
    vector<int> visitados;
    vector<Aresta> adjacentes;
    vector<Aresta> adj_aux;

    //1. Escolher vértice inicial e marcá-lo como visitado
    int v_atual = grafo.vertices[0].id;
    visitados.push_back(v_atual);

    //2. Selecionar todas as arestas ligadas ao vértice inicial
    adj_aux = grafo.getAdjList()[v_atual];

    //3. Escolher aresta com o menor peso
    Aresta menor = menor_peso(adj_aux);

    //4. Adicionar aresta na árvore geradora mínima
    agm.push_back(menor);

    //5. Marcar o outro vértice da aresta como visitado
    visitados.push_back(menor.para);

    //6. Atualizar conjunto de arestas que podem ser escolhidas
    for(Aresta a : adj_aux){
        if(a.de != menor.de || a.para != menor.para)
            adjacentes.push_back(a);
    }

    //Repetir até todos os vértices serem visitados
    int tam_vertices = grafo.vertices.size();
    while(tam_vertices != visitados.size()){
        v_atual = menor.para;

        //7. Selecionar todas as arestas ligadas ao último vertice visitado
        adj_aux.clear();
        adj_aux = grafo.getAdjList()[v_atual];

        //8. Copiar arestas do vetor de adjacentes para estrutura auxiliar
        for(Aresta a : adjacentes){
            adj_aux.push_back(a);
        }

        //9. Excluir arestas cujos vértices destino ja foram marcados como visitados
        adjacentes.clear();
        for(Aresta a : adj_aux){
            bool a_rejeitada = false;

            for(int v : visitados){
                if(a.para == v){
                    a_rejeitada = true;
                    break;
                }
            }

            if(!a_rejeitada)
                adjacentes.push_back(a);
        }

        //10. Escolher aresta com menor peso
        menor = menor_peso(adjacentes);

        //11. Adicionar aresta com menor peso na árvore geradora mínima
        agm.push_back(menor);

        //12. Marcar o outro vértice da aresta como visitado
        visitados.push_back(menor.para);
    }

    return agm;
}

//Função para escolher a aresta com o menor peso
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
