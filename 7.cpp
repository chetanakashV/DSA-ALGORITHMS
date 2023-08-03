// Given a graph in form of adjacency lists, find the minimum path from source to all the destinations 
// This is done using dijkstra's algorithm 

#include <bits/stdc++.h> 
using namespace std; 

int findMin(vector<int>& m, vector<bool>& proc){
    int ans = INT_MAX, ind = -1; 
    for(int i = 0; i<m.size(); i++) {
        if(proc[i]) continue; 
        if(ans > m[i]){ ans = m[i]; ind = i; }
    }

    return ind; 
}

vector<int> dijkstra(vector<vector<int>>& graph, int src){
    int n = graph.size(); 
    vector<int> minDist(n, INT_MAX); vector<bool> processed(n, false); 
    minDist[src] = 0; 
    
    for(int i = 0; i<n; i++){
        int t = findMin(minDist, processed); 
        cout << t << " "; 
        processed[t] = true; 

        for(int j = 0; j<n; j++) {
            if(processed[j])continue; if(!graph[j][t]) continue; 
             if(minDist[t] == INT_MAX) continue; 
             if(minDist[t] + graph[j][t] < minDist[j]) minDist[j] = minDist[t] + graph[j][t]; 
        }
        
    }

    return minDist; 
    

}

int main() {

    int src = 0; 
    vector<vector<int>> graph = 
                        { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

            vector<int> ans = dijkstra(graph, src); 

            for(int i = 0; i<ans.size(); i++) cout << i << " " << ans[i] << endl; 

    return 0; 
}