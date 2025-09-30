// Single File Programming Question
// Problem Statement



// Divu wants a program to analyze a binary tree by traversing it in two different ways. The program begins by prompting for an integer n, indicating the number of nodes in the binary tree. Divu then provides n integers representing the values of these nodes. The program constructs the binary tree from the provided values and performs two types of traversals:



// Forward In-order Traversal: It traverses the binary tree in order, printing each node's value as it visits.

// Reverse In-order Traversal: It traverses the binary tree in order but prints each node's value in reverse order.



// After conducting these traversals, the program prints the results.

// Input format :
// The first line consists of an integer n, representing the number of nodes in the binary tree.

// The second line consists of n space-separated integers representing the values of the nodes in the binary tree.

// Output format :
// The first line prints the in-order traversal of the binary tree, where each node's value is printed as it is visited.

// The second line prints the in-order traversal of the binary tree in reverse, where each node's value is printed in reverse order.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// The input integers should be unique.

// 1 ≤ n ≤ 15

// 1 ≤ Node values ≤ 50

// Sample test cases :
// Input 1 :
// 5
// 9 8 7 6 5
// Output 1 :
// 6 8 5 9 7 
// 7 9 5 8 6 
// Input 2 :
// 8
// 1 2 3 4 5 6 7 8
// Output 2 :
// 8 4 2 5 1 6 3 7 
// 7 3 6 1 5 2 4 8 
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

void printInorder(Node* node)
{
    //Type your code here
    if(node==NULL){
        return;
    }
    printInorder(node->left);
    cout<<node->data<<" ";
    printInorder(node->right);
}
void printPreorder(Node* node)
{
    //Type your code here
    if(node==NULL){
        return;
    }
    cout<<node->data<<" ";
    printPreorder(node->left);
    printPreorder(node->right);
}
void printPostorder(Node* node)
{
    //Type your code here
    if(node==NULL){
        return;
    }
    printPostorder(node->left);
    printPostorder(node->right);
    cout<<node->data<<" ";
}
void printInorderReverse(Node* node)
{
    //Type your code here
    if(node==NULL){
        return;
    }
    printInorderReverse(node->right);
    cout<<node->data<<" ";
    printInorderReverse(node->left);
}

Node* insertLevelOrder(int arr[], int i, int n) 
{
    //Type your code here
    if(i>n){
        return nullptr;
    }
    Node* node=new Node(arr[i]);
    if(i*2+1<=n){
        node->left=insertLevelOrder(arr,2*i+1,n);
    }
    if(i*2+2<=n){
        node->right=insertLevelOrder(arr,2*i+2,n);
    }
    return node;
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    Node* root = insertLevelOrder(arr, 0, n-1);

    printInorder(root);
    cout << endl;
    printInorderReverse(root);
    
    delete[] arr;

    return 0;
}