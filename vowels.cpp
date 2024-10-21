#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<int>per1{3,4,5,_,_,5};
  vector<int>per2{3,4,5};
  sort(per1.begin(),per2.end());
  for(auto it:per1){
    cout<<it<<" ";
  }
  return 0;
}