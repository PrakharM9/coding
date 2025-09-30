#include <iostream>
using namespace std;
enum class Color{
RED,
GREEN,
BLUE
};
int main()
{
Color c=Color::GREEN;
if(c==Color::GREEN)
{
cout<<"color is green!"<<endl;
}

return 0;
}