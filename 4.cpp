// Given an array of numbers, sort them using merge sort. 
#include <bits/stdc++.h> 
using namespace std; 

void merge(vector<int>&nums, int s1, int e1, int s2, int e2){
    vector<int> temp; int point1 = s1, point2 = s2; 
    while(temp.size() < e2 - s1 +1){
        if(point1 > e1) {temp.push_back(nums[point2]); point2++;  }
        else if(point2 > e2) {temp.push_back(nums[point1]); point1++; }
        else {
            if(nums[point1] > nums[point2]){
                temp.push_back(nums[point2]); point2++; 
            }
            else {
                temp.push_back(nums[point1]); point1++; 
            }
        }
    }

    for(int i = s1; i<= e2; i++) nums[i] = temp[i - s1]; 
    
}

void mergeSort(vector<int>& nums, int start, int end){

    if(start >= end) return ; 

    int mid = start + end; mid /= 2; 

    mergeSort(nums, start, mid); 
    mergeSort(nums, mid+1, end); 

    merge(nums, start, mid, mid+1, end); 

}

void print(vector<int>& nums) {for(int i = 0; i<nums.size(); i++) cout << nums[i] << " "; cout <<endl; }


int main() {

    vector<int> nums = { 12, 11, 13, 5, 6, 7 };
    print(nums); 
    mergeSort(nums, 0, nums.size()-1); 
    print(nums); 

    return 0; 
}