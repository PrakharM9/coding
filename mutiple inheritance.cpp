#include <bits/stdc++.h>
using namespace std;
class Animal{
    public:
    int age;
    int weight;
    public:
    void bark(){
        cout<<"Barking";
    }
};
class Human{
    public:
    string color;
    public:
    void speak(){
        cout<<"Speaking";
    }
};
class Hybrid:public Animal,public Human{
};
int main()
{
    Hybrid h;
    h.bark();
    cout<<endl;
    h.speak();
    return 0;
}