// Problem Statement



// Emma is working with two sets of sensor data recorded in two separate grounded header linked lists. She wants to merge these two lists alternately to analyze the combined data more efficiently. 



// Help Emma by writing a program to merge the two grounded header linked lists alternately.



// Company Tags: TCS

// Input format :
// The first line of input consists of the number of elements n in the first list.

// The second line consists of n elements, separated by space.

// The third line consists of the number of elements m in the second list.

// The fourth line consists of m elements, separated by space.

// Output format :
// The output prints the merged linked list with nodes from both lists alternately.



// Refer to the sample output for formatting specifications.

// Code constraints :
// 1 ≤ n, m ≤ 15

// 1 ≤ elements ≤ 100
// You are using GCC
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }
    Node(int data1){
        data=data1;
        next=NULL;
    }
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of a linked list
void insertNode(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to merge two linked lists alternately
struct Node* mergeLists(struct Node* list1, struct Node* list2) {
    //Type your code here
    Node* newnode=new Node(0);
    Node* current=newnode;
    while(list1!=NULL && list2!=NULL){
        current->next=list1;
        list1=list1->next;
        current=current->next;
        
        current->next=list2;
        list2=list2->next;
        current=current->next;
    }
    Node* mergednode=newnode->next->next;
    delete newnode;
    return mergednode;
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head->next;  
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct Node* list1 = createNode(0);  // Grounded header node for list1
    struct Node* list2 = createNode(0);  // Grounded header node for list2

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        insertNode(list1, data);
    }

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        insertNode(list2, data);
    }

    struct Node* mergedList = mergeLists(list1, list2);

    displayList(mergedList);

    return 0;
}