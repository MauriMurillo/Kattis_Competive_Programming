#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Variables
int test_cases, answer;
string orig_string,p;
//Variables
bool verify_repeat(){
    int index = 0;
    for (int i = 0; i < orig_string.size(); i++)
    {
        if (p[index] != orig_string[i])
        {
            return false;
        }
        index++;
        index = index % p.size();
    }
    return true;
}
void solve(){
    cin>>test_cases;
    cin.ignore();
    while (test_cases--)
    {
        orig_string = "";
        p = "";
        getline(cin, orig_string);
        p.push_back(orig_string[0]);
        answer = 1;
        if(verify_repeat()){
            cout<<answer<<endl;
            continue;
        }
        for (int i = 1; i < orig_string.size(); i++)
        {
            p.push_back(orig_string[i]);
            answer++;
            if(verify_repeat()){
                cout<<answer<<endl;
                break;
            }
        }
    }
}


int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    solve();
    return 0;
}