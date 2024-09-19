//     *    
//    ***
//   *****
//  *******
// *********
#include<bits/stdc++.h>
using namespace std;
int main(){
    int x=4,y=1;
    for(int i=0;i<5;i++){
        for(int i=0;i<x;i++){
            cout<<" ";
        }
        for(int i=0;i<y;i++){
            cout<<"*";
        }
       //hello
        for(int i=0;i<x;i++){
            cout<<" ";
        }
        cout<<endl;
        x--;
        y+=2;
    }
    return 0;
}