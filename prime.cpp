#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> closestPrimes(int left, int right) {
            int num1=-1,num2=-1;
            int count=0,counter=0;
            int lastprime;
            vector<int>primes;
            for(int i=left;i<=right;i++){
                for(int j=2;j<=sqrt(i);j++){
                    if(i%j==0){
                        count++;
                        if(i/j!=j){
                            count++;
                        }
                    }
                }
                if(count==0){
                    if(num1==-1)num1=i;
                    else if(num2==-1)num2=i;
                    else{
                        if(num2-num1>i-lastprime){
                            num1=lastprime;
                            num2=i;
                        }
                    }
                    if(counter>0)lastprime=i;
                    counter++;
                }
                count=0;
                if(num2-num1==2)break;
            }
            vector<int>result;
            if(num1!=-1 && num2!=-1){
                result.push_back(num1);
                result.push_back(num2);
            }
            else{
                result.push_back(-1);
                result.push_back(-1);
            }
            return result;
        }
    };
int main()
{
  vector<int>res=Solution().closestPrimes(19,31);
  for(auto it:res){
    cout<<it<<" ";
  }
  return 0;
}