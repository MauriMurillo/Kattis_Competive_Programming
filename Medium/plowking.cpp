#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    long long n, m;
    cin >> n >> m;
    long long start = (n * (n - 1)) / 2;
    long long extra_roads = m - (n - 1);
    long long increment = n - 3;
    long long num_increments = 1;
    long long incremented = 0;

    while (extra_roads > 0)
    {
        if (extra_roads > num_increments)
        {
            start += (increment * num_increments);
            extra_roads -= num_increments;
            num_increments += 1;
            increment -= 1;
        }
        else
        {
            start += (increment * extra_roads);
            break;
        }
    }
    cout << start << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
