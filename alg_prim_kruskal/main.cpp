#include <iostream>

#include "algorithms/graph.hpp"
#include "tests/test_case_kruskal.hpp"
#include "tests/test_case_prim.hpp"

int main(){

    Graph g(true);  //grafo orientado

    Vertice v0;
    v0.nome = "A";
    int idv0 = g.insereVertice(v0);
    cout << "id v0: " << idv0 << endl;

    Vertice v1;
    v1.nome = "B";
    int idv1 = g.insereVertice(v1);
    cout << "id v1: " << idv1 << endl;

    g.insereAresta(idv0, idv1, 2);  //insere aresta de v0 para v1 com peso 2

    g.removeAresta(idv0, idv1);


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
