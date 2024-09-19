#include<bits/stdc++.h>
using namespace std;
int main(){
    map<int,int>mpp;
    map<int,pair<int,int>>mpp1;
    map<pair<int,int>,int>mpp2;
    //map stores unique keys in soreted order
    mpp[1]=2;
    mpp.emplace(3,1);
    cout<<mpp[3]<<endl;
    mpp.insert({2,4});
    cout<<mpp[2]<<endl;
    for(auto it:mpp){
        cout<<it.first<<" "<<it.second<<endl;
    }
    cout<<mpp[1]<<endl;
    cout<<mpp[5];//It will either print value as 0 or null 5 is not present as key

    // auto it2=mpp.find(3);
    //cout<<*(it).second;

    // auto it=mpp.find(5);

    auto it=mpp.lower_bound(2);
    auto it2=mpp.upper_bound(3);
    //erase,swap.size,empty are same as above
    return 0;
}