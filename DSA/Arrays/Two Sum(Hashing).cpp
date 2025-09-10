#include <bits/stdc++.h>
using namespace std;

int main()
{
//   here  Hashing approach is used
//   It is the best approach if we have to return indices
//   It is the better approach if we have to only tell whether there exists a sum like this
    int n,target;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>target;
    unordered_map<int,int> mpp;
    for(int i=0;i<n;i++){
        int el=arr[i];
        if(mpp.find(target-el)!=mpp.end()){
            cout<<"Indices are:"<<mpp[target-el]<<" and "<<i<<endl;
            // cout<<"Yes"
            return 0;
        }
        mpp[el]=i;
        cout<<"There are no two such elements"<<endl;
        // cout<<"No"
    }
    return 0;
}