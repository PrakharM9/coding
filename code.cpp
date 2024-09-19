#include<bits/stdc++.h>
using namespace std;
int main(){
    int x;
    cin>>x;
    int x2=x,length=0,con=0,n=0,digit,mutl;
        if(x<0){
            x*=-1;
            con=1;
        }
        while(x2>0){
            length++;
            x2/=10;
        }
        mutl=pow(10,length-1);
        while(x>0){
            digit=x%10;
            n+=digit*mutl;
            mutl/=10;
            x/=10;
        }
        if(con==1){
            cout<<n*(-1);
        }
        else{
            cout<<n;
        }
    return 0;
}