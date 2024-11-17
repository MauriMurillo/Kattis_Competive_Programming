#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;
// Variables
vector<int> mess;
vector<int> clean;
int N;
int Visits;
vector<vector<int> > DP;
// Variables
void showDP(int b, int n)
{
  for (int i = b; i < n; i++)
  {
    cout << "day: " << i << endl;
    for (int j = 0; j < abs(b - n) + 1; j++)
    {
      cout << DP[i][j] << " ";
    }
    cout << endl;
  }
}
void solve()
{
  cin >> N >> Visits;
  mess.assign(N + 10, 0);
  clean.assign(N + 10, 0);
  DP.assign(N + 10, vector<int>(N + 10, -1));
  for (int i = 0; i < N; i++)
  {
    cin >> mess[i] >> clean[i];
  }
  int totalDaysCleaned = 0;
  int previousAnswer = 0;
  int previousVisit = 0;
  int actualVisit = N;
  int yesClean, noClean;
  bool posible = true;
  while (Visits--)
  {
    previousAnswer = -1;
    cin >> actualVisit;
    actualVisit--;
    DP[actualVisit][0] = 0;
    DP[actualVisit][1] = clean[actualVisit];
    if (actualVisit == previousVisit)
    {
      if (mess[previousVisit] == 0)
      {
        previousAnswer = 0;
      }
      else if (mess[previousVisit] <= clean[previousVisit])
      {
        previousAnswer = 1;
      }
    }

    for (int i = actualVisit - 1; i >= previousVisit; i--)
    {
      if (mess[i + 1] == 0)
      {
        DP[i][0] = DP[i + 1][0];
        if (i == previousVisit && mess[previousVisit] == 0)
        {
          previousAnswer = 0;
          break;
        }
      }
      for (int j = 1; j <= N; j++)
      {
        noClean = DP[i + 1][j] - mess[i + 1];
        yesClean = DP[i + 1][j - 1] - mess[i + 1];
        if (yesClean >= 0)
        {
          yesClean = DP[i + 1][j - 1] - mess[i + 1] + clean[i];
        }
        if (noClean < 0 && yesClean < 0)
        {
          DP[i][j] = -1;
        }
        else
        {
          DP[i][j] = max(yesClean, noClean);
        }
        if (i == previousVisit)
        {
          if (mess[previousVisit] <= DP[previousVisit][j])
          {
            // cout << mess[previousVisit] << " --> " << j << " -> " << DP[previousVisit][j] << endl;
            previousAnswer = j;
            break;
          }
        }
      }
    }

    // cout << "prev: " << previousAnswer << endl;
    if (previousAnswer == -1)
    {
      posible = false;
    }

    //  showDP(previousVisit, actualVisit + 1);
    totalDaysCleaned += previousAnswer;
    previousVisit = actualVisit + 1;
  }
  if (posible)
  {
    cout << totalDaysCleaned << endl;
  }
  else
  {
    cout << "-1" << endl;
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