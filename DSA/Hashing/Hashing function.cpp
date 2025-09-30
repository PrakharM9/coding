#include <iostream>
using namespace std;
int SIZE = 100;
// You are using GCC
#include<vector>;
int calHash(int key, int size)
{
    //Type your code here
    return key%size;
}

int main() {
    //Type your code here
    int size,num;
    cin>>size;
    cin>>num;
    vector<int>keys(num);
    for(int i=0;i<num;i++){
        cin>>keys[i];
    }
    vector<int>hashtable(size,-1);
    for(int key:keys){
        int index=calHash(key,size);
        while(hashtable[index]!=-1){
            index=(index+1)%size;
        }
        hashtable[index]=key;
    }
    for(int it:keys){
        for(int i=0;i<size;i++){
            if(hashtable[i]==it){
                cout<<i<<" ";
                break;
            }
        }
    }
    return 0;
}