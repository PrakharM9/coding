#include<bits/stdc++.h>
using namespace std;
int main(){
    int num,count=0;
    cin>>num;
    while(num>0){
        if(num%2==0){
            num/=2;
            count++;
        }
        else{
            num-=1;
            num/=2;
            count++;
        }
    }
    cout<<"Number of steps required is:"<<count;
}