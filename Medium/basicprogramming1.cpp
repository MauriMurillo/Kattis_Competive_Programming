#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Variables
//Variables
void solve(){
    int N,t;
    long long sum = 0,sum_even=0;
    cin>>N>>t;
    vector<int>  mod(N+1,0);
    vector<int> vis(N+1,0);
    vector<long long > vec(N+1,0);
    string mod_s="";
    for (int i = 0; i < N; i++)
    {
        cin>>vec[i];
        sum += vec[i];
        if (vec[i] % 2 == 0)
        {
            sum_even += vec[i];
        }
    }
    if (t==1)
    {
        cout<<"7"<<endl;
        return;
    }
    if (t==2)
    {
        if (vec[0] > vec[1])
        {
            cout<<"Bigger"<<endl;
        }else if (vec[0] < vec[1])
        {
            cout<<"Smaller"<<endl;
        }else
        {
            cout<<"Equal"<<endl;
        }
        return;
    }
    if (t==3)
    {
        vector<int> vec_med;
        vec_med.push_back(vec[0]);
        vec_med.push_back(vec[1]);
        vec_med.push_back(vec[2]);
        sort(vec_med.begin(),vec_med.end());
        cout<<vec_med[1]<<endl;
        return;
    }
    if (t==4)
    {
        cout<<sum<<endl;
        return;
    }
    if (t==5)
    {
        cout<<sum_even<<endl;
        return;
    }
    if (t==6)
    {
        //a=97
        for (int i = 0; i < N; i++)
        {
            mod[i] = vec[i]%26;
            mod_s += char((mod[i]+97));
        }
        cout<<mod_s<<endl;
        return;
    }
    if (t==7)
    {
        int index_start = 0;
        while (true)
        {
            if (index_start == N-1)
            {
                cout<<"Done"<<endl;
                return;
            }
            if (index_start < 0 || index_start > N-1)
            {
                cout<<"Out"<<endl;
                return;
            }
            if (vis[index_start] == 1)
            {
                cout<<"Cyclic"<<endl;
                return;
            }
            vis[index_start] = 1;
            index_start = vec[index_start];
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}