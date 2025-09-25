#include <bits/stdc++.h>
using namespace std;
int countstudents(vector<int>arr,int maxpages){
    int pagesStudents=0,student=1;
    for(auto it:arr){
        if(pagesStudents+it<=maxpages){
            pagesStudents+=it;
        }
        else {
            student+=1;
            pagesStudents=it;
        }
    }
    return student;
}
int bookallocation(vector<int>arr,int students){
    if(students>arr.size())return -1;
    int low=*max_element(arr.begin(),arr.end());
    int high=accumulate(arr.begin(),arr.end(),0);
    while(low<=high){
        int mid=(low+high)/2;
        if(countstudents(arr,mid)>students)low=mid+1;
        else high=mid-1;
    }
    return low;
}
int main()
{
  int n,students;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  cin>>students;
  cout<<"Minimum of maximum number of pages alloted is "<<bookallocation(arr,students);
  return 0;
}