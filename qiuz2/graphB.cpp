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
        int vertices;
        Node **list;
        Graph(int v) {
            vertices = v;
            list = new Node*[vertices];
            for(int i = 0; i < vertices; i++) {
                list[i] = NULL;
            }
        }
        void add(int v1,int v2, int we) {
            Node *newNode = new Node(v2,we);
            if(list[v1] == NULL) {
                list[v1] = newNode;
            } else {
                Node *temp = list[v1];
                while(temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
            Node *sort = list[v1];
            Node *tempS = NULL;
            while(sort != NULL) {
                tempS = sort->next;
                while(tempS != NULL) {
                    if(sort->data > tempS->data) {
                        int tempd = sort->data;
                        int tempw = sort->weight;
                        sort->data = tempS->data;
                        sort->weight = tempS->weight;
                        tempS->data = tempd;
                        tempS->weight = tempw;
                    }
                    tempS = tempS->next;
                }
                sort = sort->next;
            }
        }
        void dfsRecusive(int start, bool *visit) {
            visit[start] = true;
            cout << start << " ";
            Node *temp = list[start];
            while(temp != NULL) {
                if(!visit[temp->data]) {
                    dfsRecusive(temp->data,visit);
                }
                temp = temp->next;
            }
        }
        void dfs(int start) {
            bool *visit = new bool[vertices];
            for(int i = 0; i < vertices; i++) {
                visit[i] = false;
            }
            dfsRecusive(start,visit);
        }
        void bfs(int start) {
             bool *visit = new bool[vertices];
            for(int i = 0; i < vertices; i++) {
                visit[i] = false;
            }
            queue<int> q;
            visit[start] = true;
            q.push(start);
            while(!q.empty()) {
                int cur = q.front();
                cout << cur << " ";
                q.pop();
                Node *temp = list[cur];
                while(temp != NULL) {
                    if(!visit[temp->data]) {
                        visit[temp->data] = true;
                        q.push(temp->data);
                    }
                    temp = temp->next;
                }
            }
        }
};