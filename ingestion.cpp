#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
vector<int> kcal;

int after_eat(int i)
{
  return min(m, kcal[i + 1]);
}
int after_not_eat(int i)
{
  if (i == 0)
    return m;
  return kcal[i - 1];
}
void solve()
{
  cin >> n >> m;
  vector<int> food(n, -1);
  kcal = vector<int>(n + 1, m);
  for (int i = 1; i <= n; i++)
  {
    kcal[i] = (kcal[i - 1] * 2) / 3;
  }

  for (int i = 0; i < n; i++)
  {
    cin >> food[i];
  }

  vector<vector<int> > table(n + 3, vector<int>(n + 3, -1));
  table[0][0] = 0;
  for (int j = 0; j <= n; j++)
  {
    for (int i = 0; i <= n; i++)
    {
      if (table[j][i] == -1)
      {
        continue;
      }
      else
      {
        table[j + 1][i + 1] = max(table[j][i] + min(food[j], kcal[i]), table[j + 1][i + 1]); // eating
        table[j + 1][max(i - 1, 0)] = max(table[j][i], table[j + 1][max(i - 1, 0)]); // not eat
        table[j + 2][0] = max(table[j][i], table[j + 2][0]);                         // not eat two days
      }
    }
  }

  int maxi = 0;
  for (int i = 0; i <= n; i++)
  {
    maxi = max(maxi, table[n][i]);
  }
  cout << maxi << endl;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}