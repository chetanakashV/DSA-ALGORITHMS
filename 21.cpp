// Given a graph, return the topological order of that graph, print cycle if it contains one. 
// It uses Kahn's algorithm to find topological order It basically uses bfs

#include <bits/stdc++.h> 
using namespace std; 

class Graph{
    public: 
    int V; 
    vector<vector<int>> edges; 

    Graph(int x) {
        V = x; 
        edges.resize(V); 
    }

    void TopologicalSort(); 

    void addEdge(int x, int y){ edges[x].push_back(y); }

    void bfs(int node, vector<bool>& vis, queue<int>& q); 

};

void Graph:: bfs(int node, vector<bool>& vis, queue<int>& q){
    vis[node] = true; 
    q.push(node); 
    for(int i = 0; i<edges[node].size(); i++) if(!vis[edges[node][i]]) bfs(edges[node][i], vis, q); 
}

void Graph:: TopologicalSort(){
    
    vector<int> in_degree(V, 0);  queue<int> q; 
    for(int i = 0; i<V; i++) for(int j = 0; j<edges[i].size(); j++) in_degree[edges[i][j]]++; 
    for(int i = 0; i<V; i++) if(in_degree[i] == 0) q.push(i); 
    // cout << q.size(); 
    vector<int> ans; int cnt = 0; 

    while(!q.empty()){
        int temp = q.front(); q.pop(); 
        ans.push_back(temp); cnt++; 

        for(int j = 0; j<edges[temp].size(); j++) {
         in_degree[edges[temp][j]]--;
         if(in_degree[edges[temp][j]] == 0) q.push(edges[temp][j]); 
        }

    }

    if(cnt != V) {cout << "Graph Contains a cycle"; return ; }

    for(int i = 0; i<ans.size(); i++) cout << ans[i] << " "; 

}


int main() {

    int n = 6; 
    Graph * g = new Graph(n); 

    g ->addEdge(5, 2);
    g ->addEdge(5, 0);
    g ->addEdge(4, 0);
    g ->addEdge(4, 1);
    g ->addEdge(2, 3);
    g ->addEdge(3, 1);

    

    g->TopologicalSort(); 


    return 0; 
}