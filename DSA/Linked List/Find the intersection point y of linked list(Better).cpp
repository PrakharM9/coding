#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

class Solution {
public:
    Node* convertarr2LL(vector<int> arr) {
        if (arr.empty()) return nullptr;
        Node* head = new Node(arr[0]);
        Node* temp = head;
        for (int i = 1; i < arr.size(); i++) {
            Node* newEl = new Node(arr[i]);
            temp->next = newEl;
            temp = newEl;
        }
        return head;
    }

    void print(Node* head) {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    Node* collisionpoint(Node* head1, Node* head2, int count) {
        while (count-- && head1) {
            head1 = head1->next;
        }
        Node* t1 = head1, *t2 = head2;
        while (t1 && t2) {
            if (t1 == t2) return t1;
            t1 = t1->next;
            t2 = t2->next;
        }
        return nullptr;
    }

    Node* intersection(Node* head1, Node* head2) {
        int n1 = 0, n2 = 0;
        Node* temp = head1;
        while (temp) {
            n1++;
            temp = temp->next;
        }
        temp = head2;
        while (temp) {
            n2++;
            temp = temp->next;
        }

        if (n1 > n2)
            return collisionpoint(head1, head2, n1 - n2);
        else
            return collisionpoint(head2, head1, n2 - n1);
    }
};

int main() {
    int n1, n2;
    cin >> n1;
    vector<int> arr1(n1);
    for (int i = 0; i < n1; i++) cin >> arr1[i];

    cin >> n2;
    vector<int> arr2(n2);
    for (int i = 0; i < n2; i++) cin >> arr2[i];

    Solution sol;
    Node* head1 = sol.convertarr2LL(arr1);
    Node* head2 = sol.convertarr2LL(arr2);
    Node* temp = head2;
    while (temp && temp->next) temp = temp->next;
    if (head1 && head1->next && head1->next->next)
        temp->next = head1->next->next; 

    Node* result = sol.intersection(head1, head2);
    if (result)
        cout << result->data << " is the intersection point" << endl;
    else
        cout << "No Intersection point" << endl;

    return 0;
}
