#include <bits/stdc++.h>
using namespace std;
struct Employee{
    int id;
    char name[21] ;
    char dob[11] ;
    char doj[11] ;
    float salary;
    
};
int main(){
    struct Employee e;
    cin>>e.id;
    cin.ignore();
    cin.getline(e.name,21);
    cin.getline(e.dob,11);
    cin.getline(e.doj,11);
    cin>>e.salary;
    cout<<"ID : "<<e.id<<endl;
    cout<<"Name : "<<e.name<<endl;
    cout<<"DOB : "<<e.dob<<endl;
    cout<<"DOJ : "<<e.doj<<endl;
    cout<<"Salary : "<<fixed<<setprecision(1)<<e.salary<<endl;
    
}