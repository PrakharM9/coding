// In a manufacturing plant, Kishore is building a system to track the dimensions of three key components, labeled x, y, and z. The system needs to:
// 		i) Rotate the dimensions as follows:
// x becomes y
// y becomes z
// z becomes the original x
// 		ii) Identify the smallest dimension after the rotation.
// Write a program that reads three integer values (for x, y, and z), performs the rotation, and then finds and displays the smallest dimension among the three.
// Function Specifications:
// void rotate(int& a, int& b, int& c)
// int& getSmallest(int& a, int& b, int& c)
// Note: This is a sample question asked in TCS recruitment.
// Input format :
// The input consists of the three integers x, y, and z, representing the initial dimension of the first, second, and third components separated by spaces.
// Output format :
// The output displays the following format:
// The values of x, y, and z before rotation in the format: "Before Rotation: x: <x> y: <y> z: <z>".
// The values of x, y, and z after rotation in the format: "After Rotation: x: <new x> y: <new y> z: <new z>".
// The smallest value among x, y, and z after rotation in the format: "The smallest value among x, y, z: <smallest>".
// Refer to the sample output for the formatting specifications.
// // Code constraints :
// -100 ≤ x, y, and z ≤ 100
#include<bits/stdc++.h>
using namespace std;
void rotate(int& a,int& b,int& c){
    int temp1,temp2;
    temp1=a;
    temp2=b;
    a=temp2;
    b=c;
    c=temp1;
    cout<<"After Rotation: x: "<<a<<" y: "<<b<<" z: "<<c<<endl;;
}
int& getSmallest(int& a,int& b,int& c){
    if(a<b && a<c){
        return a;
    }
    else if(b<c){
        return b;
    }
    else{
        return c;
    }
}
int main(){
    int n1,n2,n3;
    cin>>n1>>n2>>n3;
    cout<<"Before Rotation: x: "<<n1<<" y: "<<n2<<" z: "<<n3<<endl;
    rotate(n1,n2,n3);
    int& min=getSmallest(n1,n2,n3);
    cout<<"The smallest value among x, y, z: "<<min;
    return 0;
}