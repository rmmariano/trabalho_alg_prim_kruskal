QT += core
QT -= gui

TARGET = alg_prim_kruskal
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

TEMPLATE = app

SOURCES += main.cpp \
    vertice.cpp \
    aresta.cpp

HEADERS += \
    algorithms/graph_def.hpp \
    algorithms/graph.hpp \
    algorithms/kruskal.hpp \
    algorithms/prim.hpp \
    tests/test_case_prim.hpp \
    tests/test_case_kruskal.hpp \
    vertice.hpp \
    aresta.hpp

