#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;
// Variables
// Variables
char op[] = {'+', '*', '/', '-'};
void solve()
{
    int mini = 100000000;
    int a, b, c;
    cin>>a>>b>>c;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (op[i] == '+')
            {
                if (op[j] == '+')
                {
                    if (a+b+c >= 0)
                    {
                        cout<<(a+b+c)<<endl;
                    }
                }
                else if (op[j] == '*')
                {
                    if ((a+b)*c >= 0)
                    {
                        cout<<(a+b)*c<<endl;
                    }
                }
                else if (op[j] == '/')
                {
                    if ((a+b)/c >= 0 && (a+b)%c ==0)
                    {
                        cout<<((a+b)/c)<<endl;;
                    }
                }
                else
                {
                    if (a+b-c >= 0)
                    {
                        cout<<(a+b-c)<<endl;
                    }
                }
            }
            else if (op[i] == '*')
            {
                if (op[j] == '+')
                {
                    if ((a*b)+c >= 0)
                    {
                        cout<<((a*b)+c)<<endl;
                    }
                }
                else if (op[j] == '*')
                {
                    if (a*b*c >= 0)
                    {
                        cout<<(a*b*c)<<endl;
                    }
                }
                else if (op[j] == '/')
                {
                    if ((a*b)/c >=0 && (a*b)%c ==0)
                    {
                        cout<<((a*b)/c)<<endl;
                    }
                }
                else
                {
                    if ((a*b)-c >= 0)
                    {
                        cout<<((a*b)-c)<<endl;
                    }
                }
            }
            else if (op[i] == '/')
            {
                if (op[j] == '+')
                {
                    if ((a/b)+c >= 0 && a%b ==0)
                    {
                        cout<<(a/b+c)<<endl;
                    }
                }
                else if (op[j] == '*')
                {
                    if ((a/b)*c >= 0 && a%b ==0)
                    {
                        cout<<((a/b)*c)<<endl;
                    }
                }
                else if (op[j] == '/')
                {
                    if (a/b/c>=0 && a%b ==0 && (a/b)%c == 0)
                    {
                        cout<<(a/b/c)<<endl;
                    }
                }
                else
                {
                    if (a/b-c >= 0 && a%b ==0)
                    {
                        cout<<(a/b-c)<<endl;
                    }
                }
            }
            else
            {
                if (op[j] == '+')
                {
                    if (a-b+c >= 0)
                    {
                        cout<<(a-b+c)<<endl;
                    }
                }
                else if (op[j] == '*')
                {
                    if ((a-b)*c >= 0)
                    {
                        cout<<((a-b)*c)<<endl;
                    }
                }
                else if (op[j] == '/')
                {
                    if ((a-b)/c >= 0 && (a-b)%c ==0)
                    {
                        cout<<"l "<<((a-b)/c)<<endl;
                    }
                }
                else
                {
                    if (a-b-c >= 0)
                    {
                        cout<<(a-b-c)<<endl;
                    }
                }
            }
        }
    }
    cout<<mini<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}