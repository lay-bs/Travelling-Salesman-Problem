#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INF 999999

// Estrutura para representar uma cidade
typedef struct {
    int x;
    int y;
} City;

// Função para calcular a distância entre duas cidades
int distance(City a, City b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return (int)sqrt(dx * dx + dy * dy);
}

// Função para encontrar o índice do menor valor em um array
int findMin(int array[], bool visited[], int size) {
    int minIndex = -1;
    int minValue = INF;

    for (int i = 0; i < size; i++) {
        if (!visited[i] && array[i] < minValue) {
            minValue = array[i];
            minIndex = i;
        }
    }

    return minIndex;
}

// Função para encontrar o caminho mais curto usando árvore binária
void findShortestPath(City cities[], int numCities) {
    bool visited[numCities];
    int distances[numCities];
    int parent[numCities];

    // Inicializa os arrays de distâncias e visitados
    for (int i = 0; i < numCities; i++) {
        distances[i] = INF;
        visited[i] = false;
    }

    // Define a cidade inicial como a primeira cidade
    distances[0] = 0;
    parent[0] = -1;

    // Encontra o caminho mais curto
    for (int i = 0; i < numCities - 1; i++) {
        int current = findMin(distances, visited, numCities);
        visited[current] = true;

        for (int j = 0; j < numCities; j++) {
            if (!visited[j]) {
                int dist = distance(cities[current], cities[j]);
                if (dist < distances[j]) {
                    distances[j] = dist;
                    parent[j] = current;
                }
            }
        }
    }

    // Imprime o caminho mais curto
    printf("Caminho mais curto:\n");

    int current = numCities - 1;
    while (current != -1) {
        printf("%d -> ", current);
        current = parent[current];
    }

    printf("0\n");

    // Imprime a distância total do caminho mais curto
    printf("Distancia total: %d\n", distances[numCities - 1]);
}

int main() {
    int numCities;

    printf("Digite o numero de cidades: ");
    scanf("%d", &numCities);

    City cities[numCities];

    printf("Digite as coordenadas das cidades:\n");
    for (int i = 0; i < numCities; i++) {
        printf("Cidade %d: ", i);
        scanf("%d %d", &cities[i].x, &cities[i].y);
    }

    findShortestPath(cities, numCities);

    return 0;
}
