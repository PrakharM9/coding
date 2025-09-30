#include <bits/stdc++.h>
using namespace std;
template<typename T1,typename T2>
class PairDerived{
    private:
    T1 first;
    T2 second;
    public:
    PairDerived(T1 a,T2 b){
        first=a;
        second=b;
    }
    void swap(){
        T1 temp=first;
        first=static_cast<T1>(second);
        second=static_cast<T2>(temp);
    }
    void display(){
        cout<<"First: "<<first<<endl;
        cout<<"Second: "<<second<<endl;
    }
};
int main() {
    float a;
    double b;
    cin >> a;
    cin >> b;
    PairDerived<float, double> p(a, b);

    cout << "Values before swap: " << endl;
    p.display();

    p.swap();

    cout << "Values after swap: " << endl;
    p.display();

    return 0;
}