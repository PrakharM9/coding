#include<bits/stdc++.h>
using namespace std;
void flip(int i,int arr[],int n){
    if(i>=n/2){
        return;
    }
    swap(arr[i],arr[n-i-1]);
    flip(i+1,arr,n);
}
int main(){
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++) cin>>array[i];
    flip(0,array,n);
    for(int i=0;i<n;i++) cout<<array[i]<<" ";
    return 0;
}