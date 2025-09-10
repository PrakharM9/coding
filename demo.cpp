#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<pair<int,int>>vals;
  pair<int,int>temp(7,4);
  vals.push_back(temp);
  pair<int,int>temp2(5,6);
  vals.push_back(temp2);
  sort(vals.begin(),vals.end());
  for(auto i:vals){
    cout<<i.first<<" "<<i.second<<endl;
  }
  return 0;
}