#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data1,Node* left1,Node* right1){
        data=data1;
        left=left1;
        right=right1;
    }
    Node(int data1){
        data=data1;
        left=nullptr;
        right=nullptr;
    }
};
Node* insertbst(Node* root,int value){
    if(!root){
        return new Node(value);
    }
    Node* current=root;
    while(true){
        if(root->data<=value){
            if(root->right!=NULL){
                root=root->right;
            }
            else{
                root->right=new Node(value);
                break;
            }
        }
        else{
            if(root->left!=NULL){
                root=root->left;
            }
            else{
                root->left=new Node(value);
                break;
            }
        }
    }
    return current;
}
void inorder(Node* root){
    if(!root){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main()
{
    int num;
    cin>>num;
    Node* head=NULL;
    for(int i=0;i<num;i++){
        int value;
        cin>>value;
        head=insertbst(head,value);
    }
    inorder(head);
    return 0;
}