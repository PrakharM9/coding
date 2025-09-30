#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        int multiplier=1;
        vector<int>answer;
        while(n>0){
            int digit=n%10;
            answer.insert(answer.begin(),digit*multiplier);
            multiplier*=10;
            n/=10;
        }
        return answer;
    }
};
int main()
{
  Solution sol;
  vector<int>ans=sol.decimalRepresentation(537);
  for(auto it:ans){
    cout<<it<<" ";
  }
  return 0;
}
