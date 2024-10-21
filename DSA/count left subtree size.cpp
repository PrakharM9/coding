// You are using GCC
// Romit, a student studying data structures, wants to explore the concept of left subtrees within binary search trees (BST).



// He plans to create a program that builds a BST, inserts data into it while keeping track of the number of elements added to the left subtree, and finally counts the nodes in the left subtree.

// Input format :
// The first line of input consists of an integer N, representing the number of elements to insert into the BST.

// The second line consists of N space-separated integers, representing the data to be inserted into the BST.

// Output format :
// The output prints the number of nodes in the left subtree of the BST.



// Refer to the sample output for formatting specifications.

// Code constraints :
// The given test cases will fall under the following constraints:

// 1 ≤ N ≤ 20

// 1 ≤ data ≤ 1000

// The input data values are distinct.

// Sample test cases :
// Input 1 :
// 3
// 5 3 7
// Output 1 :
// 1
// Input 2 :
// 6
// 10 8 15 6 9 12
// Output 2 :
// 3
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

Node* insert(Node* root, int data, int& leftSubtreeSize) {
    //Type your code here
    if(root==NULL){
        return createNode(data);
    }
    Node* current=root;
    while(true){
        if(data>=current->data){
            if(current->right!=NULL){
                current=current->right;
            }
            else{
                current->right=createNode(data);
                break;
            }
        }
        else{
            if(current->left!=NULL){
                current=current->left;
            }
            else{
                current->left=createNode(data);
                break;
            }
        }
    }
    return root;
}

int countLeftSubtreeNodes(Node* root) {
    //Type your code here
    if(root==NULL){
        return 0;
    }
    return countLeftSubtreeNodes(root->left)+1+countLeftSubtreeNodes(root->right);
}

int main() {
    Node* root = nullptr; 
    int n;
    cin >> n;

    int leftSubtreeSize = 0; 

    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        root = insert(root, data, leftSubtreeSize);
    }

    int nodesInLeftSubtree = countLeftSubtreeNodes(root->left);
    cout << nodesInLeftSubtree;

    return 0;
}