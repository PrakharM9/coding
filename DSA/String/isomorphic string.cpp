#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        bool status=true;
        vector<char>characters1;
        vector<char>characters2;
        vector<int>counter1;
        vector<int>counter2;
        int con=1,count=0;
        for(int i=0;i<s.size();i++){
            for(int j=0;j<characters1.size();j++){
                if(s[i]==characters1[j]){
                    con=0;
                }
            }
            if(con==1){
                characters1.push_back(s[i]);
            }
            con=1;
        }
        for(int i=0;i<characters1.size();i++){
            for(int j=0;j<s.size();j++){
                if(s[j]==characters1[i]){
                    count++;
                }
            }
            counter1.push_back(count);
            count=0;
        }
        for(int i=0;i<t.size();i++){
            for(int j=0;j<characters2.size();j++){
                if(t[i]==characters2[j]){
                    con=0;
                }
            }
            if(con==1){
                characters2.push_back(t[i]);
            }
            con=1;
        }
        for(auto it: characters2){
            cout<<it<<" ";
        }
        for(int i=0;i<characters2.size();i++){
            for(int j=0;j<t.size();j++){
                if(t[j]==characters2[i]){
                    count++;
                }
            }
            counter2.push_back(count);
            count=0;
        }
        if(counter1.size()==counter2.size()){
            for(int i=0;i<counter1.size();i++){
                if(counter1[i]!=counter2[i]){
                    status=false;
                }
            }
        }
        else{
            status=false;
        }
        return status;
    }
};

int main()
{
    Solution sol;
    string str1,str2;
    cin>>str1>>str2;
    if(sol.isIsomorphic(str1,str2)){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
    return 0;
}