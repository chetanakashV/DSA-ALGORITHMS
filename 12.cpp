// Flood Fill Algo: Given a matrix of numbers, each number indicating different color, Given a color and a starting point. Change every color of the points connected directly to given point  to the given color . 
#include <bits/stdc++.h> 
using namespace std; 

bool valid(vector<vector<int>>& matrix, int x, int y, int c){
    if(x < 0 || y < 0 || x >= matrix.size() || y >= matrix[0].size() || matrix[x][y] != c) return false; 
    return true; 
}

void color(vector<vector<int>>& matrix, int x, int y, int c){
    int prev = matrix[x][y]; vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 
    queue<pair<int,int>> q; q.push({x,y}); if(prev == c) return; 

    while(!q.empty()){
        int i = q.front().first, j = q.front().second; q.pop(); 
        
        for(int k = 0; k<dir.size(); k++){
            int ii = i + dir[k][0], jj = j + dir[k][1]; 
            if(valid(matrix, ii, jj, prev)) { matrix[ii][jj] = c; q.push({ii, jj}); }
        }
    }


}

void print(vector<vector<int>>& matrix){
    int m = matrix.size(), n = matrix[0].size(); 
    for(int i = 0;  i<m; i++) {for(int j = 0; j<n; j++) cout << matrix[i][j] << " "; cout << endl; }
    cout << endl; 

}

int main() {

    vector<vector<int>> matrix =
   {{1,1,1}, {1,1,0}, {1,0,1}}; 

    int x = 1,y = 1, c = 2; 


    print(matrix); 
    
    color(matrix, x, y, c); 

    print(matrix); 


    return 0; 
}