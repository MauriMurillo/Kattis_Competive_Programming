#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Variables
int N_rows, doors_closed;
int total_interest;
vector<vector<int> > Gallery(420, vector<int>(4, -1));
vector<vector<vector<int> > > DP(420, vector<vector<int> >(420, vector<int>(8, -1)));
// Variables
int close_door(int position, int to_close, int interest_loss, int prev)
{
  int rooms_left = N_rows - position;
  if (to_close == 0)
  {
    return DP[position][to_close][prev] = interest_loss;
  }
  if (to_close > rooms_left)
  {
    return 200000;
  }
  if (DP[position][to_close][prev] != -1)
  {
    return interest_loss + DP[position][to_close][prev];
  }
  int a, b, c;
  if (prev == 1)
  {
    // close right
    a = close_door(position + 1, to_close - 1, Gallery[position][0], 1);
    b = 200000;
    // not close
    c = close_door(position + 1, to_close, 0, 3);
  }
  else if (prev == 2)
  {
    a = 200000;
    // close left
    b = close_door(position + 1, to_close - 1, Gallery[position][1], 2);
    // not close
    c = close_door(position + 1, to_close, 0, 3);
  }
  else
  {
    // close right
    a = close_door(position + 1, to_close - 1, Gallery[position][0], 1);
    // close left
    b = close_door(position + 1, to_close - 1, Gallery[position][1], 2);
    // not close
    c = close_door(position + 1, to_close, 0, 3);
  }
  DP[position][to_close][prev] = min(a, min(b, c));
  return interest_loss + DP[position][to_close][prev];
}
void solve()
{
  while (cin >> N_rows >> doors_closed and (N_rows != 0 or doors_closed != 0))
  {
    DP.assign(420, vector<vector<int> >(420, vector<int>(8, -1)));
    total_interest = 0;
    for (int i = 0; i < N_rows; i++)
    {
      for (int j = 0; j < 2; j++)
      {
        cin >> Gallery[i][j];
        total_interest += Gallery[i][j];
      }
    }
    int ans = total_interest - close_door(0, doors_closed, 0, 3);
    cout << ans << endl;
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