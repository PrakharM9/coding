#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin>>n;
  int ans=1;
  cout<<ans<<" ";
  for(int i=1;i<n;i++){
    ans*=(n-i);
    ans/=i;
    cout<<ans<<" ";
  }
  return 0;
}