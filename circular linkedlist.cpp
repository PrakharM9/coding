#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
    node(int value=0)
    {
        data=value;
        next=nullptr;
    }
};
class CircularLinkedList
{
    private:
    node *header;
    public:
    CircularLinkedList()
    {
        header=new node();
        header->next=header;
    }
    void insert(int value)
    {
        node *newNode=new node(value);
        node *temp=header;
        while(temp->next!=header)
        {
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->next=header;
    }
    void deleteNode(int value)
    {
        node *current=header->next;
        node *prev=header;
        while(current!=header && current->data!=value)
        {
            prev=current;
            current=current->next;
        }
        if(current==header)
        {
            cout<<"value not found";
            return;
        }
        prev->next=current->next;
        delete current;
    }
    void display()
    {
        node *temp=header->next;
        while(temp!=header)
        {
            cout<<temp->data<<" ->";
            temp=temp->next;
        }
        cout<<"HEADER"<<endl;
    }

};
int main()
{
    CircularLinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.display();
    list.deleteNode(10);
    list.display();

    return 0;
}