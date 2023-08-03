/* UNION FIND: It is an algorithm which performs two useful operations on disjoint set data structure
1. Find: Determine which subset a particular element is in
2. Union: Join two subsets into a single subset. Check if both belong to same subset. If not, we cannot perform union
*/

#include <bits/stdc++.h> 
using namespace std; 
class Edge{
    public:
    int src; 
    int dest; 

    Edge(int x, int y){src = x; dest = y; }
}; 

class Graph{
    public:
    int V, E; 
    vector<Edge*> edges; 

    Graph(int x, int y) {
        V = x; E = y; 
    }

    bool isCyclic(); 

}; 

int find(vector<int>& parent, int i){
    if(parent[i] == i) return i; 
    
    return find(parent, parent[i]); 
}

void Union(int i, int j, vector<int>& parent){
    parent[i] = j; 
}


bool Graph:: isCyclic(){
    vector<int> parent(V, 0); 
    for(int i = 0; i<V; i++) parent[i] = i; 

    for(int i = 0; i<E; i++){
        int x = find(parent, edges[i]->src); int  y = find(parent, edges[i]->dest); 

        if(x == y) return true; 

        Union(x,y, parent); 

    }

    return false; 
}

int main() {

    int N = 3, E = 3; 

    Graph* g = new Graph(N, E); 

    vector<pair<int,int>> ed = {{0,1}, {1,2}, {0,2}}; 

    for(int i = 0; i<E; i++) {
        Edge* temp = new Edge(ed[i].first, ed[i].second); 
        g->edges.push_back(temp); 
    } 

    if(g->isCyclic()) cout << "Graph is cyclic"; else  cout << "Graph is acyclic"; 
   

    return 0; 
}