#ifndef __PRIM_HPP__
#define __PRIM_HPP__

#include "graph.hpp"

Aresta menor_peso(vector<Aresta>);
Aresta menor_pesoG(vector<Aresta>);

vector<Aresta> prim(Graph& grafo){
    vector<Aresta> agm;
    vector<int> visitados;
    vector<Aresta> adjacentes;
    vector<Aresta> adj_aux;

    //1. Escolher vértice inicial e marca-lo como visitado
    int v_atual = grafo.vertices[0].id;
    visitados.push_back(v_atual);

    //Repetir até todos os vértices serem visitados
    unsigned int tam_vertices = grafo.vertices.size();
    while(tam_vertices != visitados.size()){
        //2. Selecionar todas as arestas ligadas ao último vertice visitado
        adj_aux.clear();
        adj_aux = grafo.getAdjList()[v_atual];

        //3. Copiar arestas do vetor de adjacentes para estrutura auxiliar
        for(Aresta a : adjacentes){
            adj_aux.push_back(a);
        }

        //4. Excluir arestas cujos vértices destino ja foram marcados como visitados
        adjacentes.clear();
        for(Aresta a : adj_aux){
            bool a_rejeitada = false;

            for(unsigned int v : visitados){
                if(a.para == v){
                    a_rejeitada = true;
                    break;
                }
            }

            if(!a_rejeitada)
                adjacentes.push_back(a);
        }

        //5. Escolher aresta com menor peso
        Aresta menor = menor_peso(adjacentes);

        //6. Adicionar aresta com menor peso na árvore geradora mínima
        agm.push_back(menor);

        //7. Marcar o outro vértice da aresta como visitado
        visitados.push_back(menor.para);

        //8. Eleger último vértice destino como atual
        v_atual = menor.para;
    }

    return agm;
}

Graph primG(Graph& grafo){
    vector<Aresta> adjacentes;  //arestas ainda nao selecionadas dos vertices ja visitados
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
            adjacentes.push_back(a);

        //Elimina arestas que ligam 2 vertices visitados (formariam ciclo)
        for(unsigned int i=0; i<adjacentes.size(); i++){
            if(visitados[adjacentes[i].para]){    //se ja visitou o destino da aresta
                adjacentes.erase(adjacentes.begin()+i);    //remove aresta do vetor
                i--;    //se removeu iésimo elemento, deve verificar esta posicao novamente na proxima iteracao
            }
        }

        //Encontra aresta com menor peso
        Aresta menorAresta = menor_pesoG(adjacentes);

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
Aresta menor_pesoG(vector<Aresta> arestas){
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
