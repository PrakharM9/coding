#include<bits/stdc++.h>
using namespace std;
enum suit{
    club=0,
    diamonds=10,
    hearts=20,
    spades=3
}card;
int main(){
    card=club;
    cout<<card<<endl;    
    cout<<"size of enum variable: "<<sizeof(card)<<"bytes ";
    return 0;
}