#include <bits/stdc++.h>
using namespace std;
class Node{
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
class Solution{
    public:
    Node* convertarr2LL(vector<int>arr){
        Node* head=new Node(arr[0]);
        Node* temp=head;
        for(int i=1;i<arr.size();i++){
            Node* newEl=new Node(arr[i]);
            temp->next=newEl;
            temp=newEl;
        }
        return head;
    }
    Node* intersection(Node* head1,Node* head2){
        map<Node*,int>mpp;
        Node* temp=head1;
        while(temp){
            mpp[temp]++;
            temp=temp->next;
        }
        temp=head2;
        while(temp!=NULL){
            if(mpp[temp])return temp;
            temp=temp->next;
        }
        return NULL;
    }
};
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
    Solution sol;
    Node* head1=sol.convertarr2LL(arr1);
    Node* head2=sol.convertarr2LL(arr2);
    Node* result=sol.intersection(head1,head2);
    if(result)cout<<result->data<<" is the intersection point"<<endl;
    else cout<<"No Intersection point"<<endl;
    return 0;
}