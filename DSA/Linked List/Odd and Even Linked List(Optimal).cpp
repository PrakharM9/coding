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
    Node* oddandeven(Node* head){
        Node* odd=head;
        Node* even=head->next;
        Node* evenHead=head->next;
        while(even && even->next){
            odd->next=odd->next->next;
            even->next=even->next->next;
            odd=odd->next;
            even=even->next;
        }
        odd->next=evenHead;
        return head;
    }
    Node* convertArr2LL(vector<int> &arr){
        Node* head=new Node(arr[0]);
        Node* mover=head;
        for(int i=1;i<arr.size();i++){
            Node* temp=new Node(arr[i],nullptr);
            mover->next=temp;
            mover=temp;
        }
        return head;
    }
    void print(Node* head){
        Node* temp=head;
        while(temp){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main()
{
    vector<int>arr1={9,6,3,5,4};
    Solution sol;
    Node* head=sol.convertArr2LL(arr1);
    head=sol.oddandeven(head);
    sol.print(head);
    return 0;
}