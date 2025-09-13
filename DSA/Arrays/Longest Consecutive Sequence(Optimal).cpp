#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  unordered_set<int>vals;
  for(auto it:arr){
    vals.insert(it);
  }
  int longest=1,count=1;
  for(auto it:vals){
    if(vals.find(it-1)==vals.end()){
        int x=it;
        count=1;
        while(vals.find(x+1)!=vals.end()){
            x=x+1;
            count++;
        }
        longest=max(longest,count);
    }
  }
  cout<<"Longest common squence length is:"<<longest<<endl;
  return 0;
}