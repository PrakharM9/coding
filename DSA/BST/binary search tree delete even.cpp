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
class Bst{
    public:
    TreeNode* createbst(TreeNode* root,int value){
        if(root==NULL){
            return new TreeNode(value);
        }
        TreeNode* current=root;
        while(true){
            if(root->data<=value){
                if(root->right!=NULL){
                    root=root->right;
                }
                else{
                    root->right=new TreeNode(value);
                    break;
                }
            }
            else{
                if(root->left!=NULL){
                    root=root->left;
                }
                else{
                    root->left=new TreeNode(value);
                    break;
                }            
            }
        }
        return current;
    }
    TreeNode* deleteven(TreeNode* root){

    }
};
int main()
{
    
    return 0;
}