//it is problem virtual base class
#include <iostream>
using namespace std;
class Grandparent{
public:
void show()
{
cout<<"this is a grandparent function"<<endl;
}
};
class Parent1:virtual public Grandparent{};
class Parent2:virtual public Grandparent{};
class Child: public Parent1, public Parent2{};
int main()
{
Child myChild;
myChild.show();

return 0;
}