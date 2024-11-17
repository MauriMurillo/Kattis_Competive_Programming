#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;
// Variables
//Variables

void solve(){
    ll a,b;
    while (cin>>a>>b)
    {
        cout<<abs(a-b)<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}