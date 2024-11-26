#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isUgly(int n) {
        int count=0;
        bool checker=true;
        set<int>values;
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0){
                values.insert(i);
                cout<<i<<" ";
            }
            if((n/i)!=i){
                values.insert(n/i);
                cout<<n/i<<" ";
            }
        }
        cout<<endl;
        for(int it:values){
            if(it!=2 && it!=3 && it!=5){
                for(int i=2;i<it;i++){
                    if(it%i==0){
                        checker=false;
                    }
                }
                if(checker){
                    count++;
                }
                checker=true;
            }
        }
        if(count>0)return false;
        return true;
    }
};
int main()
{
  Solution sol;
  int num;
  cin>>num;
  if(sol.isUgly(num)){
    cout<<"True";
  }
  else{
    cout<<"false";
  }
  return 0;
}