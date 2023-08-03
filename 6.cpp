// Given a graph, and edges. Return the edges of the minimum spanning tree and total weight of minimum spanning tree of the graph. 
// This uses Kruskal's algorithm to find MST. 
#include <bits/stdc++.h>
using namespace std;

class Edge{
    public:
    int w, src, dest; 
    Edge(int x, int y, int z){
        w = z; src = x; dest = y; 
    }

}; 

class Graph{
    public: 
    int V, E; 
    vector<Edge*> edges; 

    Graph(int x){
        V = x; 
    }

    void addEdge( int x, int y, int w){
        Edge* new_edge = new Edge(x,y,w); 
        edges.push_back(new_edge); E++; 
    }

}; 

int find(vector<int>& parent, int i){
    if(parent[i] == -1) return i; 
    return find(parent, parent[i]); 
}

void Unite(vector<int>& parent, vector<int>& rank, int x, int y){
         x = find(parent, x); y = find(parent, y); 

        if(x == y) return; 

        if(rank[x] >= rank[y]){
            parent[y] = x; 
            rank[x]++; 
        }
        else {
            parent[x] = y; 
            rank[y]++; 
        }
}

    bool compare(Edge* l, Edge* r){
        return l->w < r->w; 
    }



vector<vector<int>> Kruskal_MST(Graph* g, int & weight){

    int V = g->V, E = g->E; 
    vector<int> parent(V,-1), rank(V,0); 
    vector<vector<int>> ans; 

    sort(g->edges.begin(), g->edges.end(), compare); 
    
    for(int i = 0; i<E; i++){
        int x = find(parent, g->edges[i]->src); int y = find(parent, g->edges[i]->dest); 

        if(x== y) continue; 
        Unite(parent, rank, g->edges[i]->src, g->edges[i]->dest); 
        ans.push_back({g->edges[i]->src, g->edges[i]->dest, g->edges[i]->w}); 
        weight += g->edges[i]->w; 
    }

    return ans; 
}

int main() {

    int n = 5; 
    Graph* g = new Graph(n); 

    g->addEdge(0, 1, 10);
    g->addEdge(1, 3, 15);
    g->addEdge(2, 3, 4);
    g->addEdge(2, 0, 6);
    g->addEdge(0, 3, 5);
    g->addEdge(0, 4, 12); 
    g->addEdge(4, 2, 3);
    
    int weight = 0; 

    vector<vector<int>> res; 
    res = Kruskal_MST(g, weight); 


    for(int i = 0; i<res.size(); i++) cout << res[i][0] << " " << res[i][1] << " " << res[i][2] << endl; 
    cout << weight; 

    return 0; 
}