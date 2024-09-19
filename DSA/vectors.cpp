#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>v;

    v.push_back(1);
    v.emplace_back(2);

    vector<pair<int,int>>vec;
    vec.push_back({1,2});
    vec.emplace_back(1,2);

    vector<int>v(5,100);
    //It will have values stored as {100,100,100,100,100}
    vector<int>v(5);
    //It will either have 5 times zeros or It will have some garbage values
    vector<int>v1(5,20);
    //It will declare a container of 5 instances of 20 like {20,20,20,20,20}
    vector<int>v2(v1);
    //Above method can be used to copy values of one vector into another
    //We can access these elements like we acess array's elements

    //The other way is iterator way which points to the memory where it is saved
    vector<int>::iterator it=v1.begin();
    it++;
    //It will move to next element
    cout<<*(it)<<" ";
    it+=2;
    cout<<*(it)<<" ";
    //Apart from begin iterator we also have end(),rend() and rbegin()
    //Iterator end will move the adress after the last element
    //vector<int>::iterator it=v.end; it-- will point to the last member of the vector
    //vector rend will point at the adress just before start of the vector
    //vector rbe
    cout<<v[0]<<v.at(0);
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*(it)<<" ";
    }
    for(auto it:v){
        cout<<it<<" ";
    }
    //to delete any member in vector we can delete by using erase
    v.erase(v.begin()+1);
    v.erase(v.begin()+2,v.begin()+4);
    //when we give range to get erase in vector end point is not included

    vector<int>v(2,100);//{100,100}
    v.insert(v.begin(),300);//{300,100,100}
    v.insert(v.begin()+1,2,10);//{300,10,10,100,100}

    //Copying data from one vector to other
    vector<int>copy(2,50);//{50,50}
    v.insert(v.begin(),copy.begin(),copy.end());//{50,50,300,10,10,100,100}
    
    //{10,20}
    cout<<v.size();//2

    v.pop_back();
    //It removes last element from vector

    v1.swap(v2);
    //It is used to swap values of vectors

    v.clear();
    //trims down to empty vector

    cout<<v.empty();

}