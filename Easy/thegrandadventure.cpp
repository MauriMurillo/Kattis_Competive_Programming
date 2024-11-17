#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#define ll long long

using namespace std;
// Variables
// Variables

void solve()
{
    int T;
    stack<char> backpack;
    bool possible;
    cin >> T;
    while (T--)
    {
        possible = true;
        while (!backpack.empty())
        {
            backpack.pop();
        }
        string s, news;
        cin >> s;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != '.')
            {
                news += s[i];
            }
        }
        // cout<<news<<endl;
        for (int i = 0; i < news.size(); i++)
        {
            if (news[i] == '|' or news[i] == '$' or news[i] == '*')
            {
                backpack.push(news[i]);
                continue;
            }
            if (backpack.empty())
            {
                // cout<<news[i]<<" empty bag"<<endl;
                possible = false;
                break;
            }
            char top = backpack.top();
            // cout<<i<<" : "<<news[i]<<" -- "<<top<<endl;
            if (news[i] == 'j')
            {
                if (top != '*')
                {
                    // cout<<i<<" -- "<<news[i]<<" : "<<top<<endl;
                    possible = false;
                    break;
                }else{
                    backpack.pop();
                }
            }
            if (news[i] == 't')
            {
                if (top != '|')
                {
                    // cout<<i<<" -- "<<news[i]<<" : "<<top<<endl;
                    possible = false;
                    break;
                }else
                {
                    backpack.pop();
                }
            }
            if (news[i] == 'b')
            {
                if (top != '$')
                {
                    // cout<<i<<" -- "<<news[i]<<" : "<<top<<endl;
                    possible = false;
                    break;
                }else{
                    backpack.pop();
                }
            }
        }
        if (possible and backpack.empty())
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}