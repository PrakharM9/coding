#include <bits/stdc++.h>
using namespace std;
class Animal{
    public:
    int age;
    int weight;
    public:
    void speak(){
        cout<<"Speaking";
    }
};
class Dog: public Animal{

};
class GermanShepherd:public Dog{

};
int main()
{
  GermanShepherd gs;
  gs.speak();
  return 0;
}