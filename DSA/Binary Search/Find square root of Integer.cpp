#include <bits/stdc++.h>
using namespace std;
int findsqrt(int n){
    int low=1,high=n;
    while(low<=high){
        int mid=(low+high)/2;
        if((mid*mid)<=n)low=mid+1;
        else high=mid-1;
    }
    return high;
}
int main()
{
  int n;
  cin>>n;
  cout<<"Square Root of number is "<<findsqrt(n)<<endl;
  return 0;
}