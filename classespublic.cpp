#include<bits/stdc++.h>
using namespace std;
class Circle{
    private:
        double radius;
    public:
        void compute_area(double r){
            radius=r;
            double area=3.14*radius*radius;
            cout<<"Radius is : "<<fixed<<setprecision(1)<<radius<<endl;
            cout<<"Area is: "<<area;
        }

};
int main(){
    Circle cir;
    double rad;
    cin>>rad;
    cir.compute_area(rad);
}