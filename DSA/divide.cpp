
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        double quotient;
        if(divisor<0 && dividend<0 ){
            dividend=abs(dividend);
            divisor=abs(divisor);
        }
        quotient=dividend/divisor;
        return trunc(quotient);
    }
};
int main(){
    int divisor,dividend;
    cin>>dividend>>divisor;
    Solution sol;
    cout<<sol.divide(dividend,divisor);
    return 0;
}