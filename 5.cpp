// Given an array of numbers, sort them using quick sort

#include <bits/stdc++.h> 
using namespace std; 

void quickSort(vector<int>& nums, int start, int end){
    if(start >= end) return;  
     int low = 0; int k = start; 
      int i = (start - 1);
 
    for (int j = start; j <= end - 1; j++) {
 
        if (nums[j] < nums[end]) {
            i++; low++; 
            swap(nums[i], nums[j]);
        }
    }

     swap(nums[low+start], nums[end]); 

     quickSort(nums, start, start+low-1); quickSort(nums, start+low+1, end); 
}

void print(vector<int>& nums) {
    for(int i = 0; i<nums.size(); i++) cout << nums[i] << " "; 
    cout << endl; 
}

int main() {

    vector<int> nums =  { 10, 7, 8, 9, 1, 5 };
    print(nums); 

    quickSort(nums, 0, nums.size()-1); 

    print(nums); 

    return 0; 
}