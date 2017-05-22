#ifndef __GRAPH_DEF_HPP__
#define __GRAPH_DEF_HPP__

#include <iostream>
#include <vector>
#include <stack>
#include "../aresta.hpp"

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
        vector<Aresta> arestas;
        Graph(bool orientado);
        ~Graph(){}
        int insereVertice(Vertice& v);       //retorna ID do vertice inserido
        bool removeVertice(unsigned int id_v);      //retorna se foi removido
        bool verificaVertice(unsigned int id_v);
        bool insereAresta(unsigned int  id_v1, unsigned int id_v2, float peso);    //ret false se nao for possivel criar (nó nao existir ou aresta existir)
        Aresta* verificaAresta(unsigned int id_v1, unsigned int id_v2);      //retorna obj da aresta, nullptr se nao existir
        bool removeAresta(unsigned int id_v1, unsigned int id_v2);     //retorna se foi removido
        void imprime();
        void imprimeKruskal();
        bool graphHasCicle(); //verifica se o grafo possui ciclo
        bool dfs(Vertice v); //Busca em profundidade
        void ordenaArestas(); //Ordenação de Arestas
        vector<vector<Aresta>> getAdjList();

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

vector<vector<Aresta>> Graph::getAdjList(){
    return adjList;
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

    return true;
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
    this->arestas.push_back(a);
    numArestas++;

    //se grafo nao orientado, insere aresta no sentido contrário
    if(!orientado){
        Aresta a2{id_v2, id_v1, peso};
        adjList.at(id_v2).push_back(a2);
        numArestas++;
        this->arestas.push_back(a2);
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
    int k = 0;
    for(Aresta a: this->arestas){
        if (id_v1 == a.de && id_v2 == a.para){
            this->arestas.erase(this->arestas.begin()+k);
        }
        k++;
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

void Graph::imprimeKruskal(){

    for(Aresta a: this->arestas){
        cout << "De: "<< this->vertices.at(a.de).nome << " Para: " << this->vertices.at(a.para).nome << " Peso: " << a.peso << endl;
    }

}

//Busca em profundidade para avaliar se há ciclo a partir de um Vertice V
bool Graph::dfs(Vertice v){
 //Pilha de vertices visitados (indice)
 stack<int> visit;
 //Declaração de dois vetores, o primeiro avalia se o vertice foi visitado, o segundo avalia a pilha
 bool visitados[this->numVertices], pilha_v[this->numVertices];
 //laço para inicializar os vetores com false
 for (int k = 0; k < this->numVertices; k++){
     visitados[k] = false;
     pilha_v[k] = false;
 }

 //ID da vertice
 int id_v;
 id_v = v.id;

 while(true){
     //variável de controle para ver se há visinho
     bool temVizinho = false;

     //"Se" o vertice atual não foi visitado ainda
     if(!visitados[id_v]){
         //empilha e altera os vetores de controle
         visit.push(id_v);
         visitados[id_v] = true;
         pilha_v[id_v] = true;
     }
      //vertice vizinho
      int indexA;

     //laço para iterar a lista de ajacencia a partir da vertice V
     for(Aresta a: adjList.at(id_v)){
         indexA = a.para;

         if(pilha_v[indexA]){
             //"Se" encontrar ciclo
             return true;
         }

         else if(!visitados[indexA]){
             //caso ainda não encontre ciclo, marca que há vizinho e quebra o laço de iteração
             temVizinho = true;
             break;
         }
       }

     //se não tem vizinho
     if(!temVizinho){
         pilha_v[visit.top()] = false;
         visit.pop();
         //Se visitou todos os vizinhos e não encontrou ciclo quebra o While(true)
         if(visit.empty())
             break;
        //atualiza o "v" atual para o ultimo vertice empilhado
        id_v = visit.top();
     }
     else{
        //caso há vizinho, altera o vertice "v" para o vizinho
        id_v = indexA;
     }
 }
 //caso o while seja quebrado sem encontrar ciclo, retorna falso
 return false;

}


//Faz uma verificação no grafo avaliando se há ciclo
bool Graph::graphHasCicle(){
    for (Vertice v: this->vertices){
        if(dfs(v)) return true;
    }
    return false;
}



//Bubble sort para ordenação das arestas por peso
void Graph::ordenaArestas(){

    Aresta temp;
    for (int k = this->numArestas-1; k <= 0 ; k++){
        for(int i = 0; i < k; i++){
            if(arestas.at(i).peso > arestas.at(i+1).peso){
                temp = arestas.at(i);
                arestas.at(i) = arestas.at(i+1);
                arestas.at(i+1) = temp;
            }
        }
    }

}

#endif // __GRAPH_DEF_HPP__
