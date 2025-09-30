#include<bits/stdc++.h>
using namespace std;
//Functions are used to modularize code;
//Functions are used to increase readability
//Functions are used to use same code multiple times
//void -> which does not return 
//return 
//parameterised
//non parameterised
void printName(string name){
    cout << "Hey " << name <<"!";
}
int main(){
    string name;
    cin >> name;
    printName(name);
    return 0;
}