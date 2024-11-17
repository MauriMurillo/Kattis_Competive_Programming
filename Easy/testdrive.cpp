#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define ll long long

using namespace std;
// Variables
//Variables

void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    pair<bool,int> min1,min2;
    //first dir, and distance
    min1.second = abs(b-a);
    min2.second = abs(c-b);
    min1.first = (b>a);
    min2.first = (c>b);
    //True forward
    if (min1.first == min2.first)
    {
        if (min1.second > min2.second)
        {
            cout<<"braked"<<endl;
        }else if (min1.second < min2.second)
        {
            cout<<"accelerated"<<endl;
        }else{
            cout<<"cruised"<<endl;
        }
    }else{
        cout<<"turned"<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}