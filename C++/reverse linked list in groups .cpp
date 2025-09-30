// You are using GCC
// In a warehouse management system, packages are organized sequentially using a singly linked list, where each node represents a package with its unique ID. To optimize the retrieval process, the system allows reversing the order of packages in groups of k nodes. 



// Your task is to read the package IDs, construct the linked list, and reverse the order of packages in groups of k.

// Input format :
// The first line of input consists of an integer n, the number of packages.

// The second line consists of n integers, the package IDs.

// The third line consists of an integer k, the size of the groups to reverse.

// Output format :
// The first line of output prints the original sequence of package IDs as a linked list.

// The second line prints the modified sequence of package IDs after reversing in groups of k.



// Refer to the sample output for formatting specifications.

// Code constraints :
// 1 ≤ n ≤ 20

// 1 ≤ package ID, k ≤ 100
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }
    Node(int data1){
        data=data1;
        next=NULL;
    }
};

Node* createNode(int data) {
    //Type your code here
    return new Node(data);
}

Node* reverseKNodes(Node* head, int k) {
    //Type your code here
    int count=0;
    Node* prev=NULL;
    Node* current=head;
    while(current && count<k){
        Node* nextnode=current->next;
        current->next=prev;
        prev =current;
        current=nextnode;
        count++;
    }
    if (current) {
        Node* temp = reverseKNodes(current, k);
        Node* temp2 = prev;
        while (temp2->next) {
            temp2 = temp2->next;
        }
        temp2->next = temp;
    }
    return prev;
}

void displayList(Node* head) {
    //Type your code here
    Node* current=head;
    while(current!=NULL){
        cout<<current->data<<" ";
        current=current->next;
    }
    cout<<endl;
}

void deleteList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    int n, k;
    cin >> n;
    Node* head = NULL;
    Node* tail = NULL;
    
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        Node* newNode = createNode(value);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    cin >> k;

    cout << "Original Linked List: ";
    displayList(head);

    head = reverseKNodes(head, k);

    cout << "Modified Linked List: ";
    displayList(head);

    //deleteList(head);

    return 0;
}