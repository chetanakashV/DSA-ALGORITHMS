#include <bits/stdc++.h> 
using namespace std; 

class Edge{
    public: 
    int weight, src, dest; 

    Edge(){ src = -1; dest = -1; weight = -1; }
}; 

class Graph{
    public: 
    int V, E; 
    vector<Edge*> edges; 

    Graph(int x, int y){
        V = x;  E = y; 
    }

    vector<int> BellmanFord(int src); 

};

vector<int> Graph:: BellmanFord(int s){
   
    vector<int>minDist(V, INT_MAX); minDist[s] = 0; 

    for(int i = 0; i<V; i++){
        for(int j = 0; j< E; j++){
            int s = edges[j]->src, e = edges[j]->dest, w = edges[j]->weight; 
            if(minDist[s] == INT_MAX) continue; 
            if(minDist[s] + w < minDist[e]) minDist[e] = minDist[s] + w; 
        }
    }

    
         for(int j = 0; j< E; j++){
            int s = edges[j]->src, e = edges[j]->dest, w = edges[j]->weight; 
            if(minDist[s] == INT_MAX) continue; 
            if(minDist[s] + w < minDist[e]) return {}; 
        }
    

    return minDist; 

}

int main() {

    int n = 5, E = 5; ; int s = 1;
    Graph* g= new Graph(n, E); 

    for(int i = 0; i<E; i++) g->edges.push_back(new Edge()); 

    g->edges[0]->src = 1;
    g->edges[0]->dest = 0;
    g->edges[0]->weight = 5;
  
    // add edges 0-2 (or A-C in above figure)
    g->edges[1]->src = 1;
    g->edges[1]->dest = 2;
    g->edges[1]->weight = -2;
  
    // add edges 1-2 (or B-C in above figure)
    g->edges[2]->src = 1;
    g->edges[2]->dest = 4;
    g->edges[2]->weight = 6;
  
    // add edges 1-3 (or B-D in above figure)
    g->edges[3]->src = 2;
    g->edges[3]->dest = 3;
    g->edges[3]->weight = 3;
  
    // add edges 1-4 (or B-E in above figure)
    g->edges[4]->src = 3;
    g->edges[4]->dest = 1;
    g->edges[4]->weight = -4;
  
    // add edges 3-2 (or D-C in above figure)
    // g->edges[5]->src = 3;
    // g->edges[5]->dest = 2;
    // g->edges[5]->weight = 5;
  
    // // add edges 3-1 (or D-B in above figure)
    // g->edges[6]->src = 3;
    // g->edges[6]->dest = 1;
    // g->edges[6]->weight = 1;
  
    // // add edges 4-3 (or E-D in above figure)
    // g->edges[7]->src = 4;
    // g->edges[7]->dest = 3;
    // g->edges[7]->weight = -3;

    vector<int> ans = g->BellmanFord(s); 

    // for(int i = 0; i<E; i++) cout << g->edges[i]->src << g->edges[i]->dest << g->edges[i]->weight<<endl; 

    if(ans.size() == 0) cout << "Graph contains a negative cycle"; 

    for(int i = 0; i<ans.size(); i++) cout << i << " " << ans[i] << endl; 

    return 0; 
}