// ﻿Banu wants to develop a simple shopping cart management system for her online store. The system should allow users to add items to their shopping cart, update the quantity of items, view the total bill, and exit the program when they are done shopping. To implement this system, Banu decides to use algorithms and iterators to efficiently manage the items in the shopping cart.



// Note: This kind of question will be helpful in clearing Accenture recruitment.

// Input format :
// The input consists of the following options:



// Add Item: Add an item to their shopping cart by providing the name, quantity, and price of the item.
// Update Quantity: Update the quantity of an item in their cart by providing the item's name and the new quantity.
// View Total Bill: View the total bill for all the items in their cart.
// Exit: Exit the program when they are done shopping.
// Output format :
// The output displays the following format:



// For option 1 (Add Item), the program should display a message confirming the addition of the item to the cart.

// For option 2 (Update Quantity), the program should display a message confirming the update of the item's quantity.

// For option 3 (View Total Bill), the program should display the total bill amount for all the items in the cart.

// For option 4 (Exit), the program should display a goodbye message and terminate.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// Item names will be alphanumeric and contain at most 50 characters.

// The quantity of an item will be a positive integer.

// The price of an item will be a positive double-point number.

// The bill will be a positive double-point number.

// Sample test cases :
// Input 1 :
// 1
// Laptop
// 2
// 800.00
// 3
// 4
// Output 1 :
// Total Bill: 1600
// Exiting the program.
// Input 2 :
// 1
// Shirt
// 5
// 25.00
// 2
// Shirt
// 5
// 3
// 5
// 4
// Output 2 :
// Total Bill: 125
// Invalid choice
// Exiting the program.
#include<bits/stdc++.h>
using namespace std;
class Item{
    public:
    int quantity;
    double price;
};
int main(){
    unordered_map<string,Item>cart;
    while(true){
        int choice;
        cin>>choice;
        if(choice==1){
            cin.ignore();
            string name;
            int quantity;
            double price;
            getline(cin,name);
            cin>>quantity;
            cin>>price;
            cart[name]={quantity,price};
        }
        else if(choice==2){
            cin.ignore();
            string name;
            int nquantity;
            getline(cin,name);
            cin>>nquantity;
            cart[name].quantity=nquantity;
        }
        else if(choice==3){
            double total=0;
            for(const auto &[name,item]:cart){
                total+=item.quantity*item.price;
            }
            cout<<fixed<<setprecision(0);
            cout<<"Total Bill: "<<total<<endl;
        }
        else if(choice==4){
            cout<<"Exiting the program."<<endl;
            break;
        }
        else{
            cout<<"Invalid choice"<<endl;
        }
    }
    return 0;
}