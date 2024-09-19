#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int q;
    cin>>q;
    int hash[26]={0};
    for(int i=0;i<s.size();i++){
        hash[s[i]-97]++;
    }
    while(q--){
        char ch;
        cin>>ch;
        cout<<hash[ch-97]<<endl;
    }
    return 0;
}