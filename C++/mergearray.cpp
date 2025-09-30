#include <bits/stdc++.h>
using namespace std;
int main () {
    int n;
    cin >> n;
    int arr1[n];
    for (int i=0;i<n;i++){
        cin >> arr1[i];
    }
    
    int m ;
    cin >> m;
    int arr2[m];
    for(int i=0;i<m;i++){
        cin >>arr2[i];
    }
    
    int merge[n+m];
    for(int i=0;i<n;i++){
        merge[i] = arr1[i] ;
    }
    
    for(int i=0;i<m;i++) {
        merge[n+i] = arr2[i];
    }
    int count=0,element,checker,tot=m+n;
    int arrwodup[tot];
    for(int i=0;i<tot;i++){
        element=merge[i];
        checker=1;
        for(int i=0;i<count;i++){
            if(arrwodup[i]==element){
                checker=0;
                break;
            }
        }
        if(checker==1){
            arrwodup[count]=element;
            count++;
        }
    }
    int temp;
    for(int i=0;i<count-1;i++){
        for(int j=0;j<count-i-1;j++){
            if(arrwodup[j]>arrwodup[j+1]){
                temp=arrwodup[j];
                arrwodup[j]=arrwodup[j+1];
                arrwodup[j+1]=temp;
            }
        }
    }
    for(int i=0;i<count;i++){
        cout<<arrwodup[i]<<" ";
    }
}
