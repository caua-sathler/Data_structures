#ifndef LISTA_ADJACENCIA_HPP
#define LISTA_ADJACENCIA_HPP

class ListaAdjacencia {
private:
    struct Aresta {
        int vertDestino;
        Aresta* proxVertice;
        Aresta(int d, Aresta* n = nullptr)
            : vertDestino(d), proxVertice(n) {}
    };

    struct Vertice {
        int id;
        Aresta* arestas;
        Vertice* next;
        Vertice(int id, Aresta* a = nullptr, Vertice* n = nullptr)
            : id(id), arestas(a), next(n) {}
    };

    Vertice* head;
    int numVertices;
    int numArestas;

    Vertice* buscaVertice(int id) const {
        for (Vertice* atual = head; atual != nullptr; atual = atual->next)
            if (atual->id == id)
                return atual;
        return nullptr;
    }

public:
    ListaAdjacencia();
    ~ListaAdjacencia();

    void adicionaVertice(int v);
    void adicionaAresta(int v, int w);

    int get_numVertices() const;
    int get_numArestas() const;

    int grau(int v) const;
    int grau_min() const;
    int grau_max() const;

    void printVizinhos(int v) const;
};

#endif
