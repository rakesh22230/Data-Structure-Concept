#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> edgesWeightPair;

class Graph {
    int V;
    list<edgesWeightPair>* adj; // adjacency list
public:
    Graph(int V) {
        this->V = V;
        adj = new list<edgesWeightPair>[V]; // Initialize adjacency list
    }

    // Add an edge from u to v with weight w
    void addEdges(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Undirected graph
    }

    // Display the adjacency list
    void PrintNeighbour() {
        for (int i = 0; i < V; i++) {
            cout << i << " : ";
            for (auto it = adj[i].begin();it != adj[i].end();it++ ) {
                cout << "(" << (*it).first << "," << (*it).second << ") ";
            }
            cout << endl;
        }
    }

    //---------- BFS --- > Breadth First Search Traversal 
    void BFS(int source){
        vector<bool> visited(V,false);
        queue<int> Q;
        Q.push(source);
        visited[source] = true;
        
        while(!Q.empty()){
            int u = Q.front();
            cout<<u<<" ";
            Q.pop();
           
            for( auto elements: adj[u] ){
                int v = elements.first;
                if(visited[v] != true ){
                    visited[v] = true;
                    Q.push(v);
                }
            }
        }
    }
    //---------DFS-------> Depth First Search Traversal
    void DFS(int source){
        static vector<bool> visited(V,false);
        queue<int>Q;
        visited[source] = true;
        cout<<source<<" ";

        for( auto elements: adj[source]) {
             int v = elements.first;
            if( visited[v] != true ){
                  DFS(v);
            }
        }
    }

};

int main() {
    int V, E,s1,s2;
    cout << "Enter the Vertices: ";
    cin >> V;
    cout << "Enter the Edges: ";
    cin >> E;

    Graph g(V);
    cout << "Enter edges as (u v w):\n";

    for (int i = 0; i < E; i++) {  // take input u, v, w
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdges(u, v, w);
    }

    g.PrintNeighbour();

    cout<<endl<<endl;
    cout<<"Enter the source value: ";
    cin>>s1;
    cout<<"BFS Traversal: ";
    g.BFS(s1);
    
    cout<<endl;
    cout<<"Enter the source value: ";
    cin>>s2;
    cout<<"DFS Traversal: ";
    g.DFS(s2);
    
    
    cout<<endl;


    return 0;
}


/*
7 10


0 1 7
0 2 1
0 5 3
1 3 11
2 3 3
2 5 8
3 6 1
4 5 6
5 6 2
6 4 4

*/
