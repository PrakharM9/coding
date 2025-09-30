
// Problem Statement



// Dharun is working on a program to manipulate linked lists. He wants to write a function that takes two linked lists as input, inserts nodes at the end, and deletes all the nodes from the first list that also appear in the second list. 



// Dharun needs your help implementing this function. The function should take two linked lists, list1, and list2, as input, where each list is represented by its head node.

// Input format :
// The first line contains an integer n, denoting the number of nodes in list1.

// The second line contains n space-separated integers, representing the values of the nodes in list1.

// The third line contains an integer m, denoting the number of nodes in list2.

// The fourth line contains m space-separated integers, representing the values of the nodes in list2.

// Output format :
// The first line of output displays "Before deletion: " followed by the elements of the first linked list before the deletion, separated by a space.

// The second line of output displays "After deletion: " followed by the elements of the first linked list after the deletion, separated by a space.

// If all elements in the first linked list are the same after deletion, the third line displays, "Elements in both lists are same".



// Refer to the sample output for formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ n,m ≤ 100

// -5000 ≤ values of nodes ≤ 5000// You are using GCC
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

int valueExists(struct Node* second, int value) {
    //Type your code here
    int con=0;
    Node* current=second;
    while(current!=NULL){
        if(current->data==value){
            con=1;
            break;
        }
        current=current->next;
    }
    return con;
}

Node* deleteNodesInSecondList(struct Node* first, struct Node* second) {
    //Type your code here
    Node* current=first;
    Node* prev=NULL;
    while(current!=NULL){
        int check=valueExists(second,current->data);
        if(check==1){
            if(prev==NULL){
                first=first->next;
            }
            else{
                prev->next=current->next;
            }
        }
        else{
            prev =current;
        }
        current=current->next;
    }
    return first;
}

void displayLinkedList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void deleteLinkedList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int areAllElementsSame(struct Node* head1) {
    //Type your code here
    if(head1==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int main() {
    struct Node* first = NULL;
    struct Node* second = NULL;
    int size1, size2;

    scanf("%d", &size1);
    for (int i = 0; i < size1; i++) {
        int value;
        scanf("%d", &value);
        insertNode(&first, value);
    }

    scanf("%d", &size2);
    for (int i = 0; i < size2; i++) {
        int value;
        scanf("%d", &value);
        insertNode(&second, value);
    }

    printf("Before deletion: ");
    displayLinkedList(first);

    first=deleteNodesInSecondList(first, second);

    printf("After deletion: ");
    displayLinkedList(first);

    if (areAllElementsSame(first)) {
        printf("Elements in both lists are same");
    }

    deleteLinkedList(first);
    deleteLinkedList(second);

    return 0;
}