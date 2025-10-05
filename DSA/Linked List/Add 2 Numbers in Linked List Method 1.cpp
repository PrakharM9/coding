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
    Node* addTwoNumbers(Node* head1,Node* head2){
        int carry=0;
        int sum=head1->data+head2->data;
        Node* head=new Node(sum%10);
        carry=sum/10;
        Node* temp1=head1->next;
        Node* temp2=head2->next;
        Node* prev=head;
        while(temp1 || temp2 || carry){
            int sum=carry;
            if(temp1){
                sum+=temp1->data;
                temp1=temp1->next;
            }
            if(temp2){
                sum+=temp2->data;
                temp2=temp2->next;
            }
            Node* newNode=new Node(sum%10);
            prev->next=newNode;
            carry=sum/10;
            prev=newNode;
        }
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
        if(head==NULL)return;
        print(head->next);
        cout<<head->data;
    }
};
int main()
{
    vector<int>arr1={9,9,9};
    vector<int>arr2={9,9,9};
    Solution sol;
    Node* head1=sol.convertArr2LL(arr1);
    Node* head2=sol.convertArr2LL(arr2);
    Node* sum=sol.addTwoNumbers(head1,head2);
    sol.print(head1);
    cout<<" + ";
    sol.print(head2);
    cout<<" = ";
    sol.print(sum);
    return 0;
}