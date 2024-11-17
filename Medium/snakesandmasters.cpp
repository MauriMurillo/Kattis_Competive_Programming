#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
// Variables
vector<long long> fib(10100,-1);


void solve(){
    int N;
    cin>>N;
    fib[1] = 1;
    fib[2] = 1;
    for (int i = 3; i <= N+2; i++)
    {
        fib[i] = ((fib[i-1]%1000000) + (fib[i-2]%1000000))%1000000;
    }
    cout<<(fib[N+1]%1000000)<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}