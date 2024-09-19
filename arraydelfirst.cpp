#include<bits/stdc++.h>
using namespace std;
int main(){
    int num;
    cin>>num;
    int array[num];
    for(int i=0;i<num;i++){
        cin>>array[i];
    }
    for(int i=1;i<num;i++){
        cout<<array[i]<<" ";
    }
    return 0;
}