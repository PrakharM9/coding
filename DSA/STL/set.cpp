#include <bits/stdc++.h>
using namespace std;
int main(){
    set<int>st;
    //Every command happens in o(logn) time complexity
    //it does not stores duplicates and it stores the data in sorted order
    st.insert(1);//{1}
    st.emplace(2);//{1,2}
    st.insert(2);//{1,2}
    st.insert(4);//{1,2,4}
    st.insert(3);//{1,2,3,4}

    //functionality of insert in vector can also be used as it only increases effeciciency

    //begin(), end(), rbegin(), rend(), size(),
    //empty() and swap() are same as those of above  

    st.insert(5);

    //{1,2,3,4,5}
    auto it=st.find(3);

    //{1,2,3,4,5}
    auto it=st.find(6);
    //if element is not present in set then iterator will point at the address after set's last element

    st.erase(5);
    //it will delete 5 so set will be {1,2,3,4}

    int cnt=st.count(1);
    //if element will exist then it will only have value as 1 otherwise value will be 0

    auto it=st.find(3);
    st.erase(it);
    //It will erase the element which will be at that index

    auto it1=st.find(2);
    auto it2=st.find(4);
    st.erase(it1,it2);

    //lower_bound() and upper_bpund() function works in the same way as it works in vector it doess

    return 0;
}