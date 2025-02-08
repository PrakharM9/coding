#include <bits/stdc++.h>
using namespace std;
int partition(int arr[],int low,int high){
    int pivot=arr[low];
    int i=low,j=high;
    while(i<j){
        while(arr[i]<=pivot && i<=high-1)i++;
        while(arr[j]>pivot && j>=low+1)j--;
        if(i<j)swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}
void quicksort(int arr[],int low,int high){
    if(low<high){
        int pIndex=partition(arr,low,high);
        quicksort(arr,low,pIndex-1);
        quicksort(arr,pIndex+1,high);
    }
}
int main()
{
  int num;
  cin>>num;
  int array[num];
  for(int i=0;i<num;i++){
    cin>>array[i];
  }
  quicksort(array,0,num-1);
  for(int i=0;i<num;i++){
    cout<<array[i]<<" ";
  }
  return 0;
}