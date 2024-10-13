// You are using GCC
#include <iostream>

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void insertAtBeginning(Node** head, int newData) {
    Node* newNode = new Node;
    newNode->data = newData;
    newNode->prev = nullptr;
    newNode->next = *head;

    if (*head != nullptr)
        (*head)->prev = newNode;

    *head = newNode;
}

Node* reverseList(Node* head) {
    //Type your code here
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* current=head;
    Node* temp=nullptr;
    
    while(current!=NULL){
        temp=current->prev;
        current->prev=current->next;
        current->next=temp;
        current=current->prev;
    }
    if (temp != NULL) {
        head = temp->prev;
    }
    return head;
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = nullptr;
    int n, data;

    std::cin >> n;

    // Create the doubly linked list
    for (int i = 0; i < n; i++) {
        std::cin >> data;
        insertAtBeginning(&head, data);
    }

    std::cout << "Original List: ";
    printList(head);

    // Reverse the list
    head=reverseList(head);

    std::cout << "Reversed List: ";
    printList(head);

    return 0;
}