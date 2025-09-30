#include <bits/stdc++.h>
using namespace std;

int main()
{
  int num;
  cin>>num;
  int array[num];
  for(int i=0;i<num;i++){
    cin>>array[i];
  }
  for(int i=0;i<num-1;i++){
    for(int j=0;j<num-i-1;j++){
        if(array[j]>array[j+1]){
            int temp=array[j];
            array[j]=array[j+1];
            array[j+1]=temp;
        }
    }
  }
  for(int i=0;i<num;i++){
    cout<<array[i]<<" ";
  }
  return 0;
}