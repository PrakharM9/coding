#include <bits/stdc++.h>
using namespace std;
class A{
    public:
    void func(){
        cout<<"I am A"<<endl;
    }
};
class B{
    public:
    void func(){
        cout<<"I am B"<<endl;
    }
};
class C:public A,public B{
    
};
int main()
{
  C obj;
  //If we will call like onj.func() then It will throw ambiguity error as it will not be able to know which class we are talking about
  //But we can use Scope Ambiguity Operator as we are using in below code
  obj.A::func();
  obj.B::func();
  return 0;
}