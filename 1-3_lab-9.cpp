#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

void createAdjList(vector<vector<int>>& adjList, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int edge = rand() % 2;
            if (edge == 1) {
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }
}

void printAdjList(const vector<vector<int>>& adjList, int N) {
    printf("Список смежности:\n");
    for (int i = 0; i < N; i++) {
        printf("Вершина %d: ", i+1);
        for (int j : adjList[i]) {
            printf("%d ", j+1);
        }
        printf("\n");
    }
}


void BFS(const vector<vector<int>>& adjList, int N, int v, vector<int>& DIST) {

    DIST.assign(N, -1);

    queue<int> Q;
    Q.push(v);
    DIST[v] = 0;

    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        cout << v + 1 << " ";

        for (int neighbor : adjList[v]) {
            if (DIST[neighbor] == -1) {
                Q.push(neighbor);
                DIST[neighbor] = DIST[v] + 1;
            }
        }
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(2364892365489);

    int N;
    printf("Введите количество вершин в графе: ");
    scanf("%d", &N);

    vector<vector<int>> adjList(N);
    createAdjList(adjList, N);
    printAdjList(adjList, N);

    int startVertex;
    printf("Введите исходную вершину для поиска расстояний (1 - %d): ", N);
    scanf("%d", &startVertex);
    startVertex = startVertex - 1;

    vector<int> DIST;
    BFS(adjList, N, startVertex, DIST);

    cout << endl << "Расстояния от вершины " << startVertex << ":" << endl;
    for (int i = 0; i < N; ++i) {
            cout << "До вершины " << i+1 << " расстояние: " << DIST[i] << endl;
    }
}
