#include "graph.hpp"
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    Grafo grafo;
    int numVertices = 0;
    std::cin >> numVertices;

    for (int i = 0; i < numVertices; ++i) {
        grafo.InsereVertice(i);

        int numVizinhos = 0;
        std::cin >> numVizinhos;
        for (int j = 0; j < numVizinhos; ++j) {
            int viz = 0;
            std::cin >> viz;
            grafo.InsereAresta(i, viz);
        }
    }

    std::string flag = argv[1];
    if (flag == "-d") {
        std::cout << grafo.QuantidadeVertices() << "\n"
                  << grafo.QuantidadeArestas() << "\n"
                  << grafo.GrauMinimo()         << "\n"
                  << grafo.GrauMaximo()         << "\n";
    }
    else if (flag == "-n") {
        for (int i = 0; i < numVertices; ++i)
            grafo.ImprimeVizinhos(i);
    }
    else if (flag == "-k") {
        bool completo = (grafo.GrauMaximo() == grafo.GrauMinimo()
                         && grafo.GrauMaximo() == numVertices - 1);
        std::cout << (completo ? "1\n" : "0\n");
    }
    return 0;
}
