#include <bits/stdc++.h>
using namespace std;
class Student{
    private:
    string name;
    int roll;
    public:
    Student(){
        name="Ram";
        roll=24;
    }
    Student(string n,int r){
        name=n;
        roll=r;
    }
    void print(){
        cout<<name<<endl;
        cout<<roll<<endl;
    }
};
int main()
{
  Student s;
  Student s1("Ranjan",1);
  s.print();
  s1.print();
  return 0;
}