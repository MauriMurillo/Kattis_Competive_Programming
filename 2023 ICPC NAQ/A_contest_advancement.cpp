#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
      ios::sync_with_stdio(false);
      cin.tie(0);
      cout.tie(0);
      int teams, advance, max;
      cin >> teams >> advance >> max;
      priority_queue< pair<int,int> > advances;
      priority_queue< pair<int,int> > left_out;
      vector<int> school_num(teams, 0);
      int ranking = -1;
      for (int i = 0; i < teams; i++)
      {
            int team_id, school_id;
            cin >> team_id >> school_id;
            // cout<<"ranking: "<< ranking<<endl;
            if (advances.size() < advance)
            {
                  // cout<<"equipos de la u : "<<school_num[school_id]<<endl;
                  if (school_num[school_id] < max)
                  {
                        advances.push(make_pair(ranking, team_id));
                        school_num[school_id]++;
                        // cout<<"entra\n";
                        // cout<<ranking<<": "<<team_id<<": "<<school_id<<endl;
                  }
                  else
                  {
                        left_out.push(make_pair(ranking, team_id));
                        // cout<<"no\n";
                  }
            }else{
                  continue;
            }
            ranking--;
      }

      while (advances.size() < advance)
      {
            advances.push(left_out.top());
            left_out.pop();
      }
      int limit = advances.size();
      for (int i = 0; i < limit; i++)
      {
            cout<<advances.top().second<<endl;
            advances.pop();
      }
}