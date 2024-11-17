
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> problems;
int n, lph, loc, limit;

int sol, total;
int main()
{
      ios::sync_with_stdio(false);
      cin.tie(0);
      cout.tie(0);

      cin>>n>>lph;
      limit = lph*5;
      for (int p = 0; p < n; p++)
      {
            cin >> loc;
            problems.push_back(loc);
      }
      sort(problems.begin(), problems.end());


      for (int i = 0; i < problems.size(); i++)
      {
            if (total + problems[i] > limit )
            {
                  break;
            }else{
                  sol++;
                  total += problems[i];
            }
      }
      cout<<sol<<endl;
}