#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* back;
    Node(int data1,Node* next1,Node* back1){
        data=data1;
        next=next1;
        back=back1;
    }
    Node(int data1){
        data=data1;
        next=nullptr;
        back=nullptr;
    }
};
class Solution{
    public:
    Node* convertarr2DLL(vector<int>arr){
        Node* head=new Node(arr[0]);
        Node* temp=head;
        for(int i=1;i<arr.size();i++){
            Node* newEl=new Node(arr[i]);
            temp->next=newEl;
            newEl->back=temp;
            temp=newEl;
        }
        return head;
    }
    void print(vector<vector<int>>&pairs){
        for(int i=0;i<pairs.size();i++){
            for(int j=0;j<pairs[i].size();j++){
                cout<<pairs[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    Node* findTail(Node* head){
        Node* temp=head;
        while(temp->next){
            temp=temp->next;
        }
        return temp;
    }
    vector<vector<int>>sumpairs(Node* head,int target){
        vector<vector<int>>pairs;
        Node* left=head,*right=findTail(head);
        while(left->data<=right->data){
            if(left->data+right->data==target){
                pairs.push_back({left->data,right->data});
                left=left->next;
                right=right->back;
            }
            else if(left->data+right->data>target) right=right->back;
            else left=left->next;
        }
        return pairs;
    }
};
int main()
{
    int n,targetsum;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>targetsum;
    Solution sol;
    Node* head=sol.convertarr2DLL(arr);
    vector<vector<int>>answer=sol.sumpairs(head,targetsum);
    sol.print(answer);
    return 0;
}