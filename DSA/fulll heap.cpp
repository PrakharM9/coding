#include <bits/stdc++.h>
using namespace std;
void insert(int arr[], int &size,int val){
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
void heapify(int arr[],int size,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<size && arr[left]>arr[largest]){
        largest=left;
    }
    if(right<size && arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,size,largest);
    }
}
void print(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void deleteRootfromHeap(int arr[],int &size){
    if(size==0){
        cout<<"Nothing to delete"<<endl;
        return;
    }
    arr[0]=arr[size-1];
    size--;
    int i=0;
    while(size){
        int left=2*i+1;
        int right=2*i+2;
        if(left<size && arr[left]>arr[i]){
            swap(arr[i],arr[left]);
            i=left;
        }
        else if(right<size && arr[right]>arr[i]){
            swap(arr[i],arr[right]);
            i=right;
        }
        else{
            return;
       }

    }
}
void deletenegative(int arr[],int &size){
    for(int j=0;j<size;j++){
        if(arr[j]<0){
            swap(arr[j],arr[size-1]);
            size--;
            heapify(arr,size,j);
            j--;
        }
    }
}
void buildmaxHeap(int arr[],int size){
    for(int i=(size/2)-1;i>=0;i--){
        heapify(arr,size,i);
    }
}
void heapsort(int arr[],int size){
    while(size>1){
        swap(arr[size-1],arr[0]);
        size--;
        heapify(arr,size,0);
    }
}
int main()
{
  int arr[100];
  int num;
  cin>>num;
  int size=0;
  for(int i=0;i<num;i++){
    int value;
    cin>>value;
    insert(arr,size,value);
  }
  print(arr,size);
  deletenegative(arr,size);
  print(arr,size);
  deleteRootfromHeap(arr,size);
  print(arr,size);
  heapsort(arr,size);
  print(arr,size);
  return 0;
}