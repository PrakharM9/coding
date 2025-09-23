#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x=4,y=1;
    for(int i=0;i<5;i++){
        // This loop is used for printing space before stars
        for(int j=0;j<x;j++){
            cout<<" ";
        }
        // This loop is used for printing stars
        for(int j=0;j<y;j++){
            cout<<"*";
        }
        // This loop is used for printing space before stars
        for(int j=0;j<x;j++){
            cout<<" ";
        }
        cout<<endl;
        x--;
        y+=2;
    }
  return 0;
}