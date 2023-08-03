//Return array of numbers, return if the target number is present in the array or not. 
#include <bits/stdc++.h> 
using namespace std; 

int find(vector<int>& nums, int target){
    int start = 0, end = nums.size(); 
    while(start <= end){
        int mid = (start+end)/2; 
        if(nums[mid] == target) return true; 
        else if(nums[mid] > target) end = mid-1; 
        else start = mid+1; 
    }
    return false; 
}

int main() {

    vector<int> nums = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91}; int target = 22; 

    if(find(nums, target)) cout << "Element Found"; else cout << "No Element Found"; 

    return 0; 
}