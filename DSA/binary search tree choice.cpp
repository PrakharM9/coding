// You are using GCC
#include <iostream>
#include<stdlib.h>

using namespace std;

struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
    Node(int value):data(value),left(nullptr),right(nullptr){}
};

struct Node *CreateBST(struct Node *, int);
void Inorder(struct Node *);
void Preorder(struct Node *);
void Postorder(struct Node *);

int main()
{
    struct Node *root = NULL;
    int choice, item, i;
    do
    {
        cin>>choice;
        switch(choice)
        {
        case 1:
            root = NULL;
            int n;
            cin>>n;
            for(i = 1; i <= n; i++)
            {
                cin>>item;
                root = CreateBST(root,item);
            }
            break;
        case 2:
            cout<<"Inorder: ";
            Inorder(root);
            cout<<"\n";
            break;
        case 3:
            cout<<"Preorder: ";
            Preorder(root);
            cout<<"\n";
            break;
        case 4:
            cout<<"Postorder: ";
            Postorder(root);
            cout<<"\n";
            break;
        case 5:
            exit(0);
            break;
        default:
            break;
        }
    } while(1);
    return 0;
}

struct Node *CreateBST(struct Node *root, int item) {
    //Type your code here
    if(root==NULL){
        return new Node(item);
    }
    Node* root2=root;
    while(true){
        if(root->data<=item){
            if(root->right!=NULL){
                root=root->right;
            }
            else{
                root->right=new Node(item);
            }
        }
        else{
            if(root->left!=NULL){
                root=root->left;
            }
            else{
                root->left=new Node(item);
                break;
            }
        }
    }
    return root2;
}

void Inorder(struct Node *root) {
    //Type your code here
    if(root==NULL){
        return;
    }
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

void Preorder(struct Node *root) {
    //Type your code here
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    Inorder(root->left);
    Inorder(root->right);
}

void Postorder(struct Node *root) {
    //Type your code here
    if(root==NULL){
        return;
    }
    Inorder(root->left);
    Inorder(root->right);
    cout<<root->data<<" ";
}