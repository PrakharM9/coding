#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string largestOddNumber(string num) {
        int number=0,digit,num2,storer=stoi(num);
        num2=num.size();
        if(storer%2!=0){
            return num;
        }
        else{
            for(int i=0;i<num2;i++){
                int digit=num[i]-'0';
                cout<<digit;
                if(digit%2!=0){
                    number=number*10+digit;
                }
                else{
                    break;
                }
            }
        }
        if(number==0){
            return "";
        }
        return to_string(number);
    }
};
int main()
{
  string str;
  cin>>str;
  Solution sol;
  string st=sol.largestOddNumber(str);
  return 0;
}