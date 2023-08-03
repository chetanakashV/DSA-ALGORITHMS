// Given a graph, perform a bfs for a given node
#include <bits/stdc++.h> 
using namespace std; 

class Graph{
    public: 
    int V; 
    vector<vector<int>> edges; 

    Graph(int n){
        V = n; 
        edges.resize(V); 
    }

    void addEdge(int v, int V){
        edges[v].push_back(V); 
    }

    void bfs(int i); 

    void dfs(int i); 

}; 

void Graph:: bfs(int s){
    queue<int> q; q.push(s); vector<bool> visited(V); 
    cout << "BFS: "; 
    while(!q.empty()){
        int t = q.front(); q.pop(); 
        if(visited[t]) continue; visited[t] = true; 
        cout << t << " "; 
        for(int i = 0 ; i<edges[t].size(); i++) q.push(edges[t][i]); 
    }
    cout << endl; 
    
}

void Graph:: dfs(int n){
    stack<int> s; s.push(n);  vector<bool> visited(V); 
    cout <<  "DFS: "; 
    while(!s.empty()){
        int t = s.top(); s.pop(); 
        if(visited[t]) continue; visited[t] = true; 
        cout << t << " "; 
        for(int i = edges[t].size()-1; i>=0; i--) s.push(edges[t][i]); 
    }
    cout << endl; 
}


int main() {

    int n = 4; 
    Graph* g = new Graph(n); 

    g->addEdge(0, 1);
    g->addEdge(0, 2);
    g->addEdge(1, 2);
    g->addEdge(2, 0);
    g->addEdge(2, 3);
    g->addEdge(3, 3);

    g->bfs(2); 

    g->dfs(2); 


    return 0; 
}