#include "lista_adjacencia.hpp"
#include <iostream>

ListaAdjacencia::ListaAdjacencia()
    : head(nullptr), numVertices(0), numArestas(0) {}

ListaAdjacencia::~ListaAdjacencia() {
    while (head) {
        Vertice* v = head;
        head = head->next;
        Aresta* a = v->arestas;
        while (a) {
            Aresta* aux = a;
            a = a->proxVertice;
            delete aux;
        }
        delete v;
    }
}

int ListaAdjacencia::get_numArestas() const {
    return numArestas / 2;
}

int ListaAdjacencia::get_numVertices() const {
    return numVertices;
}

void ListaAdjacencia::adicionaVertice(int id) {
    if (buscaVertice(id) == nullptr) {
        head = new Vertice(id, nullptr, head);
        numVertices++;
    }
}

void ListaAdjacencia::adicionaAresta(int v, int w) {
    Vertice* V = buscaVertice(v);
    if (!V) {
        adicionaVertice(v);
        V = head;
    }

    Vertice* W = buscaVertice(w);
    if (!W) {
        adicionaVertice(w);
    }

    if (V->arestas == nullptr) {
        V->arestas = new Aresta(w);
    } else {
        Aresta* tmp = V->arestas;
        while (tmp->proxVertice)
            tmp = tmp->proxVertice;
        tmp->proxVertice = new Aresta(w);
    }

    numArestas++;
}

int ListaAdjacencia::grau(int v) const {
    Vertice* aux = buscaVertice(v);
    if (!aux) exit(1);
    
    int gVertice = 0;
    for (Aresta* tmp = aux->arestas; tmp; tmp = tmp->proxVertice)
        ++gVertice;
    return gVertice;
}

int ListaAdjacencia::grau_min() const {
    if (!head) return 0;
    int gMin = grau(head->id);

    for (Vertice* v = head->next; v; v = v->next) {
        int vg = grau(v->id);
        if (vg < gMin) gMin = vg;
    }
    return gMin;
}

int ListaAdjacencia::grau_max() const {
    if (!head) return 0;
    int gMax = grau(head->id);

    for (Vertice* v = head->next; v; v = v->next) {
        int vg = grau(v->id);
        if (vg > gMax) gMax = vg;
    }
    return gMax;
}

void ListaAdjacencia::printVizinhos(int v) const {
    Vertice* aux = buscaVertice(v);
    if (!aux) return;

    for (Aresta* a = aux->arestas; a; a = a->proxVertice)
        std::cout << a->vertDestino << " ";
    std::cout << "\n";
}
