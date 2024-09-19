// Problem Statement



// Alex is maintaining a list of integers representing stock quantities in his warehouse. Sometimes, he needs to remove all occurrences of a particular quantity from the list when an item is discontinued. He wants to use a grounded header linked list for this purpose.



// Help Alex in the task.



// Company Tags: CTS 

// Input format :
// The first line of input consists of the number of items n in the warehouse.

// The second line consists of n elements, separated by space.

// The third line consists of the quantity to remove all occurrences.

// Output format :
// The output prints the sequence of integers representing the updated list of stock quantities after the removal of all occurrences of the specified value.



// Refer to the sample output for formatting specifications.

// Code constraints :
// 1 ≤ n ≤ 15

// 1 ≤ elements ≤ 100

// Sample test cases :
// Input 1 :
// 5
// 1 2 3 3 3
// 3
// Output 1 :
// 1 2 
// Input 2 :
// 6
// 1 1 1 1 1 12
// 1
// Output 2 :
// 12 
// You are using GCC
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayList(struct Node* head) {
    struct Node* temp = head->next;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

Node* deleteValue(struct Node* head, int value) {
    //Type your code here
    Node* prev=NULL;
    Node* current=head;
    while(current!=NULL){
        if(current->data==value){
            if(prev==NULL){
                head=head->next;
            }
            else{
                prev->next=current->next;
            }
        }
        else{
            prev=current;
        }
        current=current->next;
    }
    return head;
}

int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->next = NULL;

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        insertNode(&head, data);
    }

    int value;
    scanf("%d", &value);

    head=deleteValue(head, value);

    displayList(head);

    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}