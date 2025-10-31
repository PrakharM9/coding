#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    string data;
    Node* next;
    Node* back;
    Node(string data1,Node* next1,Node* back1){
        data=data1;
        next=next1;
        back=back1;
    }
    Node(string data1){
        data=data1;
        next=NULL;
        back=NULL;
    }
};
class BrowserHistory {
private:
    Node* currentPage;
public:
    BrowserHistory(string homepage) {
        currentPage=new Node(homepage);
    }
    
    void visit(string url) {
        Node* newPage=new Node(url,NULL,currentPage);
        currentPage->next=newPage;
        currentPage=newPage;
    }
    
    string back(int steps) {
        while(currentPage->back && steps){
            currentPage=currentPage->back;
            steps--;
        }
        return currentPage->data;
    }
    
    string forward(int steps) {
        while(currentPage->next && steps){
            currentPage=currentPage->next;
            steps--;
        }
        return currentPage->data;
    }
};
int main(){
    BrowserHistory bh("takeuforward.org");
    bh.visit("google.com");
    bh.visit("instagram.com");
    bh.visit("facebook.com");
    cout<<bh.back(1)<<endl;
    cout<<bh.back(1)<<endl;
    cout<<bh.forward(1)<<endl;
    bh.visit("takeuforward.org");
    cout<<bh.forward(2)<<endl;
    cout<<bh.back(2)<<endl;
    cout<<bh.back(7)<<endl;
    return 0;
}