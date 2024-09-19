#include<bits/stdc++.h>
using namespace std;
int pattern(int n){
    int n2=n,n3=n;
    int n4=n;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            cout<<n<<" ";
            n--;
        }
        n=n3;
        for(int j=n+(n-1)-(2*i);j>0;j--){
            cout<<n2<<" ";
        }
        n2--;
        n4-=i;
        n4++;
        for(int j=0;j<i;j++){
            cout<<n4<<" ";
            n4++;
        }
        n4=n3;
        n=n3;
        cout<<endl;
    }
    n3=n;
    n4=n;
    for(int i=0;i<n-1;i++){
        n2++;
        for(int j=n-i;j>0;j--){
            cout<<n4<<" ";
            n4--;
        }
        for(int j=0;j<=2*i;j++){
            cout<<n2<<" ";
        }
        n4=n;
        cout<<endl;
    }
}
int main(){
    int num;
    cin>>num;
    pattern(num);
}