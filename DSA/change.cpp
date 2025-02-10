#include <bits/stdc++.h>
using namespace std;

int main()
{
  map<int,int>mpp;
  mpp[0]=1;
  mpp[10]=2;
  for(auto it:mpp){
    cout<<it.first<<" "<<it.second<<endl;
  }
  return 0;
}