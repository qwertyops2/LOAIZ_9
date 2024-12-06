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

void printAdjacencyM(vector<vector<int>>& G) {
	cout << "Матрица смежности: " << endl;
	for (int i = 0; i < G.size(); i++) {
		for (int val : G[i]) {
			cout << val << " ";
		}
		cout << endl;
	}
}





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

int compare(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

void sortAdjacencyList(struct Graph* graph, int N) {
	for (int i = 0; i < N; i++) {
		int count = 0;
		struct node* temp = graph->adjLists[i];
		while (temp != NULL) {
			count++;
			temp = temp->next;
		}

		int* vertices = (int*)malloc(count * sizeof(int));
		temp = graph->adjLists[i];
		int index = 0;
		while (temp != NULL) {
			vertices[index++] = temp->vertex;
			temp = temp->next;
		}

		qsort(vertices, count, sizeof(int), compare);

		temp = graph->adjLists[i];
		index = 0;
		while (temp != NULL) {
			temp->vertex = vertices[index++];
			temp = temp->next;
		}

		free(vertices);
	}
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
	printf("\n");
}

int** createG(int size) {
	int** G = NULL;
	G = (int**)malloc(size * sizeof(int*));
	for (int i = 0; i < size; i++) {
		G[i] = (int*)malloc(size * sizeof(int));
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			G[i][j] = rand() % 2;
			if (i == j) G[i][j] = 0;
			G[j][i] = G[i][j];
		}
	}
	return G;
}

void printG(int** G, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%d ", G[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return;
}

void printGCpp(vector<vector<int>>& G) {
	cout << "мвраомврам: " << endl;
	for (int i = 0; i < G.size(); i++) {
		for (int val : G[i]) {
			cout << val << " ";
		}
		cout << endl;
	}
}

vector<int> BFS_adjList(struct Graph* graph, int start, int size) {
	bool* visited = (bool*)malloc(size * sizeof(bool));
	for (int i = 0; i < size; i++) {
		visited[i] = false;
	}
	int* queue = (int*)malloc(size * sizeof(int));
	vector<int> DIST(size, -1);
	int front = 0, rear = 0;

	visited[start] = true;
	queue[rear++] = start;

	while (front < rear) {
		int currentVertex = queue[front++];

		struct node* temp = graph->adjLists[currentVertex];
		while (temp) {
			int adjVertex = temp->vertex;
			if (!visited[adjVertex]) {
				visited[adjVertex] = true;
				queue[rear++] = adjVertex;
				DIST[temp->vertex] = DIST[temp->vertex] + 1;
			}
			temp = temp->next;
		}
	}
	return DIST;
}

void DFS_adjList(struct Graph* graph, vector<int>& DIST, int v, int start, vector<bool>& visited) {
	if (DIST[v] == -1 || start < DIST[v]) {
		DIST[v] = start;
	}

	visited[v] = true;

    struct node* temp = graph->adjLists[v];
    while (temp != NULL) {
        if (visited[temp->vertex] == 0) {
			DFS_adjList(graph, DIST, temp->vertex, start+1, visited);
        }
        temp = temp->next;
    }
	visited[v] = false;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(12345678);

    int N;
    cout << "Введите количество вершин в графе: ";
    cin >> N;

    vector<vector<int>> adjacencyM = generateAdjacencyM(N);

    printAdjacencyM(adjacencyM);
    int startVertex;
    cout << "Введите начальную вершину (1 - " << N << "): ";
    cin >> startVertex;


    vector<bool> visited(N, false);
    vector<int> DIST_DFS(N, -1);

    auto start_time = clock();
    DFS(adjacencyM, DIST_DFS, startVertex - 1, 0, visited);
    auto end_time = clock();
    auto result_time = ((double)(end_time - start_time));

    cout << endl << "Время выполнения DFS: " << result_time << " миллисекунд." << endl;

    cout << endl << "Расстояния от вершины " << startVertex << " (DFS):" << endl;
    for (int i = 0; i < N; i++) {
        cout << "До вершины " << i + 1 << " расстояние: " << DIST_DFS[i] << endl;
    }

    auto start_time_BFS = clock();
    vector<int> DIST_BFS = bfsDistance(adjacencyM, startVertex - 1);
    auto end_time_BFS = clock();
    auto result_time_BFS = ((double)(end_time_BFS - start_time_BFS));

    cout << endl << "Время выполнения BFS: " << result_time_BFS << " миллисекунд." << endl;

    cout << endl << "Расстояния от вершины " << startVertex << " (BFS):" << endl;
    for (int i = 0; i < N; i++) {
        cout << "До вершины " << i + 1 << " расстояние: " << DIST_BFS[i] << endl;
    }

	struct Graph* graph1 = edges(adjacencyM);
	sortAdjacencyList(graph1, N);
	printGraph(graph1);

	vector<bool> visited2(N, false);
	vector<int> DIST_DFS_al(N, -1);

	auto start_time_al_dfs = clock();
	DFS_adjList(graph1, DIST_DFS_al, startVertex - 1, 0, visited2);
	auto end_time_al_dfs = clock();
	auto result_time_al_dfs = ((double)(end_time_al_dfs - start_time_al_dfs));
	cout << endl << "Время выполнения DFS_AL: " << result_time_al_dfs << " миллисекунд." << endl;
	cout << endl << "Расстояния от вершины " << startVertex << " (DFS_al):" << endl;
	for (int i = 0; i < N; i++) {
		cout << "До вершины " << i + 1 << " расстояние: " << DIST_DFS_al[i] << endl;
	}
	
	vector<int> DIST_BFS_al(N, -1);
	auto start_time_al = clock();
	DIST_BFS_al = BFS_adjList(graph1, 0, N);
	auto end_time_al = clock();
	auto result_time_al = ((end_time_al - start_time_al));
	cout << endl << "Время выполнения BFS_AL: " << result_time_al << " миллисекунд." << endl;
	cout << endl << "Расстояния от вершины " << startVertex << " (BFS_al):" << endl;
	for (int i = 0; i < N; i++) {
		cout << "До вершины " << i + 1 << " расстояние: " << DIST_DFS[i] << endl;
	}
}