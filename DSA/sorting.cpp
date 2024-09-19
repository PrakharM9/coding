#include<bits/stdc++.h>
using namespace std;
bool comp(pair<int,int>p1,pair<int,int>p2){
    if(p1.second<p2.second) return true;
    if(p1.second>p2.second)return false;
    //they are same

    if(p1.first>p2.second) return true;
    return false;
}
int main(){
    // sort(a,a+n);
    //It will sort between the given rnage excluding the end point

    //sort(v.begin(),v.end())

    // sort(a,a+n,greater<int>);

    pair<int,int>a[]={{1,2},{2,1},{4,1}};

    //sort it according to second element but if second element is same, then sort it according to first element but in descending
    // sort(a,a+n,comp);
    //{4,1},{2,1},{1,2}

    int num=7;
    int cnt=__builtin_popcount();
    //for 6 it will return 111 it's  binary value  otherwise it might have return like 0000...111

    long long num=12211244214124;
    int cnt=__builtin_popcountll();
    //it is for long long

    string s='123';
    do{
        cout<<s<<endl;
    }while(next_permutation(s.begin(),s.end()));
    //when permutation will end it will return null
    //if you want to print all permutation then give the first one as the starting one otherwise it will may not print all permuations
    int maxi=max_element(a,a+n);
    int max=*max_element(a,a+n);
    //for element we have to put *
    //min elements also exist
    return 0;
}