// Joseph wants a program to validate email addresses based on certain criteria. The program should check whether an entered email address confirms to the specified rules and throw a custom exception if it is invalid.



// The program should define a custom exception class, InvalidEmailException, to handle cases where the email is not valid.

// The validation criteria for a valid email are as follows:

// The email must start with a letter (either uppercase or lowercase).
// It must contain the characters '@' and '.' in the correct order.
// The '@' symbol must appear before the '.' symbol.
// The email must have at least one character before the '@' symbol and one character between the '@' and '.' symbols.
// The email must end with at least one character after the '.' symbol.


// If any of these conditions are not met, the program should throw an exception and output "Invalid Email Id!!!". Otherwise, it should output "Email Id is Valid".

// Input format :
// The input consists of a single line containing a string representing the email address.

// Output format :
// If the entered email is valid, print "Email Id is Valid"

// If the email is not valid, throw and catch the InvalidEmailException and print the custom error message.



// Refer to the sample output for the exact text and format.

// Code constraints :
// The length of the email address ≤ 100

// The email address can only contain alphabetical characters (both uppercase and lowercase), digits, '@', and '.' symbols.

// Sample test cases :
// Input 1 :
// abc@example.com
// Output 1 :
// Email Id is Valid
// Input 2 :
// 12345@example.com
// Output 2 :
// Exception Caught...
// Invalid Email Id!!!
// You are using GCC
#include<bits/stdc++.h>
using namespace std;
class InvalidEmailException{
    public:
    string str;
    InvalidEmailException(string s){
        str=s;
    }
    void check(){
        string name;
        bool checkend=false,checkdomain=false,checkname=false;
        int atpos=-1,dotpos=-1;
        for(int i=0;i<str.size();i++){
            if(str[i]=='@'){
                atpos=i;
                break;
            }
        }
        for(int i=0;i<str.size();i++){
            if(str[i]=='.'){
                dotpos=i;
                break;
            }
        }
        if(atpos==-1 || dotpos==-1 || atpos>dotpos){
            throw InvalidEmailException("Invalid Email");
        }
        for(int i=0;i<atpos;i++){
            if(isalpha(str[i])){
                checkname=true;
                break;
            }
        }
        for(int i=atpos+1;i<dotpos;i++){
            if(isalpha(str[i])){
                checkdomain=true;
                break;
            }
        }
        for(int i=dotpos+1;i<str.size();i++){
            if(isalpha(str[i])){
                checkend=true;
                break;
            }
        }
        if(isalpha(str[0]) && checkname && checkdomain && checkend){
            cout<<"Email Id is Valid"<<endl;
        }
        else{
            throw InvalidEmailException("Exception Caught");
        }
    }
};
int main(){
    string str;
    getline(cin,str);
    InvalidEmailException IEE(str);
    try{
        IEE.check();
    }
    catch(InvalidEmailException& e){
        cout<<"Exception Caught..."<<endl;
        cout<<"Invalid Email Id!!!"<<endl;
    }
    return 0;
}