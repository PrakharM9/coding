#include <bits/stdc++.h>
using namespace std;
class Human{
    public:
    int height;
    int weight;
    int age;
    public:
    int getage(){
        return age;
    }
    void setweight(int value){
        weight=value;
    }
};
class Male: public Human{
    public:
    string color;
    void sleep(){
        cout<<"Male is sleeping"<<endl;
    }
};
int main()
{
  
  return 0;
}