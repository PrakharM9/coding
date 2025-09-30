#include<bits/stdc++.h>
using namespace std;
int main(){
    //Everything is same as set but the only difference is that it allows to store duplicate values
    multiset<int>ms;
    ms.insert(1);//{1}
    ms.insert(1);//{1,1}
    ms.insert(1);//{1,1,1}
    
    ms.erase(1);//all 1 are erased

    int cont=ms.count(1);

    ms.erase(ms.find(1));
    //only a single one is erased

    ms.erase(ms.find(1), ms.find(1)+2);
    return 0;
}