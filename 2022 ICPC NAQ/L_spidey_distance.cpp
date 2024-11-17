#include <iostream>
#include <cmath>
#define ll long long

using namespace std;
long long gcd(long long a, long long b)
{
  int matrix[10][10];

  if (b == 0)
    return a;
  return gcd(b, a % b);
}
void solve()
{
  long long SD, TD;
  cin >> TD >> SD;
  long long TotT, TotS, both;

  long long axisS = SD * 4 + 1;
  long long axisT = TD * 4 + 1;

  both = min(axisS, axisT);

  TotS = axisS;
  TotT = axisT;
  double counterSpidey = SD;
  long long counterTaxi = TD;
  counterSpidey -= 1.5;
  counterTaxi -= 2;

  while (counterSpidey >= 0.0)
  {
    TotS += 4;
    if (counterTaxi >= 0)
    {
      both += 4;
      TotT += 4;
    }
    long long integer = floor(counterSpidey);
    if (integer > 0)
    {
      TotS += integer * 8;
      if (counterTaxi >= 0)
      {
        TotT += counterTaxi * 8;
        both += min(integer, counterTaxi) * 8;
      }
    }
    counterSpidey -= 1.5;
    counterTaxi -= 2;
  }
  long long greatComDen = gcd(TotS, both);
  if (TotS / greatComDen == 1)
  {
    cout << both / greatComDen << endl;
  }
  else
  {
    cout << both / greatComDen << "/" << TotS / greatComDen << endl;
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