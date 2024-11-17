#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;

vector<vector<int>> adj_List;
vector<pair<int, int>> num_dep;
vector<pair<int, int>> data_ch;
vector<int> pages;

pair<pair<int, int>, int> check_children(int num)
{
  vector<int> ones(2, 1000000000);
  int min_two = 1000000000;
  pair<int, int> child;
  for (int i = 0; i < adj_List[num].size(); i++)
  {
    child = data_ch[adj_List[num][i]];
    if (child.second != 1000000000)
      min_two = min(min_two, child.second);
    if (child.first != 1000000000)
      ones.push_back(child.first);
  }
  sort(ones.begin(), ones.end());
  return make_pair(make_pair(ones[0], ones[1]), min_two);
}

void run_sub_tree(int chapter)
{
  // culminating chapter
  if (num_dep[chapter].second == 0)
  {
    data_ch[chapter] = make_pair(pages[chapter], 1000000000);
    return;
  }

  for (int i = 0; i < adj_List[chapter].size(); i++)
  {
    if (data_ch[adj_List[chapter][i]].first == -1 || data_ch[adj_List[chapter][i]].second == -1)
    {
      run_sub_tree(adj_List[chapter][i]);
    }
  }

  pair<pair<int, int>, int> var = check_children(chapter);

  // do one
  data_ch[chapter].first = var.first.first + pages[chapter];
  // do two
  data_ch[chapter].second = min(var.second + pages[chapter], var.first.first + var.first.second + pages[chapter]);
  return;
}

void solve()
{
  // get chapters and dependencies
  cin >> n >> m;
  pages.assign(n + 2, 0);
  // read page numbers
  for (int i = 0; i < n; i++)
  {
    cin >> pages[i];
  }
  // Setup necessary vectors
  adj_List.assign(n + 2, vector<int>());
  num_dep.assign(n + 2, make_pair(0, 0));
  data_ch.assign(n + 2, make_pair(-1, -1));
  // read dependencies
  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    a = a - 1;
    b = b - 1;
    adj_List[a].push_back(b);
    num_dep[b].first++;
    num_dep[a].second++;
  }

  pages[n] = 0;
  for (int i = 0; i < n; i++)
  {
    if (num_dep[i].first == 0)
    {
      adj_List[n].push_back(i);
    }
  }

  // for (int i = 0; i < n + 1; i++)
  // {
  //   cout << "i: " << i << endl;
  //   for (auto it : adj_List[i])
  //   {
  //     cout << it << endl;
  //   }
  // }

  num_dep[n] = make_pair(1, 1);
  run_sub_tree(n);
  cout << data_ch[n].second << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}
