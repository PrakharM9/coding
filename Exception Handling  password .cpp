

// You are developing a login system for a website that requires users to provide a username and password. 



// The system has specific password requirements: it must have at least 6 characters and contain at least one digit.



// Write a program to accept username and password and throw an exception if the password has less than 6 characters or does not contain a digit.

// Input format :
// The input consists of two strings representing username and password in separate lines.

// Output format :
// The output displays whether the password is valid or not.



// Refer to the sample output for the exact text.

// Sample test cases :
// Input 1 :
// Sam
// sam123
// Output 1 :
// Password is Correct
// Input 2 :
// Sandy
// sansan
// Output 2 :
// Password must have at least one digit
// Caught by Exception 
// Invalid Password Format!
// Input 3 :
// Mano
// 2313
// Output 3 :
// Password must be at least 6 characters long
// Caught by Exception 
// Invalid Password Format!
// You are using GCC
#include<bits/stdc++.h>
using namespace std;
class NoDigit:public exception{
    public:
    const char* what() const noexcept override{
        return "Error";
    }
};
class Length:public exception{
    public:
    const char* what() const noexcept override{
        return "Error";
    }
};
int main(){
    string username,password;
    getline(cin,username);
    getline(cin,password);
    try{
        bool digits=true;
        for(char ch:password){
            if(isdigit(ch)){
                digits=false;
                break;
            }
        }
        if(password.size()<6){
            throw Length();
        }
        if(digits){
            throw NoDigit();
        }
        cout<<"Password is Correct";
    }
    catch(NoDigit& e){
        cout<<"Password must have at least one digit"<<endl;
        cout<<"Caught by Exception"<<endl;
        cout<<"Invalid Password Format!";
    }
    catch(Length& e){
        cout<<"Password must be at least 6 characters long"<<endl;
        cout<<"Caught by Exception"<<endl;
        cout<<"Invalid Password Format!";
    }
    return 0;
}