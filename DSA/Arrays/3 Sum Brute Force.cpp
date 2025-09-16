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
  set<vector<int>>st;
  for(int i=0;i<arr.size()-2;i++){
    for(int j=i+1;j<arr.size()-1;j++){
        for(int k=j+1;k<arr.size();k++){
            if(arr[i]+arr[j]+arr[k]==0){
                vector<int>temp={arr[i],arr[j],arr[k]};
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }
        }
    }
  }
  for(auto it:st){
    for(auto it2:it){
        cout<<it2<<" ";
    }
    cout<<endl;
  }
  return 0;
}