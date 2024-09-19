#include<bits/stdc++.h>
using namespace std;
int main(){
    int num,num2;
    cin>>num;
    num2=num;
    int array[num][num];
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            cin>>array[i][j];
        }
    }
    int rev[num][num];
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            rev[i][j]=array[num2-j-1][i];
        }
        num2=num;
    }
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            cout<<rev[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}