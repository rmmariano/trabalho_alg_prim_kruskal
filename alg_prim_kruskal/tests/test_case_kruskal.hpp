#ifndef __TEST_CASE_KRUSKAL_HPP__
#define __TEST_CASE_KRUSKAL_HPP__

#include "../algorithms/kruskal.hpp"

void test_case_kruskal_01 () {
    cout << "\n================================ Kruskal - Teste 1 ================================"<< endl;

    Graph g(false);  //grafo nao orientado

//Insere vertices    
    Vertice v0("Jacarei");
    int idv0 = g.insereVertice(v0);

    Vertice v1("SJC");
    int idv1 = g.insereVertice(v1);

    Vertice v2("Jambeiro");
    int idv2 = g.insereVertice(v2);

    Vertice v3("Cacapava");
    int idv3 = g.insereVertice(v3);

    Vertice v4("Taubate");
    int idv4 = g.insereVertice(v4);

    Vertice v5("Ubatuba");
    int idv5 = g.insereVertice(v5);

    Vertice v6("Caraguatatuba");
    int idv6 = g.insereVertice(v6);

//Insere arestas
    g.insereAresta(idv0, idv1, 8);
    g.insereAresta(idv1, idv2, 20);
    g.insereAresta(idv2, idv3, 40);
    g.insereAresta(idv1, idv3, 30);
    g.insereAresta(idv3, idv4, 25);
    g.insereAresta(idv4, idv5, 100);
    g.insereAresta(idv2, idv6, 70);
    g.insereAresta(idv6, idv1, 90);
    g.insereAresta(idv5, idv6, 27);

    g.imprime();
    cout << "Tem ciclo: "<< g.isCyclic() << endl << endl;

    Graph kruskalG = kruskal(g);

    kruskalG.imprime();
    cout << "Tem ciclo: "<< kruskalG.isCyclic() << endl << endl;
}

void test_case_kruskal_02 () {
    cout << "\n================================ Kruskal - Teste 2 ================================"<< endl;

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

    Graph result = kruskal(g);
    result.imprime();
    cout << "Tem ciclo: "<< result.isCyclic() << endl << endl;
}

#endif // __TEST_CASE_KRUSKAL_HPP__
