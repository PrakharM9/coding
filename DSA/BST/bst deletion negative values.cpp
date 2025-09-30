#include <bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data1){
        data=data1;
        left=nullptr;
        right=nullptr;
    }
};
TreeNode* insertbst(TreeNode* root,int value){
    if(!root){
        return new TreeNode(value);
    }
    TreeNode* current=root;
    while(true){
        if(current->data<=value){
            if(current->right!=NULL){
                current=current->right;
            }
            else{
                current->right=new TreeNode(value);
                break;
            }
        }
        else{
            if(current->left!=NULL){
                current=current->left;
            }
            else{
                current->left=new TreeNode(value);
                break;
            }
        }
    }
    return root;
}
TreeNode* findlastright(TreeNode* root){
    if(root->right==NULL){
        return root;
    }
    return findlastright(root->right);
}
TreeNode* helper(TreeNode* root){
    if(root->left==NULL){
        return root->right;
    }
    if(root->right==NULL){
        return root->left;
    }
    TreeNode* rightchild=root->right;
    TreeNode* lastright=findlastright(root->left);
    lastright->right=rightchild;
    return root->left;
}
TreeNode* deleteNegativeValues(TreeNode* root){
    if(!root){
        return NULL;
    }
    root->left=deleteNegativeValues(root->left);
    root->right=deleteNegativeValues(root->right);
    if(root->data<0){
        root=helper(root);
    }
    return root;
}
void inorder(TreeNode* root){
    if(root==NULL)return; 
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main()
{
    TreeNode* root=NULL;
    int num;
    cin>>num;
    for(int i=0;i<num;i++){
        int value;
        cin>>value;
        root=insertbst(root,value);
    }
    inorder(root);
    cout<<endl;
    root=deleteNegativeValues(root);
    inorder(root);
    return 0;
}