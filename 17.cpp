// Given an array of numbers, sort them using insertion sort. 
#include <bits/stdc++.h> 
using namespace std; 

void insertionSort(vector<int>& nums){
    int key; 
    for(int i = 1; i<nums.size(); i++){
        key = nums[i]; int temp = i-1; 

         while(temp >= 0 && nums[temp] > key){
            nums[temp+1] = nums[temp]; temp--; 
         }
         nums[temp+1] = key; 

    }


}

void print(vector<int>& nums){
    for(int i = 0; i<nums.size(); i++) cout << nums[i] << " "; 
    cout << endl; 
}

int main() {

    vector<int> nums = { 12, 11, 13, 5, 6 }; 

    print(nums); 

    insertionSort(nums); 

    print(nums); 


    return 0; 
}