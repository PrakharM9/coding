

// C++ program to convert char
// to int using stoi()
#include <iostream>
#include <string>
using namespace std;
 
// Driver code
int main() 
{
  string str = "45";
  int x = stoi(str);
  cout << "The integer value of x : " << x<<endl;
  cout<<to_string(x);
  return 0;
}