#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin>>n;
  int space=(2*n)-2;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=i;j++)cout<<j;
    for(int j=0;j<space;j++)cout<<" ";
    for(int j=i;j>0;j--)cout<<j;
    space-=2;
    cout<<endl;
  }
  return 0;
}