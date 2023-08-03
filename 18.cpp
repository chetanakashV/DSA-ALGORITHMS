// Given an array of numbers , sort them using selection sort
#include <bits/stdc++.h> 
using namespace std; 

void selectionSort(vector<int>& nums, int pos = 0){
    if(pos == nums.size()) return; 
    int ind = pos; 
    for(int i = pos; i<nums.size(); i++) if(nums[ind] > nums[i]) ind = i; 
    swap(nums[ind], nums[pos]); 
    selectionSort(nums, pos+1); 
}

void print(vector<int>& nums){
    for(int i = 0; i<nums.size(); i++) cout << nums[i] << " "; 
    cout << endl; 
}

int main() {

    vector<int> nums =  { 12, 11, 13, 5, 6 , 13};

    print(nums); 

    selectionSort(nums); 

    print(nums); 


    return 0; 

}