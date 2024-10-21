#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumSwap(int num) {
        int size=0,max=-1,index=-1,index2,num2=num;
        bool status=false;
        vector<int>digits;
        while(num2>0){
            int digit=num2%10;
            digits.insert(digits.begin(),digit);
            num2/=10;
            size++;
        }
        for(int i=0;i<size-1;i++){
            for(int j=i+1;j<digits.size();j++){
                if(digits[j]>digits[i] && digits[j]>max){
                    max=digits[j];
                    status=true;
                    index=j;
                    index2=i;
                }
            }
        }
        if(status){
            int temp=digits[index2];
            digits[index2]=digits[index];
            digits[index]=temp;
        }
        if(!status){
            return num;
        }
        num2=0;
        for(int it:digits){
            num2=num2*10+it;
        }
        return num2;
    }
};
int main()
{
  int num;
  cin>>num;
  Solution sol;
  cout<<sol.maximumSwap(num);
  return 0;
}