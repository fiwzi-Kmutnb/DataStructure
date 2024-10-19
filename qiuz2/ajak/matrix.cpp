// C++ program to demonstrate Adjacency Matrix
// representation of undirected and unweighted graph
#include <bits/stdc++.h>
#include <vector>
using namespace std;

void bfs(vector< vector<int> >& adj, int s) 
{
    // Create a queue for BFS
    queue<int> q;  
    
    // Initially mark all the vertices as not visited
    // When we push a vertex into the q, we mark it as 
    // visited
    vector<bool> visited(adj.size(), false);

    // Mark the source node as visited and 
    // enqueue it
    visited[s] = true;
    q.push(s);

    // Iterate over the queue
    while (!q.empty()) {
      
        // Dequeue a vertex from queue and print it
        int curr = q.front();
        q.pop();
        cout << curr << " ";

        // Get all adjacent vertices of the dequeued 
        // vertex curr If an adjacent has not been 
        // visited, mark it visited and enqueue it
        for (int i=0; i<adj[curr].size(); i++){
            if (adj[curr][i] == 1) {			
				if (!visited[i]) {
                	visited[i] = true;
                	q.push(i);
            	}
            }
        }
    }
}



void addEdge(vector<vector<int> > &mat, int i, int j)
{
    mat[i][j] = 1;
    mat[j][i] = 1; // Since the graph is undirected
}

void displayMatrix(vector<vector<int> > &mat)
{
    int V = mat.size();
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int V, E;
    cin >> V;
    vector<vector<int> > mat(V, vector<int>(V, 0));
	cin >> E;
	for (int i=0; i<E; i++){
		int from, to;
		cin >> from >> to;
		addEdge(mat, from, to);
	}
//    // Now add edges one by one
//    addEdge(mat, 0, 1);
//    addEdge(mat, 0, 2);
//    addEdge(mat, 1, 2);
//    addEdge(mat, 2, 3);

    /* Alternatively we can also create using below
       code if we know all edges in advacem

     vector<vector<int>> mat = {{ 0, 1, 0, 0 },
                               { 1, 0, 1, 0 },
                               { 0, 1, 0, 1 },
                               { 0, 0, 1, 0 } }; */

    cout << "Adjacency Matrix Representation" << endl;
    displayMatrix(mat);
    cout << "BFS: ";
	bfs(mat, 0);

    return 0;
}
