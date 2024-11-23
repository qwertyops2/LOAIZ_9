//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <cstdlib>
//#include <ctime>
//#include <Windows.h>
//
//using namespace std;
//
//vector<vector<int>> generateAdjacencyM(int n) {
//    vector<vector<int>> matrix(n, vector<int>(n, 0));
//
//    for (int i = 0; i < n; ++i) {
//        for (int j = i + 1; j < n; ++j) {
//            if (rand() % 2 == 1) {
//                matrix[i][j] = 1;
//                matrix[j][i] = 1;
//            }
//        }
//    }
//    return matrix;
//}
//
//vector<int> bfsDistance(const vector<vector<int>>& G, int start) {
//    int n = G.size();
//    vector<int> DIST(n, -1);
//    queue<int> Q;
//
//    Q.push(start);
//    DIST[start] = 0;
//
//    while (!Q.empty()) {
//        int v = Q.front();
//        Q.pop();
//        cout << v+1 << " ";
//
//        for (int i = 0; i < n; ++i) {
//            if (G[v][i] == 1 && DIST[i] == -1) {
//                Q.push(i);
//                DIST[i] = DIST[v] + 1;
//            }
//        }
//    }
//
//    return DIST;
//}
//
//void printMatrix(const vector<vector<int>>& matrix) {
//    cout << "Матрица смежности:" << endl;
//    for (const auto& row : matrix) {
//        for (int val : row) {
//            cout << val << " ";
//        }
//        cout << endl;
//    }
//}
//
//int main() {
//
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    srand(time(0));
//
//    int n;
//    cout << "Введите количество вершин в графе: ";
//    cin >> n;
//
//    vector<vector<int>> adjacencyM = generateAdjacencyM(n);
//    printMatrix(adjacencyM);
//
//    int startVertex;
//    cout << "Введите начальную вершину (1 - " << n << "): ";
//    cin >> startVertex;
//
//    cout << "Посещенные вершины: " << endl;
//    vector<int> distances = bfsDistance(adjacencyM, startVertex-1);
//
//    cout << endl << "Расстояния от вершины " << startVertex << ":" << endl;
//    for (int i = 0; i < n; ++i) {
//        cout << "До вершины " << i+1 << " расстояние: " << distances[i] << endl;
//    }
//}
