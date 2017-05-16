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

    cout << "\n\nComeço execução prim\n";

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
    cout << "Fim execução prim\n";
}

void test_case_prim_02 () {
    cout << "Test Case Prim 02" << endl;

}

#endif // __TEST_CASE_PRIM_HPP__
