#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>ans(n);
    int pos=0,neg=1;
    for(auto it:arr){
        if(it<0){
            ans[pos]=it;
            pos+=2;
        }
        else{
            ans[neg]=it;
            neg+=2;
        }
    }
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}