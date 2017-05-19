#include <iostream>

#include "algorithms/graph.hpp"
#include "tests/test_case_kruskal.hpp"
#include "tests/test_case_prim.hpp"

int main(){

    Graph g(true);  //grafo orientado

//Insere vertices
    cout << "================================ Insere vertices ================================"<< endl;
    Vertice v0("A");
    int idvA = g.insereVertice(v0);
    cout << "id A: " << idvA << endl;

    Vertice v1("B");
    int idvB = g.insereVertice(v1);
    cout << "id B: " << idvB << endl;

    Vertice v2("C");
    int idvC = g.insereVertice(v2);
    cout << "id C: " << idvC << endl;

    Vertice v3("D");
    int idvD = g.insereVertice(v3);
    cout << "id D: " << idvD << endl;

    Vertice v4("E");
    int idvE = g.insereVertice(v4);
    cout << "id E: " << idvE << endl;

//Insere arestas
    cout << "\n================================ Insere arestas ================================"<< endl;
    g.insereAresta(idvA, idvB, 2);  //insere aresta de A para B com peso 2
    g.insereAresta(idvA, idvC, 8);
    g.insereAresta(idvA, idvD, 3);
    g.insereAresta(idvA, idvE, 5);
    g.insereAresta(idvE, idvA, 5);
    g.insereAresta(idvB, idvE, 1);

    g.imprime();
    cout << "\n "<< g.graphHasCicle();
/*
//Verifica aresta
    cout << "\n================================ Verifica aresta ================================"<< endl;
    Aresta *a = g.verificaAresta(idvA, idvD);
    if(a != nullptr)
        cout << g.vertices[a->de].nome << " -> " << g.vertices[a->para].nome << "\tPeso: " << a->peso << endl;
    else
        cout << "Aresta nao encontrada" << endl;

//Remove aresta
    cout << "\n================================ Remove aresta ================================"<< endl;
    g.removeAresta(idvA, idvB);
    cout << "Removeu A -> B" << endl;
    g.imprime();

//Remove vertice
    cout << "\n================================ Remove vertice ================================"<< endl;
    g.removeVertice(idvA);
    cout << "Removeu vertice A" << endl;
    g.imprime();

*/
/*
    test_case_kruskal_01();
    test_case_kruskal_02();
    // outros ...

    test_case_prim_01();
    test_case_prim_02();
    // outros ...
*/




    return 0;
}
