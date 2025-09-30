//Smith wants to buy a second-hand car so he wants to check for a few parameters before buying. So you have to design a class Car with private attributes brand and fuelConsumption. Implement a friend function calculateFuelCost(Car&, double , double ) that takes a car object, the distance traveled, and the fuel price per liter as parameters and calculates and returns the total fuel cost. 
// Write a program to input the brand, fuel consumption, distance traveled, and fuel price, create an object of the Car class, calculate the fuel cost using the calculateFuelCost function, and display the result.
// Note: This is a sample question asked in TCS recruitment.
// Input format :
// The first line consists of the car brand as a string.
// The second line consists of the fuel consumption in liters per 100 km as a double.
// The third line consists of the distance traveled in kilometers as a double.
// The fourth line consists of the fuel price per liter as a double.
// Output format :
// The output prints the total fuel cost as a double, rounded off to two decimal places.
// Refer to the sample output for the formatting specifications.
// Code constraints :
// The brand string will have a maximum length of 50 characters.
// 0 < fuelConsumption <= 100
// 0 < distance <= 1000.0
// 0 < fuelPrice <= 100.0
#include<bits/stdc++.h>
using namespace std;
class Car{
    private:
        string brand;
        double fuelConsumption;
    public:
        friend double calculateFuelCost(Car&,double,double);
    void set(double f){
        fuelConsumption=f;
    }
        
};
double calculateFuelCost(Car& c,double distance,double fuelprice){
    return c.fuelConsumption*distance*fuelprice;
}
int main(){
    Car c;
    string brand;
    cin>>brand;
    double fuelConsumption,distance,fuelprice,result;
    cin>>fuelConsumption;
    fuelConsumption*=0.01;
    c.set(fuelConsumption);
    cin>>distance;
    cin>>fuelprice;
    result=calculateFuelCost(c,distance,fuelprice);
    cout<<fixed<<setprecision(2)<<result;
}