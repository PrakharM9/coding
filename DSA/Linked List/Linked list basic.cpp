#include <bits/stdc++.h>
using namespace std;
struct Node{
    public:
    int data;
    Node* next;
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};
int main()
{ 
    vector<int>arr={2, 5, 8, 7};
    Node y=Node(arr[0],nullptr);
    cout<<y.next;
    return 0;
}   