#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <Windows.h>

using namespace std;

vector<vector<int>> generateAdjacencyM(int n) {
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (rand() % 2 == 1) {
                matrix[i][j] = 1;
                matrix[j][i] = 1;
            }
        }
    }
    return matrix;
}

void DFS(const vector<vector<int>>& G, vector<int>& DIST, int v, int start, vector<bool>& visited) {
    if (DIST[v] == -1 || start < DIST[v]) {
        DIST[v] = start;
    }

    visited[v] = true;

    for (int i = 0; i < G.size(); i++) {
        if (G[v][i] == 1 && !visited[i]) {
            DFS(G, DIST, i, start + 1, visited);
        }
    }

    visited[v] = false;
}

vector<int> bfsDistance(const vector<vector<int>>& G, int start) {
    int n = G.size();
    vector<int> DIST(n, -1);
    queue<int> Q;

    Q.push(start);
    DIST[start] = 0;

    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();

        for (int i = 0; i < n; ++i) {
            if (G[v][i] == 1 && DIST[i] == -1) {
                Q.push(i);
                DIST[i] = DIST[v] + 1;
            }
        }
    }

    return DIST;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(12345678);

    int N;
    cout << "Введите количество вершин в графе: ";
    cin >> N;

    vector<vector<int>> adjacencyM = generateAdjacencyM(N);

    int startVertex;
    cout << "Введите начальную вершину (1 - " << N << "): ";
    cin >> startVertex;


    vector<bool> visited(N, false);
    vector<int> DIST_DFS(N, -1);

    auto start_time = chrono::high_resolution_clock::now();
    DFS(adjacencyM, DIST_DFS, startVertex - 1, 0, visited);
    auto end_time = chrono::high_resolution_clock::now();
    chrono::duration<double> result_time = end_time - start_time;

    cout << endl << "Время выполнения DFS: " << result_time.count() << " миллисекунд." << endl;

    cout << endl << "Расстояния от вершины " << startVertex << " (DFS):" << endl;
    for (int i = 0; i < N; i++) {
        cout << "До вершины " << i + 1 << " расстояние: " << DIST_DFS[i] << endl;
    }

    auto start_time_BFS = chrono::high_resolution_clock::now();
    vector<int> DIST_BFS = bfsDistance(adjacencyM, startVertex - 1);
    auto end_time_BFS = chrono::high_resolution_clock::now();
    chrono::duration<double> result_time_BFS = end_time_BFS - start_time_BFS;

    cout << endl << "Время выполнения BFS: " << result_time_BFS.count() << " миллисекунд." << endl;

    cout << endl << "Расстояния от вершины " << startVertex << " (BFS):" << endl;
    for (int i = 0; i < N; i++) {
        cout << "До вершины " << i + 1 << " расстояние: " << DIST_BFS[i] << endl;
    }
}
