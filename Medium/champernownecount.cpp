#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define ll long long

using namespace std;
// Variables
// Variables
long long modpow(int base, int power, int mod){
  if (power == 1) return base % mod;
  long long pot = modpow(base,power/2,mod);
  if (power%2 == 0) return ((pot % mod) * (pot % mod))%mod;
  else return ((((pot % mod) * (pot % mod))%mod) * (base%mod))% mod;
}

void solve()
{
  long long n, divisor;
  long long ans = 0;
  unsigned long long chapnum = 0;
  long long count = 1;
  long long powmod;
  cin >> n >> divisor;
  for (int i = 0; i < n; i++)
  {
    // cout<<count<<" - "<<int(log10(count+1))<<endl;
    powmod = modpow(10, int(log10(count)+1),divisor);

    chapnum = ((((chapnum%divisor) * (powmod%divisor))%divisor))%divisor;
    chapnum += + (int(count)%divisor);
    chapnum %= divisor;
    if (chapnum % divisor == 0)
    {
      ans++;
    }
    count++;
  }
  cout << ans << endl;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}
