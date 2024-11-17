#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Variables
//Variables

void solve(){
    int estatuas;
    int impresoras = 1;
    int dias = 0;
    cin>>estatuas;
    while (true)
    {
        if (estatuas > impresoras)
        {
            impresoras += impresoras;
            dias++;
        }else{
            dias++;
            break;
        }
    }
    cout<<dias<<endl;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}