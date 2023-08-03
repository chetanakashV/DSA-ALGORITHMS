// Given an array of elements sort them using couting sort, 

#include <bits/stdc++.h> 
using namespace std; 

int main() {
    vector<int> nums = {1, 4, 1, 2, 7, 5, 2}; int n = nums.size(); int low = 1, high = 7; 
      vector<int> pre(high - low + 1, 0); 

    for(int i = 0; i<n; i++) pre[nums[i] - low]++; 

    for(int i = 1; i<pre.size(); i++) pre[i] += pre[i-1]; 

    vector<int> ans(n, 0); 

    for(int i = n-1; i>= 0; i--) {
        ans[pre[nums[i] - low]-1] = nums[i]; pre[nums[i] - low]--; 
    }

    for(int i = 0; i<ans.size(); i++) cout << ans[i] << " "; 

    return 0; 

}