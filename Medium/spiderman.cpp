#include <iostream>
#include <vector>
using namespace std;
int test_cases, num_workouts;
int up, down;
vector<int> distances;
vector<vector<pair<int, string> > > DP;
void showDP()
{
  for (int i = 0; i < 22; i++)
  {
    cout << "Day : " << i << endl;
    for (int j = 0; j < 130; j++)
    {
      cout <<"  "<<"Height -> "<<j<<" --> "<<DP[i][j].second<< " cost: "<<DP[i][j].first<<endl;
    }
  }
}
void solve()
{
  cin >> test_cases;
  while (test_cases--)
  {
    cin >> num_workouts;
    distances.assign(num_workouts + 10, 0);
    DP.assign(50, vector<pair<int, string> >(4100, make_pair(10000, "")));
    for (int i = 0; i < num_workouts; i++)
    {
      cin >> distances[i];
    }

    DP[num_workouts - 1][distances[num_workouts - 1]] = make_pair(distances[num_workouts - 1], "D");
    for (int i = (num_workouts - 2); i >= 0; i--)
    {
      for (int j = 0; j <= 1010; j++)
      {
        if (j - distances[i] < 0)
        {
          if (DP[i + 1][j + distances[i]].first == 10000)
          {
            DP[i][j] = make_pair(10000, "");
            continue;
          }
          else
          {
            DP[i][j] = make_pair(max(j + distances[i], DP[i + 1][j+distances[i]].first), "U" + DP[i + 1][j+distances[i]].second);
            continue;
          }
        }
        if (j + distances[i] >= 1000)
        {
          if (DP[i + 1][j - distances[i]].first == 10000)
          {
            DP[i][j] = make_pair(10000, "");
            continue;
          }
          else
          {
            DP[i][j] = make_pair(max(j, DP[i + 1][j-distances[i]].first), "D" + DP[i + 1][j-distances[i]].second);
            continue;
          }
        }
        up = DP[i + 1][j + distances[i]].first;
        down = DP[i + 1][j - distances[i]].first;
        if (up == 10000 && down == 10000)
        {
          DP[i][j] = make_pair(10000, "");
          continue;
        }
        if (up < down)
        {
          DP[i][j] = make_pair(max(j + distances[i], DP[i + 1][j+distances[i]].first), "U" + DP[i + 1][j+distances[i]].second);
          continue;
        }
        else
        {
          DP[i][j] = make_pair(max(j, DP[i + 1][j-distances[i]].first), "D" + DP[i + 1][j-distances[i]].second);
          continue;
        }
      }
    }
    // showDP();
    if (DP[0][0].first == 10000)
    {
      cout << "IMPOSSIBLE" << endl;
    }
    else
    {
      cout << DP[0][0].second << endl;
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