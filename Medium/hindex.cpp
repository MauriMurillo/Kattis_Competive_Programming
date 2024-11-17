#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n;
    long long c;
    cin >> n;

    int arr[n + 1];
    for (int i = 0; i <= n; i++)
    {
        arr[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        if (c > n)
        {
            arr[n] += 1;
        }
        else
        {
            arr[c] += 1;
        }
    }
    int acc = 0;
    for (int i = n; i >= 0; i--)
    {
        acc += arr[i];
        arr[i] = acc;
    }
    int h = 0;
    for (int i = 0; i <= n; i++)
    {
        if (arr[i] >= i)
            h = i;
    }
    cout << h << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
