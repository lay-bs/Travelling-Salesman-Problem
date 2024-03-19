#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int grafo[MAX_VERTICES][MAX_VERTICES];
bool visitado[MAX_VERTICES];
int caminho[MAX_VERTICES];
int custo_total = 0;
int num_vertices;

void vizinhoMaisProximo(int vertice_inicial) {
    int atual = vertice_inicial;
    int proximo;

    visitado[atual] = true;
    caminho[0] = atual;

    for (int i = 1; i < num_vertices; i++) {
        int menor_custo = -1;

        for (int j = 0; j < num_vertices; j++) {
            if (!visitado[j] && (menor_custo == -1 || grafo[atual][j] < menor_custo)) {
                menor_custo = grafo[atual][j];
                proximo = j;
            }
        }

        visitado[proximo] = true;
        caminho[i] = proximo;
        custo_total += menor_custo;
        atual = proximo;
    }

    custo_total += grafo[atual][vertice_inicial];
}

int main() {
    // Leitura do número de vértices
    printf("Digite o número de vértices: ");
    scanf("%d", &num_vertices);

    // Leitura da matriz de adjacência do grafo
    printf("Digite a matriz de adjacência:\n");
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            scanf("%d", &grafo[i][j]);
        }
    }

    // Inicializa o vetor de visitados
    for (int i = 0; i < num_vertices; i++) {
        visitado[i] = false;
    }

    // Chama o algoritmo do vizinho mais próximo
    vizinhoMaisProximo(0);

    // Imprime o caminho e o custo total
    printf("Caminho: ");
    for (int i = 0; i < num_vertices; i++) {
        printf("%d ", caminho[i]);
    }
    printf("%d\n", caminho[0]);

    printf("Custo Total: %d\n", custo_total);

    return 0;
}
