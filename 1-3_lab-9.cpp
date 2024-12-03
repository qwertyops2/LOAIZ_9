#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

struct node {
	int vertex;
	struct node* next;
};

struct Graph {
	int numVertices;
	struct node** adjLists;
};

struct node* createNode(int v) {
	struct node* newNode = (node*)malloc(sizeof(struct node));
	newNode->vertex = v;
	newNode->next = NULL;
	return newNode;
}

struct Graph* createAGraph(int vertices) {
	struct Graph* graph = (Graph*)malloc(sizeof(struct Graph));
	graph->numVertices = vertices;

	graph->adjLists = (node**)malloc(vertices * sizeof(struct node*));

	for (int i = 0; i < vertices; i++) {
		graph->adjLists[i] = NULL;
	}

	return graph;
}

void addEdge(struct Graph* graph, int s, int d) {
	struct node* temp = graph->adjLists[s];
	while (temp) {
		if (temp->vertex == d) {
			return;
		}
		temp = temp->next;
	}

	struct node* newNode = createNode(d);
	newNode->next = graph->adjLists[s];
	graph->adjLists[s] = newNode;

	temp = graph->adjLists[d];
	while (temp) {
		if (temp->vertex == s) {
			return;
		}
		temp = temp->next;
	}

	newNode = createNode(s);
	newNode->next = graph->adjLists[d];
	graph->adjLists[d] = newNode;
}


struct Graph* edges(vector<vector<int>>& G) {
	struct Graph* graph = createAGraph(G.size());

	for (int i = 0; i < G.size(); i++) {
		for (int j = i; j < G.size(); j++) {
			if (G[i][j] == 1) {
				addEdge(graph, i, j);
			}
		}
	}
	return graph;
}

void printGraph(struct Graph* graph) {
	for (int v = 0; v < graph->numVertices; v++) {
		struct node* temp = graph->adjLists[v];
		printf("\nVertex %d: ", v + 1);
		while (temp) {
			printf("%d -> ", temp->vertex + 1);
			temp = temp->next;
		}
		printf("\n");
	}
}

vector<vector<int>> generateG(int versh) {
	vector<vector<int>> G(versh, vector<int>(versh, 0));

	for (int i = 0; i < versh; i++) {
		for (int j = i + 1; j < versh; j++) {
			if (rand() % 2 == 1) {
				G[i][j] = 1;
				G[j][i] = 1;
			}
		}
	}
	return G;
}

void printG(const vector<vector<int>>& G) {
	printf("Матрица смежности: \n");
	for (const auto& row : G) {
		for (int val : row) {
			printf("%d ", val);
		}
		printf("\n");
	}
}


void BFS(struct Graph* graph, int N, int v, vector<int>& DIST) {

    DIST.assign(N, -1);

    queue<int> Q;
    Q.push(v);
    DIST[v] = 0;

    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        cout << v + 1 << " ";
		struct node* neighbor = graph->adjLists[v];
        while (neighbor != NULL) {
            if (DIST[neighbor->vertex] == -1) {
                Q.push(neighbor->vertex);
                DIST[neighbor->vertex] = DIST[v] + 1;
            }
			neighbor = neighbor->next;
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

	vector<vector<int>> G = generateG(N);
	struct Graph* graph = edges(G);
	printGraph(graph);

    int startVertex;
    printf("Введите исходную вершину для поиска расстояний (1 - %d): ", N);
    scanf("%d", &startVertex);
    startVertex = startVertex - 1;

    vector<int> DIST;
    BFS(graph, N, startVertex, DIST);

    cout << endl << "Расстояния от вершины " << startVertex << ":" << endl;
    for (int i = 0; i < N; ++i) {
            cout << "До вершины " << i+1 << " расстояние: " << DIST[i] << endl;
    }
}
