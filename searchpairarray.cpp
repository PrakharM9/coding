#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>twosum;
    int num,val;
    cin>>num;
    for(int i=0;i<num;i++){
        cin>>val;
        twosum.push_back(val);
    }
    cout<<twosum[0];
    // for(auto it:twosum){
    //     cout<<it<<" ";
    // }
    return 0;
}