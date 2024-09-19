#include <bits/stdc++.h>
using namespace std;
int pattern(int n){
    char ch='A'+(n-1);
    char ch2=ch;
    for(int i=0;i<n;i++){
        ch-=i;
        for(int j=0;j<=i;j++){
            cout<<ch<<" ";
            ch++;
        }
        cout<<endl;
        ch=ch2;
}
int main(){
    int num;
    cin>>num;
    pattern(num);
    }
    return 0;
}