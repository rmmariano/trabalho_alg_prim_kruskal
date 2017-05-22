#ifndef __TEST_CASE_KRUSKAL_HPP__
#define __TEST_CASE_KRUSKAL_HPP__

#include "../algorithms/kruskal.hpp"

void test_case_kruskal_01 () {
    Graph g(true);  //grafo orientado

//Insere vertices
    cout << "================================ Insere vertices ================================"<< endl;
    Vertice v0("Jacarei");
    int idv0 = g.insereVertice(v0);
    cout << "id Jac: " << idv0 << endl;

    Vertice v1("SJC");
    int idv1 = g.insereVertice(v1);
    cout << "id SJC: " << idv1 << endl;

    Vertice v2("Jambeiro");
    int idv2 = g.insereVertice(v2);
    cout << "id Jamb: " << idv2 << endl;

    Vertice v3("Cacapava");
    int idv3 = g.insereVertice(v3);
    cout << "id Caçapava: " << idv3 << endl;

    Vertice v4("Taubate");
    int idv4 = g.insereVertice(v4);
    cout << "id Taubate: " << idv4 << endl;

    Vertice v5("Ubatuba");
    int idv5 = g.insereVertice(v5);
    cout << "id Ubatuba: " << idv5 << endl;

    Vertice v6("Caraguatatuba");
    int idv6 = g.insereVertice(v6);
    cout << "id Caragua: " << idv6 << endl;

    //Insere arestas
       // cout << "\n================================ Insere arestas ================================"<< endl;
        g.insereAresta(idv0, idv1, 8);
        g.insereAresta(idv1, idv0, 8);
        g.insereAresta(idv1, idv2, 20);
        g.insereAresta(idv2, idv1, 20);
        g.insereAresta(idv2, idv3, 40);
        g.insereAresta(idv1, idv3, 30);
        g.insereAresta(idv3, idv1, 30);
        g.insereAresta(idv3, idv4, 25);
        g.insereAresta(idv4, idv3, 25);
        g.insereAresta(idv4, idv5, 100);
        g.insereAresta(idv5, idv4, 100);
        g.insereAresta(idv2, idv6, 70);
        g.insereAresta(idv6, idv1, 90);
        g.insereAresta(idv5, idv6, 27);
        g.insereAresta(idv6, idv5, 27);

        Graph kruskalG = kruskal(g);

        kruskalG.imprimeKruskal();
}

void test_case_kruskal_02 () {
    cout << "Test Case Kruskal - Nao orientado" << endl;

    Graph g(false);  //grafo nao orientado

//Insere vertices
    cout << "================================ Insere vertices ================================"<< endl;
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
    cout << "\n================================ Insere arestas ================================"<< endl;
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
