#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;
vector<vector<char> > Grid(8, vector<char>(8, '.'));
pair<int, int> whiteKing, blackKing, rook;
void solve()
{
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      cin >> Grid[i][j];
      if (Grid[i][j] == 'K')
      {
        whiteKing = make_pair(i, j);
      }
      else if (Grid[i][j] == 'k')
      {
        blackKing = make_pair(i, j);
      }
      else if (Grid[i][j] == 'R')
      {
        rook = make_pair(i, j);
      }
    }
  }

  if ((blackKing.first == 0 or blackKing.first == 7) or (blackKing.second == 0 or blackKing.second == 7))
  {
    if (blackKing.first == 0)
    {
      if (whiteKing.first == 2 and whiteKing.second == blackKing.second and abs(rook.second - blackKing.second) > 1)
      {
        cout<<"Yes"<<endl;
        return;
      }
    }
    if (blackKing.first == 7)
    {
      if (whiteKing.first == 5 and whiteKing.second == blackKing.second and abs(rook.second - blackKing.second) > 1)
      {
        cout<<"Yes"<<endl;
        return;
      }
    }
    if (blackKing.second == 0)
    {
      if (whiteKing.second == 2 and whiteKing.first == blackKing.first and abs(rook.first - blackKing.first) > 1)
      {
        cout<<"Yes"<<endl;
        return;
      }
    }
    if (blackKing.second == 7)
    {
      if (whiteKing.second == 5 and whiteKing.first == blackKing.first and abs(rook.first - blackKing.first) > 1)
      {
        cout<<"Yes"<<endl;
        return;
      }
    }
  }
  
  if ((blackKing.first == 0 or blackKing.first == 7) and (blackKing.second == 0 or blackKing.second == 7))
  {
    if (blackKing.first == 0 and blackKing.second == 0)
    {
      if (whiteKing.first == 2 and (whiteKing.second == 0 or whiteKing.second == 1) and rook.second >= 2)
      {
        cout<<"Yes"<<endl;
        return;
      }
      if (whiteKing.second == 2 and (whiteKing.first == 0 or whiteKing.first == 1) and rook.first >= 2)
      {
        cout<<"Yes"<<endl;
        return;
      }
    }
    if (blackKing.first == 0 and blackKing.second == 7)
    {
      if (whiteKing.first == 2 and (whiteKing.second == 6 or whiteKing.second == 7) and rook.second <= 5)
      {
        cout<<"Yes"<<endl;
        return;
      }
      if (whiteKing.second == 5 and (whiteKing.first == 0 or whiteKing.first == 1) and rook.first >= 2)
      {
        cout<<"Yes"<<endl;
        return;
      }
    }
    if (blackKing.second == 0 and blackKing.first == 7)
    {
      if (whiteKing.first == 5 and (whiteKing.second == 0 or whiteKing.second == 1) and rook.second >= 2)
      {
        cout<<"Yes"<<endl;
        return;
      }
      if (whiteKing.second == 2 and (whiteKing.first == 6 or whiteKing.first == 7) and rook.first <= 5)
      {
        cout<<"Yes"<<endl;
        return;
      }
    }
    if (blackKing.second == 7 and blackKing.first == 7)
    {
      if (whiteKing.first == 5 and (whiteKing.second == 6 or whiteKing.second == 7) and rook.second <= 5)
      {
        cout<<"Yes"<<endl;
        return;
      }
      if (whiteKing.second == 5 and (whiteKing.first == 6 or whiteKing.first == 7) and rook.first <= 5)
      {
        cout<<"Yes"<<endl;
        return;
      }
    }
  }
  cout << "No" << endl;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}