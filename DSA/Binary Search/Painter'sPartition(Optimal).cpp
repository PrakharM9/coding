#include <bits/stdc++.h>
using namespace std;
int countpainters(vector<int>arr,int maxpages){
    int workpainters=0,paintercount=1;
    for(auto it:arr){
        if(workpainters+it<=maxpages){
            workpainters+=it;
        }
        else {
            paintercount+=1;
            workpainters=it;
        }
    }
    return paintercount;
}
int painterallocation(vector<int>work,int painters){
    if(painters>work.size())return -1;
    int low=*max_element(work.begin(),work.end());
    int high=accumulate(work.begin(),work.end(),0);
    while(low<=high){
        int mid=(low+high)/2;
        if(countpainters(work,mid)>painters)low=mid+1;
        else high=mid-1;
    }
    return low;
}
int main()
{
  int n,painters;
  cin>>n;
  vector<int>work(n);
  for(int i=0;i<n;i++){
    cin>>work[i];
  }
  cin>>painters;
  cout<<"Minimum of maximum task alloted to painters is "<<painterallocation(work,painters);
  return 0;
}