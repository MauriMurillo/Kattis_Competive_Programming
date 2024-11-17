#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define ll long long

using namespace std;
// Variables
//Variables



void solve(){
    map<char,string> dic;
    dic['a'] = "@";
    dic['b'] = "8";
    dic['c'] = "(";
    dic['d'] = "|)";
    dic['e'] = "3";
    dic['f'] = "#";
    dic['g'] = "6";
    dic['h'] = "[-]";
    dic['i'] = "|";
    dic['j'] = "_|";
    dic['k'] = "|<";
    dic['l'] = "1";
    dic['m'] = "[]\\/[]";
    dic['n'] = "[]\\[]";
    dic['o'] = "0";
    dic['p'] = "|D";
    dic['q'] = "(,)";
    dic['r'] = "|Z";
    dic['s'] = "$";
    dic['t'] = "\'][\'";
    dic['u'] = "|_|";
    dic['v'] = "\\/";
    dic['w'] = "\\/\\/";
    dic['x'] = "}{";
    dic['y'] = "`/";
    dic['z'] = "2";
    string input;
    string ans;
    getline(cin, input);
    for (int i = 0; i < input.size(); i++)
    {
        if ( dic.find(tolower(input[i])) == dic.end()){
            ans += input[i];
        }else{
            ans += dic[tolower(input[i])];
        }
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}