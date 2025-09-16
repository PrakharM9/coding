#include <bits/stdc++.h>
using namespace std;
void swapifgreater(vector<int>&arr1,vector<int>&arr2,int ind1,int ind2){
    if(arr1[ind1]>arr2[ind2]){
        swap(arr1[ind1],arr2[ind2]);
    }
}
void merge(vector<int>&arr1,vector<int>&arr2){
    int n=arr1.size(),m=arr2.size();
    int size=n+m;
    int gap=(size/2)+(size%2);
    while(gap>0){
        int left=0,right=left+gap;
        while(right<size){
            //arr1 and arr2
            if(left<n && right>=n){
                swapifgreater(arr1,arr2,left,right-n);
            }
            //Both arr1
            else if(left<n && right<n){
                swapifgreater(arr1,arr1,left,right);
            }
            // Both arr2
            else{
                swapifgreater(arr2,arr2,left-n,right-n);
            }
            left++; right++;
        }
        if(gap==1)break;
        gap=(gap/2)+(gap%2);
    }
}
int main()
{
    
  int n,m;
  cin>>n;
  vector<int>arr1(n);
  for(int i=0;i<n;i++){
    cin>>arr1[i];
  }
  cin>>m;
  vector<int>arr2(m);
  for(int i=0;i<m;i++){
    cin>>arr2[i];
  }
  merge(arr1,arr2);
  for(auto it:arr1){
    cout<<it<<" ";
  }
  cout<<endl;
  for(auto it:arr2){
    cout<<it<<" ";
  }
  cout<<endl;
  return 0;
}