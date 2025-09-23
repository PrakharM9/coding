#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin>>n;
    int x=0,y=n+(n-1);
    for(int i=0;i<n;i++){
        for(int j=0;j<x;j++){
            cout<<" ";
        }
        for(int j=0;j<y;j++){
            cout<<"*";
        }
        for(int j=0;j<x;j++){
            cout<<" ";
        }
        cout<<endl;
        x++;y-=2;
    }
  return 0;
}