// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int main(){
    bool status=true;
    int quantity;
    string str;
    double price;
    while(status){
        int choice;
        cin>>choice;
        switch(choice){
            case 1:
            getline(cin,str);
            cin>>quantity;
            cin>>price;
            cin.ignore();
            break;
            case 2:
            getline(cin,str);
            cin>>quantity;
            cin.ignore();
            break;
            case 3:
            cout<<"Total Bill: "<<price*quantity<<endl;
            break;
            case 4:
            cout<<"Exiting the program."<<endl;
            status=false;
            break;
            default:
            cout<<"Invalid choice"<<endl;
            break;
        }
    }
    return 0;
}