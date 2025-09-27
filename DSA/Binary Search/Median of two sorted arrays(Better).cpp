#include <bits/stdc++.h>
using namespace std;
double median(vector<int>arr1,vector<int>arr2){
    int count=0,i=0,j=0;
    int n1=arr1.size(),n2=arr2.size();
    int n=n1+n2; // >>2 means that we are diving by 2
    int ind2=n/2;
    int ind1=ind2-1;
    int ind1el=-1,ind2el=-1;
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            if(count==ind1)ind1el=arr1[i];
            if(count==ind2)ind2el=arr1[i];
            i++;
            count++;
        }
        else{
            if(count==ind1)ind1el=arr2[j];
            if(count==ind2)ind2el=arr2[j];
            j++;
            count++;
        }
    }
    while(i<n1){
        if(count==ind1)ind1el=arr1[i];
        if(count==ind2)ind2el=arr1[i];
        i++;
        count++;
    }
    while(j<n2){
        if(count==ind1)ind1el=arr2[j];
        if(count==ind2)ind2el=arr2[j];
        j++;
        count++;
    }
    if(n%2==1)return (double)ind2el;
    return (double)((double)(ind1el+ind2el))/2.0;
}
int main()
{
  int n1,n2;
  cin>>n1;
  vector<int>arr1(n1);
  for(int i=0;i<n1;i++){
    cin>>arr1[i];
  }
  cin>>n2;
  vector<int>arr2(n2);
  for(int i=0;i<n2;i++){
    cin>>arr2[i];
  }
  cout<<median(arr1,arr2);
  return 0;
}