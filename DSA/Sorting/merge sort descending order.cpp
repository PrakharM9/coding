// You are using GCC
#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
using namespace std;

int partition(vector<string>&names,vector<int>&heights, int low, int high) {
    
    //Type your code here
    int pivot=heights[low];
    int i=low,j=high;
    while(i<j){
        while(heights[i]>=pivot && i<=high-1)i++;
        while(heights[j]<pivot && j>=low+1)j--;
        if(i<j){
            swap(heights[i],heights[j]);
            swap(names[i],names[j]);
        }
    }
    swap(names[low],names[j]);
    swap(heights[low],heights[j]);
    return j;
}

void quickSort(vector<string>&names,vector<int>&heights, int low, int high) {
    
    //Type your code here
    if(low<high){
        int pIndex=partition(names,heights,low,high);
        quickSort(names,heights,low,pIndex-1);
        quickSort(names,heights,pIndex+1,high);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int>heights(n);
    vector<string>names(n);
    for (int i = 0; i < n; i++) {
        cin >> names[i] >> heights[i];
    }

    quickSort(names, heights, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << names[i] << " ";
    }
    return 0;
}