// You are using GCC
// Kamal is interested in managing a collection of integers using a Binary Search Tree (BST). He wants to write a program that constructs a BST from a given set of integers and then deletes all the nodes with values greater than the average value of all nodes in the BST.

// Help him solve this problem.
// Example
// Input:

// 5

// 10 20 30 40 50

// Output:

// 10 20 30

// Explanation:

// The sum of values is 10 + 20 + 30 + 40 + 50 = 150, and there are 5 nodes. So, the average is 150 / 5 = 30. Then, delete nodes with values greater than the average (30). The final output is the values of the remaining nodes in the BST, which are 10, 20 and 30.

// Input format :
// The first line consists of an integer N, representing the number of elements in the BST.

// The second line consists of N space-separated integers, representing the BST elements.

// Output format :
// The output prints the remaining integers in the BST after deleting nodes greater than the average value, separated by a space.

// The integers should be printed in an in-order traversal.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// The given test cases will fall under the following constraints:

// 1 ≤ N ≤ 20

// 1 ≤ elements ≤ 1000

// Sample test cases :
// Input 1 :
// 5
// 10 20 30 40 50
// Output 1 :
// 10 20 30 
// Input 2 :
// 6
// 20 52 65 98 74 57
// Output 2 :
// 20 52 57 
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return newNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

void inOrderTraversal(struct Node* root) {
    if (root) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int sumNodes(struct Node* root) {
    //Type your code here
    if(root==NULL){
        return 0;
    }
    return root->data+sumNodes(root->left)+sumNodes(root->right);
}

int countNodes(struct Node* root) {
    //Type your code here
    if(root==NULL){
        return 0;
    }
    return 1+countNodes(root->left)+countNodes(root->right);
}

Node* deleteGreaterThanAverage(struct Node* root, int avg) {
    //Type your code here
    if(root==NULL){
        return NULL;
    }
    root->left=deleteGreaterThanAverage(root->left,avg);
    root->right=deleteGreaterThanAverage(root->right,avg);
    if(root->data>avg){
        Node* temp=root->left;
        delete root;
        return temp;
    }
    return root;
}

int main() {
    struct Node* root = NULL;
    int n, data;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insert(root, data);
    }

    int sum = sumNodes(root);
    int count = countNodes(root);
    int avg = count ? sum / count : 0;

    root=deleteGreaterThanAverage(root, avg);

    inOrderTraversal(root);

    return 0;
}