#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Variables
int num_coins;
vector<int> coins;
int change;
vector<int> DP(2000100,-1);
vector<int> Greedy(2000100,-1);
//Variables
int coin_change(int to_change){
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
    int mini = 1000000000;
    for (int i = 0; i < coins.size(); i++)
    {
        mini = min(coin_change(to_change - coins[i]), mini);
    }
    return DP[to_change] = mini + 1;
}
int greedy_coin_change(int to_change){
    int coins_used = 0;
    if (Greedy[to_change] != -1)
    {
        return Greedy[to_change];
    }
    for (int i = 0; i < coins.size(); i++)
    {
        if (to_change == coins[i])
        {
            return Greedy[to_change] = 1;
        }
    }
    for (int i = coins.size()-1; i >= 0; i--)
    {
        if(to_change >= coins[i])
        {
            coins_used = greedy_coin_change(to_change - coins[i]) + 1;
            break;
        }
    }
    return Greedy[to_change] = coins_used;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int aux;
    cin>>num_coins;
    while (num_coins--)
    {
        cin>>aux;
        coins.push_back(aux);
    }
    int n;
    bool is_canonical = true;
    long long max = coins[coins.size()-1] + coins[coins.size()-2];

    sort(coins.begin(),coins.end());
    
    for (int i = max; i > 0; i--)
    {
        if (greedy_coin_change(i) != coin_change(i))
        {
            is_canonical = false;
        }
    }
    if (is_canonical)
    {
        cout<<"canonical"<<endl;
    }else{
        cout<<"non-canonical"<<endl;
    }
    return 0;
}