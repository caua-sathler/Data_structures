#include "graph.hpp"

Grafo::Grafo() {};
Grafo::~Grafo() {};

void Grafo::InsereVertice(int id) {
    vertices.adicionaVertice(id);
}

void Grafo::InsereAresta(int v, int w) {
    vertices.adicionaAresta(v, w);
}

int Grafo::QuantidadeArestas() {
    return vertices.get_numArestas();
}

int Grafo::QuantidadeVertices() {
    return vertices.get_numVertices();
}

int Grafo::GrauMinimo() {
    return vertices.grau_min();
}

int Grafo::GrauMaximo() {
    return vertices.grau_max();
}

void Grafo::ImprimeVizinhos(int v) {
    vertices.printVizinhos(v);
}