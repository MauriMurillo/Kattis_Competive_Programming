#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Variables
int num_coins = 3;
vector<int> coins;
int change;
vector<int> DP(1000000,-1);
//Variables
int coin_change(int to_change){
    // cout<<"-"<<to_change<<endl;
    if (to_change < 0)
    {
        return 1000000000;
    }
    if (DP[to_change] != -1)
    {
        return DP[to_change];
    }
    for (int i = 0; i < coins.size(); i++)
    {
        if (to_change == coins[i])
        {
            return DP[to_change] = 1;
        }
    }
    int mini = 100000000;
    for (int i = 0; i < coins.size(); i++)
    {
        mini = min(coin_change(to_change - coins[i]), mini);
    }
    return DP[to_change] = mini + 1;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int aux;
    while (num_coins--)
    {
        cin>>aux;
        coins.push_back(aux);
    }
    cin>>change;
    cout<<coin_change(change)<<endl;
    return 0;
}