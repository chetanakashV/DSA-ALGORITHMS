// Given an array of elements, return the kth element  using quick select algorithm
// It uses quick sort algorithm, but instead of partitioning both left and right part, it partitions only required part. 
#include <bits/stdc++.h> 
using namespace std; 

int search(vector<int>& nums,int start, int end, int k){
    int i = start, key = nums[end]; int temp = 0; 

    for(int k = start; k<end; k++){
        if(nums[k] < key){
            temp++; swap(nums[i], nums[k]); i++; 
        }
    }
    swap(nums[i], nums[end]); 

    if(temp < k-1){
        return search(nums,i,end, k - temp); 
    }
    else if(temp == k-1) return key; 
    return search(nums, start, i-1, k); 

}

int main() {

    vector<int> nums = { 10, 4, 5, 8, 6, 11, 26 }; int k = 3; 

    cout << search(nums, 0, nums.size()-1, k); 


    return 0; 
}