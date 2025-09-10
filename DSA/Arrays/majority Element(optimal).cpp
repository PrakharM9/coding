#include <bits/stdc++.h>
using namespace std;
// Here we are using Moore's Voting Algorithm for knowing the majority element
int main()
{
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  int el,count=0;
  for(int i=0;i<arr.size();i++){
    if(count==0){
        el=arr[i];
        count=1;
    }
    else if(arr[i]==el)count++;
    else count--;
  }
  int counter=0;
  for(int i=0;i<n;i++){
    if(arr[i]==el)counter++;
  }
  if(counter>arr.size()/2)cout<<"The majority element is:"<<el<<endl;
  else cout<<"There is no majority element";
  return 0;
}