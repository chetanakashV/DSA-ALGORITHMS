// Given a graph, print the topological sort of the graph
// a topological sort is the order where u appears before v if u->v edge is present. 
// This uses dfs
#include <bits/stdc++.h> 
using namespace std; 

class Graph{
    public: 
    int V; 
    vector<vector<int>> edges; 

    Graph(int x){
        V = x; edges.resize(V); 
    }

    void addEdge(int v, int V); 

    void topologicalSort(); 

    void dfs(int x, vector<bool>& vis, stack<int>& s); 

}; 

void Graph:: addEdge(int v, int V){
    edges[v].push_back(V); 
}

void Graph::dfs(int node, vector<bool>& vis, stack<int>& s){
    vis[node] = true; 
    for(int i = 0; i<edges[node].size(); i++) if(!vis[edges[node][i]]) dfs(edges[node][i], vis, s);
    s.push(node); 
}

void Graph:: topologicalSort(){
    vector<bool> vis(V); stack<int> s; 

    for(int i = 0; i<V; i++) if(!vis[i]) dfs(i, vis, s); 

    while(!s.empty()){ cout<< s.top() << " "; s.pop(); }

}


int main() {

    int n = 6; 
    Graph* g = new Graph(n); 
    g->addEdge(5, 2);
    g->addEdge(5, 0);
    g->addEdge(4, 0);
    g->addEdge(4, 1);
    g->addEdge(2, 3);
    g->addEdge(3, 1);

    g->topologicalSort(); 


    return 0; 
}