#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;
// Variables
//Variables
int string_to_bin(string s){
    int tot = 0;
    int aux= 1;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i]=='B')
        {
            tot += aux;
        }
        aux = aux*2;
    }
    return tot;
}
string num_to_string(ll a){
    string ans = "";
    while (a!= 0)
    {
        if (a%2 == 0)
        {
            ans += 'A';
        }else{
            ans += 'B';
        }
        a = a/2;
    }
    return ans;
}
void solve(){
    string s;
    int D;
    cin>>s>>D;
    int ans = string_to_bin(s) +D;
    string answer = num_to_string(ans);
    int fill = s.size() - answer.size();
    while (fill--)
    {
        answer+='A';
    }
    cout<<answer<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}

