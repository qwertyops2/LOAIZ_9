//#include <iostream>
//#include <vector>
//#include <cstdlib>
//#include <ctime>
//#include <Windows.h>
//
//using namespace std;
//
//void createGraph(vector<vector<int>>& adjList, int N) {
//    for (int i = 0; i < N; i++) {
//        for (int j = i + 1; j < N; j++) {
//            int edge = rand() % 2;
//            if (edge) {
//                adjList[i].push_back(j);
//                adjList[j].push_back(i);
//            }
//        }
//    }
//}
//
//void printGraph(const vector<vector<int>>& adjList) {
//    for (int i = 0; i < adjList.size(); i++) {
//        cout << i + 1 << ": ";
//        for (int next : adjList[i]) {
//            cout << next + 1 << " ";
//        }
//        cout << endl;
//    }
//}
//
//
//void DFS(const vector<vector<int>>& adjList, vector<int>& DIST, int v, int currentDist, vector<bool>& visited) {
//    if (DIST[v] == -1 || currentDist < DIST[v]) {
//        DIST[v] = currentDist;
//    }
//
//    visited[v] = true;
//
//    for (int next : adjList[v]) {
//        if (!visited[next]) {
//            DFS(adjList, DIST, next, currentDist + 1, visited);
//        }
//    }
//
//    visited[v] = false;
//}
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
//    vector<vector<int>> adjList(N);
//    createGraph(adjList, N);
//    printGraph(adjList);
//
//    int startVertex;
//    cout << "Введите начальную вершину (1 - " << N << "): ";
//    cin >> startVertex;
//
//    vector<int> DIST(N, -1);
//    vector<bool> visited(N, false);
//
//    DFS(adjList, DIST, startVertex - 1, 0, visited);
//
//    cout << endl << "Расстояния от вершины " << startVertex << ":" << endl;
//    for (int i = 0; i < N; i++) {
//        cout << "До вершины " << i + 1 << " расстояние: " << DIST[i] << endl;
//    }
//
//    return 0;
//}
