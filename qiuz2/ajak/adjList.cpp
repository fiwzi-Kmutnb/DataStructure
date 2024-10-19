#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// Recursive function for DFS traversal
void DFSRec(vector<vector<int> > &adj, vector<bool> &visited, int s){
  
    visited[s] = true;

    // Print the current vertex
    cout << s << " ";

    // Recursively visit all adjacent vertices
    // that are not visited yet
    for (int i=0; i<adj[s].size();i++){
    	int x = adj[s][i];
    	if (visited[x] == false)
            DFSRec(adj, visited, x);
	}
        
}

// Main DFS function that initializes the visited array
// and call DFSRec
void DFS(vector< vector<int> > &adj, int s){
    vector<bool> visited(adj.size(), false);
    DFSRec(adj, visited, s);
}


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
        for (int i=0; i<adj[curr].size();i++) {
        	int x = adj[curr][i];
            if (!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}



// Function to add an edge between two vertices
void addEdge(vector<vector<int> > & adj, int i, int j) {
    adj[i].push_back(j);
    adj[j].push_back(i); // Undirected
}

// Function to display the adjacency list
void displayAdjList(const vector<vector<int> >& adj) {
    for (int i = 0; i < adj.size(); i++) {
        cout << i << ": "; // Print the vertex
        int length = adj[i].size();
        for (int j=0; j<length; j++ ) {
            cout << adj[i][j] << " "; // Print its adjacent
        }
        cout << endl; 
    }
}

// Main function
int main() {
    // Create a graph with 4 vertices and no edges
    int V = 4;
    vector<vector<int> > adj(V); 

    // Now add edges one by one
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);

    cout << "Adjacency List Representation:" << endl;
    displayAdjList(adj);
    cout << "BFS: ";
    bfs(adj, 0);

	cout << "DFS: ";
    DFS(adj, 0);
    return 0;
}
