#include <bits/stdc++.h>
using namespace std;
class Heap{
    public:
    int arr[100];
    int size;
    Heap(){
        size=0;
    }
    void insert(int val){
        size++;
        int index=size-1;
        arr[index]=val;
        while(index>0){
            int parent=(index-1)/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else{
                return;
            }
        }
    }
    void print(){
        for(int i=0;i<=size;i++){
            cout<<arr[i];
        }
        cout<<endl;
    }
    void deletefromHeap(){
        swap(arr[index],arr[n-1]);
    }
i
};
int main()
{
  
  return 0;
}