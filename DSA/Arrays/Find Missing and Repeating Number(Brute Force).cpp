#include <bits/stdc++.h>
using namespace std;
vector<int>missandrep(vector<int>arr){
    int repeating=-1,missing=-1,n=arr.size();
    for(int i=1;i<=n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(arr[j]==i)count++;
        }
        if(count==2)repeating=i;
        else if(count==0)missing=i;

        if(repeating!=-1 && missing!=-1)break;
    }
    return {missing,repeating};
}
int main()
{
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  vector<int>ans=missandrep(arr);
  cout<<"Missing Number is "<<ans[0]<<" and "<<"Repeating Number is "<<ans[1]<<endl;
  return 0;
}