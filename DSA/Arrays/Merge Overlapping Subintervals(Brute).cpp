#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>minsubintervals(vector<vector<int>>subintervals){
    vector<vector<int>>solution;
    sort(subintervals.begin(),subintervals.end());
    for(int i=0;i<subintervals.size();i++){
        int start=subintervals[i][0],end=subintervals[i][1];
        if(!solution.empty() && end<=solution.back()[1])continue;
        for(int j=i+1;j<subintervals.size();j++){
            if(subintervals[j][0]<=end){
                end=max(end,subintervals[j][1]);
            }
        }
        solution.push_back({start,end});
    }
    return solution;
}
int main()
{
  int k;
  cin>>k;
  vector<vector<int>>subintervals(k,vector<int>(2));
  for(int i=0;i<k;i++){
    cin>>subintervals[i][0]>>subintervals[i][1];
  }
  vector<vector<int>>answer=minsubintervals(subintervals);
  for(int i=0;i<answer.size();i++){
    for(int j=0;j<answer[i].size();j++){
        cout<<answer[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}