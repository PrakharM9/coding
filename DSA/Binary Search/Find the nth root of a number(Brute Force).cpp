#include <bits/stdc++.h>
using namespace std;
// n is power and m is number
int nthroot(int n,int m){
  for(int i=0;i<=m;i++){
    if(pow(i,n)==m)return  i;
    else if(pow(i,n)>m)break;
  }
  return -1;
}
int main()
{
  int n,m;
  cin>>n>>m;
  int result=nthroot(n,m);
  if(result!=-1)cout<<m<<"^-"<<n<<" is "<<nthroot(n,m);
  else cout<<"Answer is not integer";
  return 0;
}