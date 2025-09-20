#include <bits/stdc++.h>
using namespace std;
int floor(vector<int>arr,int target){
    int n=arr.size();
    int low=0,high=n-1;
    int answer=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]<=target){
            answer=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return answer;
}
int main()
{
  int n,elem;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  cin>>elem;
  int result=floor(arr,elem);
  if(result<n){
    cout<<"Floor of "<<elem<<" is "<<arr[result];
  }
  else{
    cout<<"Floor of the element is not present";
  }
  return 0;
}