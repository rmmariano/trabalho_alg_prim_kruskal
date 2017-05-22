#ifndef __GRAPH_DEF_HPP__
#define __GRAPH_DEF_HPP__

#include <iostream>
#include <vector>
#include <stack>
#include <list>
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
        bool orientado;
        Graph(bool orientado);
        ~Graph(){}
        int insereVertice(Vertice& v);              //retorna ID do vertice inserido
        bool removeVertice(unsigned int id_v);      //retorna se foi removido
        bool verificaVertice(unsigned int id_v);    //retorna se vertice existe
        bool insereAresta(unsigned int  id_v1, unsigned int id_v2, float peso);    //ret false se nao for possivel criar (nó nao existir ou aresta existir)
        Aresta* verificaAresta(unsigned int id_v1, unsigned int id_v2);      //retorna obj da aresta, nullptr se nao existir
        bool removeAresta(unsigned int id_v1, unsigned int id_v2);     //retorna se foi removido
        void imprime();

        //Kruskal
        void imprimeKruskal();
        bool graphHasCicle(); //verifica se o grafo possui ciclo
        bool dfs(Vertice v); //Busca em profundidade de ciclos
        void ordenaArestas(); //Ordenação de Arestas

        //Prim
        vector<vector<Aresta>> getAdjList();    //retorna lista de adjacencia

        //Busca de ciclos para grafo nao orientado
        bool isCyclicUtil(int v, bool visited[], int parent);
        bool isCyclic();

    private:
        int numArestas;
        int numVertices;
        vector< vector<Aresta> > adjList;

        // nao permite copia do obj
        //Graph(Graph&);
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

    vector<Aresta> arestas;     //vetor de arestas que partem do nó inserido
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
        this->arestas.push_back(a2);
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
                //cout << "achou contrario" << endl;
                adjList[id_v2].erase(adjList[id_v2].begin()+i);    //remove aresta
                numArestas--;
                break;
            }
        }
    }

    //remove aresta do vetor de arestas
    int k = 0;
    for(Aresta a: this->arestas){
        if (id_v1 == a.de && id_v2 == a.para){
            this->arestas.erase(this->arestas.begin()+k);
        }

        //se for nao orientado remove aresta contraria
        if(!orientado && id_v1 == a.para && id_v2 == a.de){
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
    stack<int> visitar;                         //Pilha de vertices a serem visitados (indice)
    bool visitado[this->numVertices] {false};   //Indica se o vertice foi visitado, inicializado com false
    bool empilhado[this->numVertices] {false};  //Indica se vertice esta na pilha

    bool temVizinho = false;    //variável de controle para ver se há vizinho
    int id_destino;     //vertice vizinho

    int id_v = v.id;    //ID do vertice sendo verificado, inicia por v

    //Percore or vértices a partir de v
    while(true){
        temVizinho = false;    //variável de controle para ver se há vizinho

        //Se o vertice atual não foi visitado ainda
        if(!visitado[id_v]){
            visitar.push(id_v);     //Empilha para visitar depois
            empilhado[id_v] = true; //Marca como empilhado
            visitado[id_v] = true;  //Marca como visitado
        }

        //Percorre lista de arestas do vértice procurando por vizinho que ainda nao foi visitado
        for(Aresta a: adjList[id_v]){
            id_destino = a.para;

            if(empilhado[id_destino]){  //se o vertice destino esta na pilha
                if(orientado){
                    return true;    //Encontrou ciclo
                //se nao orientado ignora sentido contrario da primeira aresta
                }else{
                    for(Aresta a2 : adjList[v.id]){

                    }
                    //return true;    //Encontrou ciclo
                }

            }else if(!visitado[id_destino]){ //Se o destino ainda não foi visitado
                temVizinho = true;  //marca que há vizinho e quebra o laço para que ele seja verificado
                break;
            }
        }

        //se não tem vizinho
        if(!temVizinho){
            empilhado[visitar.top()] = false;   //pega próximo vértice da pilha para visitar
            visitar.pop();

            //Se visitou todos os vizinhos e não encontrou ciclo quebra o While(true)
            if(visitar.empty())
                break;

            id_v = visitar.top();   //atualiza o "v" atual para o ultimo vertice empilhado
        } else{
            id_v = id_destino;      //caso há vizinho, altera o vertice "v" para o vizinho
        }
    }
    //caso o while seja quebrado sem encontrar ciclo, retorna falso
    return false;
}


//Faz uma verificação no grafo avaliando se há ciclo
bool Graph::graphHasCicle(){
    for (Vertice v: this->vertices){
        if(dfs(v)) return true;     //faz busca em profundidade a partir de cada vertice
    }
    return false;
}


//Ordenação das arestas por peso
void Graph::ordenaArestas(){
    Aresta temp;
    int menor = 0;
    for(int pivo=0; pivo < numArestas; pivo++){
        menor = pivo;
        for(int i=pivo+1; i<numArestas; i++){
            if(arestas[i].peso < arestas[menor].peso)
                menor = i;
        }

        //swap
        temp = arestas.at(pivo);
        arestas.at(pivo) = arestas.at(menor);
        arestas.at(menor) = temp;
    }
}


//  Adaptado de http://www.geeksforgeeks.org/detect-cycle-undirected-graph/

// A recursive function that uses visited[] and parent to detect
// cycle in subgraph reachable from vertex v.
bool Graph::isCyclicUtil(int v, bool visited[], int parent){
    // Mark the current node as visited
    visited[v] = true;

    // Recur for all the vertices adjacent to this vertex
    int i;
    for (i = 0; i < adjList[v].size(); ++i){
        // If an adjacent is not visited, then recur for that adjacent
        if (!visited[adjList[v][i].para]){
           if (isCyclicUtil(adjList[v][i].para, visited, v))
              return true;
        }

        // If an adjacent is visited and not parent of current vertex, then there is a cycle.
        else if (adjList[v][i].para != parent)
           return true;
    }
    return false;
}

// Returns true if the graph contains a cycle, else false.
bool Graph::isCyclic(){
    // Mark all the vertices as not visited and not part of recursion stack
    int V = this->numVertices;
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Call the recursive helper function to detect cycle in different DFS trees
    for (int u = 0; u < V; u++)
        if (!visited[u]) // Don't recur for u if it is already visited
          if (isCyclicUtil(u, visited, -1))
             return true;

    return false;
}

#endif // __GRAPH_DEF_HPP__
