#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int data1,Node* next1){
        val=data1;
        next=next1;
    }
    Node(int data1){
        val=data1;
        next=nullptr;
    }
};
class Solution {
public:
    void deleteNode(Node* node) {
      Node* nextel=node->next;
      node->val=nextel->val;
      node->next=nextel->next;
      delete(nextel);
    }
};
int main()
{
    
    return 0;
}