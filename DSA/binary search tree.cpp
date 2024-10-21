#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int v) : data(v), left(nullptr), right(nullptr) {}
};
class Solution{
public:
    TreeNode* searchBST(TreeNode* root,int val){
        while(root!=NULL && root->data!=val){
            root=(val<root->data)?root->left:root->right;
        }
        return root;
    }
    int findCeil(TreeNode* root,int key){
        int ceil=-1;
        while(root){
            if(root->data==key){
                ceil=root->data;
                return ceil;
            }
            else if(key>root->data){
                root=root->right;
            }
            else{
                ceil=root->data;
                root=root->left;
            }
        }
        return ceil;
    }
    int findFloor(TreeNode* root,int key){
        int floor=-1;
        while(root){
            if(root->data==key){
                floor=root->data;
                return floor;
            }
            else if(key>root->data){
                floor=root->data;
                root=root->right;
            }
            else{
                root=root->left;
            }
        }
        return floor;
    }
    TreeNode* insertintoBST(TreeNode* root,int val){
        if(root==NULL){
            return new TreeNode(val);
        }
        TreeNode* current=root;
        while(true){
            if(current->data<=val){
                if(current->right!=NULL)current=current->right;
                else{
                    current->right=new TreeNode(val);
                    break;
                }
            }
            else{
                if(current->left!=NULL)current=current->left;
                else{
                    current->left=new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root,int key){
        if(root==NULL){
            return NULL;
        }
        if(root->data==key){
            return helper(root);
        }
        TreeNode* dummy=root;
        while(root!=NULL){
            if(root->data>key){
                if(root->data>key){
                    if(root->left!=NULL && root->left->data==key){
                        root->left=helper(root->left);
                        break;
                    }
                }
                else{
                    root=root->left;
                }
            }
            else{
                if(root->right!=NULL && root->right->data==key){
                    root->right=helper(root->right);
                    break;
                }
                else{
                    root=root->right;
                }
            }
        }
        return dummy;
    }
    TreeNode* helper(TreeNode* root){
        if(root->left==NULL){
            return root->right;
        }
        else if(root->right==NULL){
            return root->left;
        }
        TreeNode* rightchild=root->right;
        TreeNode* lastRight=findLastRight(root->left);
        lastRight->right=rightchild;
        return root->left;
    }
    TreeNode* findLastRight(TreeNode* root){
        if(root->right==NULL){
            return root;
        }
        return findLastRight(root->right);
    }
    void printInorder(TreeNode* node)
    {
        //Type your code here
        if(node==NULL){
            return;
        }
        printInorder(node->left);
        cout<<node->data<<" ";
        printInorder(node->right);
    }
    void printPreorder(TreeNode* node)
    {
        //Type your code here
        if(node==NULL){
            return;
        }
        cout<<node->data<<" ";
        printPreorder(node->left);
        printPreorder(node->right);
    }
    void printPostorder(TreeNode* node)
    {
        //Type your code here
        if(node==NULL){
            return;
        }
        printPostorder(node->left);
        printPostorder(node->right);
        cout<<node->data<<" ";
    }
    void printInorderReverse(TreeNode* node)
    {
        //Type your code here
        if(node==NULL){
            return;
        }
        printInorderReverse(node->right);
        cout<<node->data<<" ";
        printInorderReverse(node->left);
    }
};
int main()
{
  int num;
  cin>>num;
  TreeNode* root=NULL;
  Solution sol;
  for(int i=0;i<num;i++){
    int value;
    cin>>value;
    root=sol.insertintoBST(root,value);
  }
  sol.printInorder(root);
  return 0;
}