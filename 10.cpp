// Kadane's Algorithm to find the maximum sum of sub array. 

#include <bits/stdc++.h> 
using namespace std; 


int main() {

    vector<int> nums = { -2, -3, 4, -1, -2, 1, 5, -3 };

    int ans = INT_MIN, temp = 0; 

    for(int i = 0; i<nums.size(); i++){
        temp += nums[i]; 
        if(ans < temp) ans = temp; 
        if(temp < 0) temp = 0; 
    }


    cout << "Using Kadane's:  " << ans << endl; 

    return 0; 
}