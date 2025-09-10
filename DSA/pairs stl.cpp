#include<bits/stdc++.h>
using namespace std;
int main(){
    pair<int,pair<int,int>> p={1,{3,5}};
    cout<<p.first<<" "<<p.second.first<<" "<<p.second.second;
    pair<int,int> arr[]={{1,2},{2,5},{5,1}};
    cout<<endl;
    cout<<arr[2].first;
    return 0;
}