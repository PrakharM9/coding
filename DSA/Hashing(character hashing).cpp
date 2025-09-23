#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int q;
    cin>>q;
    //pre computing the frequency of each character
    int hash[256]={0};
    for(int i=0;i<s.size();i++){
        hash[s[i]]++;
    }
    while(q--){
        char ch;
        cin>>ch;
        //fetching the frequency of the character
        cout<<hash[ch]<<endl;
    }
    return 0;
}