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
    int low=1,high=el;
    while(low<=high){
        int mid=(low+high)/2;
        int totalhrs=calculatehours(arr,mid);
        if(totalhrs<=h){
            high=mid-1;
        }
        else low=mid+1;
    }
    return low;
    // Here we are returning low becuase answer is expected at end and high start from
    // there so low will contain answer
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