//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//#include <vector>
//#include <cstdlib>
//#include <ctime>
//#include <Windows.h>
//
//using namespace std;
//
//void createG(vector<vector<int>>& G, int N) {
//    for (int i = 0; i < N; i++) {
//        for (int j = i + 1; j < N; j++) {
//            int edge = rand() % 2;
//            G[i][j] = edge;
//            G[j][i] = edge;
//        }
//    }
//
//    for (int i = 0; i < N; i++) {
//        G[i][i] = 0;
//    }
//}
//
//void printG(const vector<vector<int>>& G) {
//    cout << "Матрица смежности:" << endl;
//    for (const auto& row : G) {
//        for (int val : row) {
//            cout << val << " ";
//        }
//        cout << endl;
//    }
//}
//
//void DFS(const vector<vector<int>>& G, vector<int>& DIST, int v, int start, vector<bool>& visited) {
//    if (DIST[v] == -1 || start < DIST[v]) {
//        DIST[v] = start;
//    }
//
//    visited[v] = true;
//
//    cout << v + 1 << " ";
//
//    for (int i = 0; i < G.size(); i++) {
//        if (G[v][i] == 1 && !visited[i]) {
//            DFS(G, DIST, i, start + 1, visited);
//        }
//    }
//
//    visited[v] = false;
//}
//
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    srand(12345678);
//
//    int N;
//    cout << "Введите количество вершин в графе: ";
//    cin >> N;
//
//    vector<vector<int>> G(N, vector<int>(N, 0));
//    createG(G, N);
//    printG(G);
//
//    int startVertex;
//    cout << "Введите начальную вершину (1 - " << N << "): ";
//    cin >> startVertex;
//
//    vector<int> DIST(N, -1);
//    cout << "Посещенные вершины: " << endl;
//    vector<bool> visited(G.size(), false);
//    DFS(G, DIST, startVertex - 1, 0, visited);
//
//    cout << endl << "Расстояния от вершины " << startVertex << ":" << endl;
//    for (int i = 0; i < N; i++) {
//        cout << "До вершины " << i + 1 << " расстояние: " << DIST[i] << endl;
//    }
//
//    return 0;
//}
