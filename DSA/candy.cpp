#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int candy(vector<int>& ratings) {
        int s=ratings.size();
        if(s==1)return 1;
        vector<int>candies(s,1);
        for(int i=0;i<s;i++){
            if((i-1>=0 && ratings[i-1]<ratings[i] && candies[i]<=candies[i-1]) || (i+1<s && ratings[i+1]<ratings[i] && candies[i]<=candies[i+1])){
                candies[i]+=1;
                i--;
            }
        }
        for(int i=0;i<s;i++){
            if((i-1>=0 && ratings[i-1]<ratings[i] && candies[i]<=candies[i-1]) || (i+1<s && ratings[i+1]<ratings[i] && candies[i]<=candies[i+1])){
                candies[i]+=1;
                i--;
            }
        }
        int sum=0;
        for(int it:candies){
            cout<<it<<" ";
            sum+=it;
        }
        cout<<endl;
        return sum;
    }
};
int main()
{
  Solution sol;
  vector<int>vals{1,2,87,87,87,2,1};
  cout<< sol.candy(vals);
  return 0;
}