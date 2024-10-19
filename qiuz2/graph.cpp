#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

class Node {
public:
    int data;
    int weight;
    Node *next;
    Node(int data, int weight) {
        this->data = data;
        this->weight = weight;
        this->next = NULL;
    }
};

class Graph {
public:
    Node **adjList;
    int vertices;
    Graph(int vertices) {
        this->vertices = vertices;
        adjList = new Node*[vertices];
        for (int i = 0; i < vertices; i++) {
            adjList[i] = NULL;
        }
    }

    void addEdge(int v1, int v2, int weight) {
        Node* newNodev2 = new Node(v2, weight);
        if(adjList[v1] == NULL) {
            adjList[v1] = newNodev2;
        } else {
            Node* temp = adjList[v1];
            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNodev2;
        }

        Node* nodeSort = adjList[v1];
        Node* temp = NULL;
        while(nodeSort != NULL) {
            temp = nodeSort->next;
            while(temp != NULL) {
                if(nodeSort->data > temp->data) {
                    int tempData = nodeSort->data;
                    int tempWeight = nodeSort->weight;
                    nodeSort->data = temp->data;
                    nodeSort->weight = temp->weight;
                    temp->data = tempData;
                    temp->weight = tempWeight;
                }
                temp = temp->next;
            }
            nodeSort = nodeSort->next;
        }
    }
    void printAll() {
        for (int i = 0; i < vertices; i++) {
            cout << i << " ";
            Node* temp = adjList[i];
            while(temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
    void dfsUtil(int v, bool visited[]) {
        visited[v] = true;
        cout << v << " ";

        Node* temp = adjList[v];
        while (temp != NULL) {
            if (!visited[temp->data]) {
                dfsUtil(temp->data, visited);
            }
            temp = temp->next;
        }
    }
    void dfs(int start) {
        bool *visited = new bool[vertices];
        for (int i = 0; i < vertices; i++) {
            visited[i] = false;
        }

        dfsUtil(start, visited);

        delete[] visited;
    }

    void bfs(int start) {
        bool *visited = new bool[vertices];
        for (int i = 0; i < vertices; i++) {
            visited[i] = false;
        }

        queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int v = q.front();
            cout << v << " ";
            q.pop();

            Node* temp = adjList[v];
            while (temp != NULL) {
                if (!visited[temp->data]) {
                    visited[temp->data] = true;
                    q.push(temp->data);
                }
                temp = temp->next;
            }
        }

        delete[] visited;
    }
};

int main() {
    int vertices;
    cin >> vertices;
    Graph* graph = new Graph(vertices);

    char key;
    int start, end, weight;

    while (cin >> key && key != 'q') {
        switch (key) {
            case 'e':
                cin >> start >> end >> weight;
                graph->addEdge(start, end, weight);
                break;
            case 's':
                graph->printAll();
                break;
            case 'd':
                cin >> start;
                graph->dfs(start);
                break;
            case 'b':
                cin >> start;
                graph->bfs(start);
                break;
            default:
                return 0;
        }
    }

    return 0;
}