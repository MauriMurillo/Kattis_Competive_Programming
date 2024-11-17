#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int time = 0;
    int Q, M, S, L;
    cin >> Q >> M >> S >> L;
    if (L > 0)
    {
        if (L % M == 0)
        {
            time = (L / M) * Q;
        }
        else
        {
            time = ((L / M) + 1) * Q;
            S -= (M - (L % M)) * Q;
        }
    }

    if (S > 0)
    {
        time += (S / M);
        if (S % M != 0)
            time++;
    }

    cout << time << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
