// Lee's algorithm: it is to find shortest path from a source to destination in a maze(matrix), It uses BFS to traverse through the matrix. It does Give TLE for some cases. 

#include <bits/stdc++.h> 
using namespace std; 

struct Point{
    int x; 
    int y; 
    int dist = 0; 
}; 

bool valid(Point i, vector<vector<int>>& matrix, vector<vector<bool>>& visited){
    if(i.x <0 || i.y <0 || i.x >= matrix.size() || i.y >= matrix[0].size() || visited[i.x][i.y] 
    || matrix[i.x][i.y] == 0) return false; 

    return true; 
}

int traverse(vector<vector<int>>& matrix, Point src, Point dest){
    int m = matrix.size(), n = matrix[0].size(); int ans = -1; 
    queue<Point> q; q.push(src); vector<vector<bool>> vis(m, vector<bool>(n)); 
    if(matrix[src.x][src.y] == 0) return -1; 

    vector<vector<int>> dir = {{0,1}, {0, -1}, {1, 0}, {-1, 0}}; 

    while(!q.empty()){
        Point temp = q.front(); q.pop(); 
        vis[temp.x][temp.y] = true; 
        if(temp.x == dest.x && temp.y == dest.y) { if(ans == -1 || ans > temp.dist) ans = temp.dist;  continue; }
        for(int i = 0; i<4; i++){
            Point k; k.x = temp.x + dir[i][0]; k.y = temp.y + dir[i][1]; k.dist = 1 + temp.dist; 
            if(valid(k, matrix, vis)) q.push(k); 
        }
    }

    return ans; 
}

int main() {

    vector<vector<int>> matrix = 
    {
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
        { 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }
    };

    int m = matrix.size(), n = matrix[0].size(); Point src = {0,0}, dest = {3,4}; 

    

    cout << "Using Lee: " << traverse(matrix, src, dest) << endl; 


    return 0; 
}