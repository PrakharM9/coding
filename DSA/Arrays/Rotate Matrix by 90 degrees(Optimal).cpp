#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,m;
  cin>>n>>m;
  vector<vector<int>>arr(n,vector<int>(m));
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>arr[i][j];    
    }
  }
  //This is the code for transposing the array
  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
        swap(arr[i][j],arr[j][i]);
    }
  }
  //This is the code for reversing the rows of array
  for(int i=0;i<n;i++){
    reverse(arr[i].begin(),arr[i].end());
  }
  cout<<"Matrix after rotating 90 degress:"<<endl;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cout<<arr[i][j]<<" ";    
    }
    cout<<endl;
  }
  return 0;
}