#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <deque>
using namespace std;
// Variables
vector<int> dist;
int T,num;
int mini,maxi;
int len;
//Variables
void solve(){
    cin>>T;
    while (T--)
    {
        cin>>len>>num;
        mini = 0;
        maxi = 0;
        dist.assign(num+1,0);
        for (int i = 0; i < num; i++)
        {
            cin>>dist[i];
            mini = max(mini, min(dist[i], len-dist[i]));
            maxi = max(maxi, max(dist[i], len-dist[i]));
        }
        cout<<mini<<" "<<maxi<<endl;
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}