#include <bits/stdc++.h>
using namespace std;
int maxel(vector<int>arr){
    int max=INT_MIN;
    for(auto it:arr)if(it>max)max=it;
    return max;
}
int calculatehours(vector<int>arr,int hourly){
    int total=0;
    for(auto it:arr){
        total+=ceil((double)it/(double)hourly);
    }
    return total;
}
int kokobananas(vector<int>arr,int h){
    int el=maxel(arr);
    for(int i=1;i<el;i++){
        if(calculatehours(arr,i)<=h){
            return i;
        }
    }
    return -1;
}
int main()
{
  int n,h;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  cin>>h;
  cout<<"Bananas to eat per hour "<<kokobananas(arr,h);
  return 0;
}