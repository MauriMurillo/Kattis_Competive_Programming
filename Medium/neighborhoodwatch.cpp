#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    long long n, k;
    cin >> n >> k;
    long long safety = 0;
    long long house;
    long long last_house = 0;
    long long houses_right, houses_left;
    for (int i = 0; i < k; i++)
    {
        cin >> house;
        houses_left = (house - last_house);
        houses_right = (n - house) + 1;
        safety += (houses_left * houses_right);
        last_house = house;
    }
    cout << safety << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
