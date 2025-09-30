#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dayOfYear(string date) {
        vector<int>months{31,28,31,30,31,30,31,31,30,31,30,31};
        int days=0;
        int year=stoi(date.substr(0,4));
        int month=stoi(date.substr(5,2));
        int day=stoi(date.substr(8,2));
        if(year>1900 && year%4==0 && month>2){
            days+=1;
        }
        while(month>1){
            days+=months[month-1];
            month--;
        }
        days+=day;
        cout<<year<<" "<<month<<" "<<day<<endl;
        return days;
    }
};
int main()
{
  Solution sol;
  cout<<sol.dayOfYear("2019-02-10");
  return 0;
}