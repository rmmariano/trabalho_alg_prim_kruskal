#ifndef __TEST_CASE_PRIM_HPP__
#define __TEST_CASE_PRIM_HPP__

#include "../algorithms/prim.hpp"

void test_case_prim_01 () {
    Graph g(false);

    //Vértices
    Vertice v0("A");
    int idvA = g.insereVertice(v0);
    Vertice v1("B");
    int idvB = g.insereVertice(v1);
    Vertice v2("C");
    int idvC = g.insereVertice(v2);
    Vertice v3("D");
    int idvD = g.insereVertice(v3);
    Vertice v4("E");
    int idvE = g.insereVertice(v4);
    Vertice v5("F");
    int idvF = g.insereVertice(v5);
    Vertice v6("G");
    int idvG = g.insereVertice(v6);

    //Arestas
    g.insereAresta(idvA, idvB, 7);
    g.insereAresta(idvA, idvD, 5);

    g.insereAresta(idvB, idvA, 7);
    g.insereAresta(idvB, idvC, 8);
    g.insereAresta(idvB, idvD, 9);
    g.insereAresta(idvB, idvE, 7);

    g.insereAresta(idvC, idvB, 8);
    g.insereAresta(idvC, idvE, 5);

    g.insereAresta(idvD, idvA, 5);
    g.insereAresta(idvD, idvB, 9);
    g.insereAresta(idvD, idvE, 15);
    g.insereAresta(idvD, idvF, 6);

    g.insereAresta(idvE, idvB, 7);
    g.insereAresta(idvE, idvD, 15);
    g.insereAresta(idvE, idvF, 8);

    g.insereAresta(idvF, idvD, 6);
    g.insereAresta(idvF, idvE, 8);
    g.insereAresta(idvF, idvG, 11);

    g.insereAresta(idvG, idvE, 9);
    g.insereAresta(idvG, idvF, 11);

    cout << "\n\nComeco execucao Teste 01 Prim\n";

    vector<Aresta> agm = prim(g);

    float soma = 0;
    int qtd = 0;
    for(Aresta a : agm){
        cout << a.de << " -> " << a.para << "\n";
        soma += a.peso;
        ++qtd;
    }

    cout << "Soma da AGM: " << soma << "\n";
    cout << "Qtd de arestas: " << qtd << "\n";
    cout << "Fim execucao Teste 01 Prim\n";
}

void test_case_prim_02 () {
    Graph g(false);

    //Vértices
    Vertice v0("A");
    int idvA = g.insereVertice(v0);
    Vertice v1("B");
    int idvB = g.insereVertice(v1);
    Vertice v2("C");
    int idvC = g.insereVertice(v2);
    Vertice v3("D");
    int idvD = g.insereVertice(v3);
    Vertice v4("E");
    int idvE = g.insereVertice(v4);
    Vertice v5("F");
    int idvF = g.insereVertice(v5);

    //Arestas
    g.insereAresta(idvA, idvB, 6);
    g.insereAresta(idvA, idvC, 1);
    g.insereAresta(idvA, idvD, 5);

    g.insereAresta(idvB, idvA, 6);
    g.insereAresta(idvB, idvC, 2);
    g.insereAresta(idvB, idvE, 5);

    g.insereAresta(idvC, idvA, 1);
    g.insereAresta(idvC, idvB, 2);
    g.insereAresta(idvC, idvD, 2);
    g.insereAresta(idvC, idvE, 6);
    g.insereAresta(idvC, idvF, 4);

    g.insereAresta(idvD, idvA, 5);
    g.insereAresta(idvD, idvC, 2);
    g.insereAresta(idvD, idvF, 4);

    g.insereAresta(idvE, idvB, 5);
    g.insereAresta(idvE, idvC, 6);
    g.insereAresta(idvE, idvF, 3);

    g.insereAresta(idvF, idvC, 4);
    g.insereAresta(idvF, idvD, 4);
    g.insereAresta(idvF, idvE, 3);

    cout << "\n\nComeco execucao Teste 02 Prim\n";

    vector<Aresta> agm = prim(g);

    float soma = 0;
    int qtd = 0;
    for(Aresta a : agm){
        cout << a.de << " -> " << a.para << "\n";
        soma += a.peso;
        ++qtd;
    }

    cout << "Soma da AGM: " << soma << "\n";
    cout << "Qtd de arestas: " << qtd << "\n";
    cout << "Fim execucao Teste 02 Prim\n";

}

void test_case_prim_03(){
    cout << "\n================================ Prim - Teste 3 ================================"<< endl;

    Graph g(false);  //grafo nao orientado

//Insere vertices
    Vertice v0("A");
    int idvA = g.insereVertice(v0);

    Vertice v1("B");
    int idvB = g.insereVertice(v1);

    Vertice v2("C");
    int idvC = g.insereVertice(v2);

    Vertice v3("D");
    int idvD = g.insereVertice(v3);

    Vertice v4("E");
    int idvE = g.insereVertice(v4);

//Insere arestas
    g.insereAresta(idvA, idvB, 2);  //insere aresta de A para B com peso 2
    g.insereAresta(idvA, idvC, 8);
    g.insereAresta(idvA, idvD, 3);
    g.insereAresta(idvA, idvE, 5);
    g.insereAresta(idvE, idvD, 5);
    g.insereAresta(idvB, idvE, 1);

    g.imprime();
    cout << "Tem ciclo: "<< g.isCyclic() << endl << endl;

    Graph result = primG(g);
    result.imprime();
    cout << "Tem ciclo: "<< result.isCyclic() << endl << endl;
}

#endif // __TEST_CASE_PRIM_HPP__
